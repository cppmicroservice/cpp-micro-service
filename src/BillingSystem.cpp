#include "BillingSystem.h"
#include <map>

void BillingSystem::generateBill(std::vector<Item>& items) {

	// Sorting logic based on the specified criteria
        // 1. Order: non-fragile, non-eatable
        // 2. Order: non-perishable, eatable
        // 3. Order: fragile, non-eatable
        // 4. Order: perishable, eatable
        // 5. Within each category, sort based on weight and then MRP.
    	
    	std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {

        // Mapping categories to integers for comparison
        std::map<std::string, int> categoryOrder = {{"NFNE", 1}, {"NPE", 2}, {"FNE", 3}, {"PE", 4}};

        // Creating a key for comparison
        std::string keyA = a.getPerishableOrFragile() + a.getEatType();
        std::string keyB = b.getPerishableOrFragile() + b.getEatType();

        if (categoryOrder[keyA] != categoryOrder[keyB]) {
            return categoryOrder[keyA] < categoryOrder[keyB];
        }

        // Within the same category, sort based on weight
        if (a.getWeight() != b.getWeight()) {
            return a.getWeight() < b.getWeight();
        }

        // If weight is the same, sort based on MRP
        return a.getMRP() < b.getMRP();
    });

    int itemNumber = 1;
    float totalAmount = 0.0;

    // Output the bill
    for (const Item& item : items) {
        std::cout << itemNumber << ". "
                  << item.getItemType() << " "
                  << item.getBrandName() << " "
                  << item.getMRP() << " "
                  << item.getNumberOfItems() << " "
                  << item.calculatePrice() << std::endl;

	totalAmount += item.calculatePrice();
        itemNumber++;
    }

    // Output total bill amount
    std::cout << "Total Amount: " << totalAmount << std::endl;
}

