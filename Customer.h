
#ifndef CUSTOMER_H

#define CUSTOMER_H


using namespace std;
#include <string>
#include <vector>
#include "Order.h"
class Order;


class Customer {
private:
    string name;
    string surname;
    string email;
    string address;
    unsigned long int phone;
    vector<Order*> orders;

public:
    Customer(string name, string surname, string email, string address, int phone);

    string getName() const;
    string getSurname() const;
    string getEmail() const;
    string getAddress() const;
    int getPhone() const;

    void setName(const string& name);
    void setSurname(const string&surname);
    void setEmail(const string&email);
    void setPhone(const int& phone);
    void setAddress(const string&address);

    void addOrder(Order* order);
    void removeOrder(Order* order);
    int getOrderCount() const;

    void print() const;

};

#endif //CUSTOMER_H
