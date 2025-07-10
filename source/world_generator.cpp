#include "world_generator.h"
#include "tile.h"
#include "ground_brush.h"
#include "map.h"
#include "basemap.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <random>

using json = nlohmann::json;

void WorldGenerator::Generate(Map* map, int width, int height) {
	if (!map) return;

	map->clear();

	std::ifstream file("data/biomes.json");
	if (!file) return;

	json biomes;
	file >> biomes;

	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<> biome_dist(0, biomes.size() - 1);

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			Position pos(x, y, 7);
			TileLocation* tileLoc = map->createTileL(pos);
			Tile* tile = map->allocator(tileLoc);

			const auto& biome = biomes[biome_dist(rng)];
			std::string ground_str = biome["ground"];
			GroundBrush* brush = g_brushes.getGroundBrush(ground_str);
			if (brush) {
				brush->draw(map, tile, nullptr);
			}
			map->setTile(pos, tile);
		}
	}
}
