#ifndef MONGODBINTEGRATION_H
#define MONGODBINTEGRATION_H

#include <vector>
#include "Item.h"
#include "Customer.h"

class MongoDBIntegration {
private:
    int customerID;
    std::string customerName;
    std::vector<Item> itemsPurchased;

public:
    void storeCustomerPurchaseData(Customer customer, const std::vector<Item>& items);
};

#endif

