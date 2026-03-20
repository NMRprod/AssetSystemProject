#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "AssetManager.h"

class AssetRepository
{
public:
	AssetRepository() = default;

	void save(const std::vector<Asset>& assets);
	void load(AssetManager& m);
};

