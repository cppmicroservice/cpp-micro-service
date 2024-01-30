#include "Item.h"
#include <iostream>

Item::Item(std::string itemType, std::string brandName, std::string eatType, std::string perishableOrFragile,
           float mrp, float weight, std::string countryOfManufacture, float importDuty, int numberOfItems)
           : itemType(itemType), brandName(brandName), eatType(eatType), perishableOrFragile(perishableOrFragile),
             mrp(mrp), weight(weight), countryOfManufacture(countryOfManufacture), importDuty(importDuty),
             numberOfItems(numberOfItems) {

	     }

#if 1 
float Item::calculatePrice() const {

	float totalPrice = mrp * numberOfItems;

        if (countryOfManufacture != "India") {
            totalPrice += (importDuty / 100) * totalPrice;
        }

        return totalPrice;
}
#endif
