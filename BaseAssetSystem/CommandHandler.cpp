#include <iostream>
#include "CommandHandler.h"

void CommandHandler::printMenu() {
    std::cout << "Welcome to Asset Manager Application!" << std::endl << std::endl;
    std::cout << "===============================================================" << std::endl;
    std::cout << "1: add asset" << std::endl
        << "2: print lists of assets" << std::endl
        << "3: find asset" << std::endl
        << "4: delete asset" << std::endl
        << "5: set location for asset" << std::endl //Перепроверить и мб поменять
        << "6: turn off the application" << std::endl
        << "===============================================================" << std::endl
        << "Please enter command" << std::endl;
}

void CommandHandler::run() {
    int command = 0;
    while (command != 6) {
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
            //manager.findAsset(int id);
            break;
        case 4:
            deleteAsset();
            break;
        case 5:
            //set location;
            break;
        }
    }
} 
