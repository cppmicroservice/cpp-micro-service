#include <iostream>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>
#include "Customer.h"
#include "Item.h"
#include "MongoDBIntegration.h"
#include "BillingSystem.h"

using namespace std;
using json = nlohmann::json;

int main() {
    // Reading JSON data from file
    ifstream jsonFile("input.json");
    if (!jsonFile) {
        cout << "Error: input.json file not found." << endl;
        return -1; // Exit with error code
    }

    json jsonData;
    jsonFile >> jsonData;

    // Extracting customer name and items
    string customerName = jsonData["customer_name"];
    json itemsData = jsonData["items"];

    // Creating a customer object
    Customer customer(customerName);

    // Processing each item
    vector<Item> items;
    for (const auto& itemData : itemsData) {
        string itemType = itemData["item_type"];
        string brandName = itemData["brand_name"];
        string eatType = itemData["eat_type"];
        string perishableOrFragile = itemData["perishable_or_fragile"];
        float mrp = itemData["mrp"];
        float weight = itemData["weight"];
        string countryOfManufacture = itemData["country_of_manufacture"];
        float importDuty = itemData["import_duty"];
        int numberOfItems = itemData["num_items"];

        // Creating item object and add to vector
        Item item(itemType, brandName, eatType, perishableOrFragile,
                  mrp, weight, countryOfManufacture, importDuty, numberOfItems);
        items.push_back(item);
    }

    // TODO: Store customer purchase data
    MongoDBIntegration mongoDB;
    mongoDB.storeCustomerPurchaseData(customer, items);

    // Generate bill
    BillingSystem billingSystem;
    billingSystem.generateBill(items);

    return 0;
}

