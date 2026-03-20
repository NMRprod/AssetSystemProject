#include <iostream>
#include "Asset.h"
#include "AssetManager.h"
#include "CommandHandler.h"
#include "AssetRepository.h"

int main() {
    AssetManager manager;
    AssetRepository repository;

    CommandHandler app(manager);

    repository.load(manager);

    app.run();
    //repository.save(manager.getAssets());
    
}