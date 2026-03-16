#pragma once
#include <iostream>
#include "AssetManager.h"

class CommandHandler {
private:
    AssetManager manager;

public:
    CommandHandler() = default;

    void run();

private:
    void printMenu();
    void addAsset();
    void moveAsset();
    void deleteAsset();
};