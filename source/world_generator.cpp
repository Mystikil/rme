#include "world_generator.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <nlohmann/json.hpp>
#include "tile.h"
#include "item.h"

using json = nlohmann::json;

WorldGenerator::WorldGenerator() {}

void WorldGenerator::Generate(Map* map, int width, int height) {
    map->clear();

    // Load biome config (optional)
    json biomes;
    std::ifstream file("data/biomes.json");
    if (file.is_open()) {
        file >> biomes;
    }

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            float noise = PerlinNoise(x * 0.1f, y * 0.1f);
            int tileID = GetGroundTileID(noise);

            // 🔧 Use correct constructor
            Tile* tile = new Tile(x, y, 7);
            tile->addItem(Item::Create(tileID));
            map->setTile(tile->getPosition(), tile);

            // OPTIONAL future logic: biome-based monster placement
            /*
            if (biomes.contains("forest") && noise > 0.5f && noise < 0.7f) {
                // spawn monsters later via spawns tab or spawn container
            }
            */
        }
    }
}

float WorldGenerator::PerlinNoise(float x, float y) {
    return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

int WorldGenerator::GetGroundTileID(float heightValue) {
    if (heightValue < 0.3f) return 4820; // Water
    if (heightValue < 0.6f) return 103;  // Grass
    return 351;                          // Mountain
}
