#include <iostream>
#include "Asset.h"
#include "AssetManager.h"
#include "CommandHandler.h"
#include "AssetRepository.h"
#include "AssetValidator.h"

int main() {
    AssetManager manager;
    AssetRepository repository;
    AssetValidator validator;

    CommandHandler app(manager, validator);

    repository.load(manager);

    app.run();
    repository.save(manager.getAssets());
    
}