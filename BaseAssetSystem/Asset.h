#pragma once
#include <iostream>
#include <string>

class Asset {
private:
    int id;
    std::string name;
    std::string category;
    std::string location;
    double value;
    int yearsOfUsing;

public:
    Asset(int id, const std::string& name, const std::string& category, const std::string& location, double value, int yearsOfUsing)
        : id(id), name(name), category(category), location(location), value(value), yearsOfUsing(yearsOfUsing) {
        /*if (id > nextId) {
            ++nextId;
        }*/
    }

    int getId() const;
    std::string getName() const;
    std::string getCategory() const;
    std::string getLocation() const;
    double getValue() const;
    int getYearsOfUsing() const;
};