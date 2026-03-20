#pragma once
#include <iostream>
#include "AssetManager.h"

class CommandHandler {
private:
    AssetManager& manager;

public:
    CommandHandler(AssetManager& m) : manager(m) {}

    void run();

private:
    void printMenu();
    void addAsset();
    void moveAsset();
    void deleteAsset();
};