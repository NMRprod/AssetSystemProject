#include <iostream>
#include "CommandHandler.h"

void CommandHandler::printMenu() {
    std::cout << "\n\nWelcome to Asset Manager Application!\n";
    std::cout << "===============================================================" << std::endl;
    std::cout << "1: add asset" << std::endl
        << "2: print lists of assets" << std::endl
        << "3: move asset" << std::endl
        << "4: delete asset" << std::endl
        << "5: turn off the application" << std::endl
        << "===============================================================" << std::endl
        << "Please enter command" << std::endl << std::endl << std::endl;
}

void CommandHandler::run() {
    int command = 0;
    while (command != 5) {
        printMenu();
        std::cin >> command;
        switch (command) {
        case 1:
            addAsset();
            break;
        case 2:
            manager.listAssets();
            break;
        case 3:
            moveAsset();
            break;
        case 4:
            deleteAsset();
            break;
        }
    }
} 

std::string CommandHandler::getValidatedString(const std::string& promt, const std::function<std::string(const std::string&)> validator) {
    while (true) {
        std::cout << promt;

        std::string input;
        std::getline(std::cin, input);

        std::string error = validator(input);
        if (error.empty()) {
            return input;
        }
        std::cout << error << std::endl;
    }
}

double CommandHandler::getValidatedDouble(const std::string& promt, const std::function<std::string(double)> validator) {
    while (true) {
        std::cout << promt;

        std::string input;
        std::getline(std::cin, input);

        double value;

        try {
            value = std::stod(input);
        }
        catch (const std::exception&) {
            std::cout << "Invalid number format!" << std::endl;
            continue;
        }
        

        std::string error = validator(value);
        if (error.empty()) {
            return value;
        }
        std::cout << error << std::endl;
    }
    
}

int CommandHandler::getValidatedInt(const std::string& promt, const std::function<std::string(int)>& validator) {
    while (true) {
        std::cout << promt;

        std::string input;
        std::getline(std::cin, input);

        int value;

        try {
            value = std::stoi(input);
        }
        catch (const std::exception&) {
            std::cout << "Invalid number format!" << std::endl;
            continue;
        }

        std::string error = validator(value);
        if (error.empty()) {
            return value;
        }
        std::cout << error << std::endl;
    }
}



void CommandHandler::addAsset() {
    std::string _name;
    std::string _category;
    std::string _location;
    double _value;
    int _yearsOfUsing;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    _name = getValidatedString("Enter name: ", [this](const std::string& s) {return validator.validateName(s); });
    _category = getValidatedString("Enter category of asset: ", [this](const std::string& s) {return validator.validateCategory(s); });
    _location = getValidatedString("Enter location: ", [this](const std::string& s) {return validator.validateLocation(s); });
    _value = getValidatedDouble("Enter value: ", [this](double v){ return validator.validateValue(v); });
    _yearsOfUsing = getValidatedInt("Enter years of using: ", [this](int y) {return validator.validateYearsOfUsing(y); });

    manager.addAsset(_name, _category, _location, _value, _yearsOfUsing);
}

void CommandHandler::moveAsset() {
    std::string _newLocation;
    int _id;

    std::cout << "Enter asset's ID: ";
    std::cin >> _id;
    std::cout << "\nEnter new location for asset: ";
    std::cin >> _newLocation;
    Asset* _asset = manager.findAsset(_id);
    _asset->setLocation(_newLocation);
}

void CommandHandler::deleteAsset() {
    int _id;
    std::string answer;
    std::string assetName;

    std::cout << "Enter asset's ID: ";
    std::cin >> _id;
    Asset* _asset = manager.findAsset(_id);
    if (_asset == nullptr) {
        std::cout << "\nAsset not found ";
        return;
    }
    assetName = _asset->getName();
    std::cout << "\nAre you sure that you want delete asset " << assetName << "?\n(y/n)\n";
    std::cin >> answer;

    if (answer == "y" || answer == "Y") {
        manager.deleteAsset(_id);
        std::cout << "\nAsset " << assetName << " have been deleted!\n";
    }
    else {
        std::cout << "Delete canceled\n";
    }
}