#pragma once

#include "map.h"

class WorldGenerator {
public:
	WorldGenerator();
	void Generate(Map* map, int width, int height);

private:
	float PerlinNoise(float x, float y);
	int GetGroundTileID(float heightValue);
};