#pragma once
#include <iostream>
#include <functional>
#include "AssetManager.h"
#include "AssetValidator.h"

class CommandHandler {
private:
    AssetManager& manager;
    AssetValidator& validator;

public:
    CommandHandler(AssetManager& m, AssetValidator& v) : manager(m), validator(v) {}

    void run();

private:
    void printMenu();
    void addAsset();
    void moveAsset();
    void deleteAsset();
    std::string getValidatedString(const std::string& promt, const std::function<std::string(const std::string&)> validator);
    double getValidatedDouble(const std::string& promt, const std::function<std::string(double)> validator);
    int getValidatedInt(const std::string& promt, const std::function<std::string(int)>& validator);
};