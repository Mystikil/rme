#include "world_generator.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>

using json = nlohmann::json;

WorldGenerator::WorldGenerator() {
	loadBiomes("data/biomes.json");
	srand(static_cast<unsigned>(time(nullptr)));
}

void WorldGenerator::loadBiomes(const std::string& path) {
	std::ifstream file(path);
	if (!file.is_open()) {
		std::cerr << "[Error] Could not open biome config: " << path << std::endl;
		return;
	}
	file >> biomeData;
}

void WorldGenerator::Generate(Map* map, int width, int height) {
	if (biomeData.empty()) {
		std::cerr << "[Error] No biome data loaded.\n";
		return;
	}

	map->clear(); // Clear existing map

	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			float noise = PerlinNoise(x * 0.05f, y * 0.05f);
			std::string biome = pickBiome(noise);
			const auto& biomeCfg = biomeData[biome];

			Tile* tile = new Tile(Position(x, y, 7)); // Default ground level

			// Place ground tile
			int groundID = biomeCfg["ground"];
			tile->addItem(Item::Create(groundID));

			// Trees (10% chance)
			if (biomeCfg.contains("trees") && rand() % 100 < 10) {
				int treeID = biomeCfg["trees"][rand() % biomeCfg["trees"].size()];
				tile->addItem(Item::Create(treeID));
			}

			// Decorations (15% chance)
			if (biomeCfg.contains("decorations") && rand() % 100 < 15) {
				int decoID = biomeCfg["decorations"][rand() % biomeCfg["decorations"].size()];
				tile->addItem(Item::Create(decoID));
			}

			// Monsters (5% chance - stored in metadata)
			if (biomeCfg.contains("monsters") && rand() % 100 < 5) {
				std::string monster = biomeCfg["monsters"][rand() % biomeCfg["monsters"].size()];
				tile->addMeta("monster", monster);
			}

			map->setTile(tile->getPosition(), tile);
		}
	}
}

float WorldGenerator::PerlinNoise(float x, float y) {
	// Placeholder: replace with real Perlin noise later
	return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

std::string WorldGenerator::pickBiome(float noiseVal) {
	if (noiseVal < 0.3f) return "water";
	if (noiseVal < 0.5f) return "grassland";
	if (noiseVal < 0.75f) return "forest";
	return "mountain";
}
