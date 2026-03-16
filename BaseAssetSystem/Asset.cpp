#include "Asset.h"

int Asset::getId() const
{
    return id;
}

std::string Asset::getName() const {
    return name;
}

std::string Asset::getCategory() const {
    return category;
}

std::string Asset::getLocation() const {
    return location;
}

double Asset::getValue() const {
    return value;
}

int Asset::getYearsOfUsing() const {
    return yearsOfUsing;
}
