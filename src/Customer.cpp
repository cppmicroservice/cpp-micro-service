#include "Customer.h"
#include <iostream>

Customer::Customer(std::string name) : name(name) {
    // Generate a random customer ID 
 //   customerId = generateRandomCustomerId();
}

std::string Customer::getName() const {
    return name;
}

int Customer::getCustomerId() const {
    return customerId;
}

