#include "world_generator.h"
#include <cmath>
#include <cstdlib>

WorldGenerator::WorldGenerator() {}

void WorldGenerator::Generate(Map* map, int width, int height) {
	map->clear(); // Clear existing map
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			float noise = PerlinNoise(x * 0.1f, y * 0.1f);
			int tileID = GetGroundTileID(noise);
			
			Tile* tile = new Tile(x, y, 7); // ✅ Fixed: no Position(), just raw coords
			tile->addItem(Item::Create(tileID));
			map->setTile(tile->getPosition(), tile);
		}
	}
}

float WorldGenerator::PerlinNoise(float x, float y) {
	// Placeholder for Perlin noise (replace with a real implementation later)
	return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
}

int WorldGenerator::GetGroundTileID(float heightValue) {
	if (heightValue < 0.3f) return 4820; // Water tile
	if (heightValue < 0.6f) return 103;  // Grass tile
	return 351;                         // Mountain tile
}
