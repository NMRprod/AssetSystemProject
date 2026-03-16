#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Asset.h"

class AssetManager {
private:
    std::vector<Asset> assets;
    int nextId = 1;

public:
    AssetManager() = default;

    void addAsset(const std::string& name, const std::string& category, const std::string& location, double value, int yearsOfUsing);
    void listAssets();
    Asset* findAsset(int id);
    void deleteAsset(int id);
};