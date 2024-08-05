
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Customer.h"


    Customer::Customer(string name, string surname, string email, string address, int phone)
    : name(name), surname(surname), email(email), address(address), phone(phone) {}



    string Customer::getName() const{

        return name;
    }



    string Customer::getSurname() const{

        return surname;
    }



    string Customer::getEmail() const{

        return email;
    }



    int Customer::getPhone() const{

        return phone;
    }



    string Customer::getAddress() const{

        return address;
    }



    void Customer::setName(const string& name){

        this->name = name;
    }



    void Customer::setSurname(const string& surname){

        this->surname = surname;
    }



    void Customer::setEmail(const string& email){

        this->email = email;
    }



    void Customer::setPhone(const int& phone){

        this->phone = phone;
    }



    void Customer::setAddress(const string& address){

        this->address = address;
    }



    void Customer::addOrder(Order* order){

        order->set_customer(this);
        orders.push_back(order);
    }



    void Customer::removeOrder(Order* order){

        auto it = find(orders.begin(), orders.end(), order);
        if (it != orders.end()) {
            orders.erase(it);
        }
    }



    int Customer::getOrderCount() const{

    return orders.size();
}



void Customer::print() const{

    cout << "Customer Information:\n";
    cout << "Name: " << name << " " << surname << endl;
    cout << "Email: " << email << endl;
    cout << "Address: " << address << endl;
    cout << "Phone: " << phone << endl;
    cout << "Number of Orders: " << orders.size() << endl;

    if (!orders.empty()) {
        cout << "Orders:\n";
        for (auto order : orders){
            cout << " - " << order->get_event() << endl;
        }
    }
}
