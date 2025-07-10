#pragma once

#include "map.h"
#include <string>
#include <nlohmann/json.hpp>

class WorldGenerator {
public:
    WorldGenerator();
    void Generate(Map* map, int width, int height);

private:
    nlohmann::json biomeData;

    void loadBiomes(const std::string& path);
    std::string pickBiome(float heightVal);
    float PerlinNoise(float x, float y);
};
