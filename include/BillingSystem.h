#ifndef BILLINGSYSTEM_H
#define BILLINGSYSTEM_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Item.h"

class BillingSystem {
public:
    void generateBill(std::vector<Item>& items);

};

#endif

