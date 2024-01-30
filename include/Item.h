#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    std::string itemType;
    std::string brandName;
    std::string eatType;
    std::string perishableOrFragile;
    float mrp;
    float weight;
    std::string countryOfManufacture;
    float importDuty;
    int numberOfItems;

public:
    Item(std::string itemType, std::string brandName, std::string eatType, std::string perishableOrFragile,
         float mrp, float weight, std::string countryOfManufacture, float importDuty, int numberOfItems);
    float calculatePrice() const;

    std::string getItemType() const {
        return itemType;
    }

    std::string getBrandName() const {
        return brandName;
    }

    std::string getEatType() const {
        return eatType;
    }

    std::string getPerishableOrFragile() const {
        return perishableOrFragile;
    }

    float getMRP() const {
        return mrp;
    }

    float getWeight() const {
        return weight;
    }

    std::string getCountryOfManufacture() const {
        return countryOfManufacture;
    }

    float getImportDuty() const {
        return importDuty;
    }

    int getNumberOfItems() const {
        return numberOfItems;
    }
};

#endif

