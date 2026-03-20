#include "AssetManager.h"

void AssetManager::addAsset(const std::string& name, const std::string& category, const std::string& location, double value, int yearsOfUsing) {
    assets.emplace_back(nextId++, name, category, location, value, yearsOfUsing);
}

void AssetManager::listAssets() {
    std::cout << "\nList of assets:" << std::endl;
    for (const auto& asset : assets) {
        std::cout
            << "ID: " << asset.getId()
            << " | Name: " << asset.getName()
            << " | Category: " << asset.getCategory()
            << " | Location: " << asset.getLocation()
            << " | Value: " << asset.getValue()
            << " | Years of using: " << asset.getYearsOfUsing()
            << std::endl;
    }
    std::cout << std::endl << std::endl;
}

Asset* AssetManager::findAsset(int id) {
    for (auto& a : assets) {
        if (a.getId() == id) {
            return &a;
        }
    }
    return nullptr;
}

void AssetManager::deleteAsset(int id) {
    for (auto it = assets.begin(); it != assets.end(); ++it) {
        if (it->getId() == id) {
            assets.erase(it);
            return;
        }
    }
}

const std::vector<Asset>& AssetManager::getAssets() const {
    return assets;
}