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

void CommandHandler::addAsset() {
    std::string _name;
    std::string _category;
    std::string _location;
    double _value;
    int _yearsOfUsing;

    std::cout << "Enter name: ";
    std::cin >> _name;
    std::cout << "\nEnter category of asset: ";
    std::cin >> _category;
    std::cout << "\nEnter location: ";
    std::cin >> _location;
    std::cout << "\nEnter value: ";
    std::cin >> _value;
    std::cout << "\nEnter years of using: ";
    std::cin >> _yearsOfUsing;

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