#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    int customerId;

public:
    Customer(std::string name);
    std::string getName() const;
    int getCustomerId() const;
};

#endif

