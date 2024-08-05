
#ifndef ORDER_H

#define ORDER_H

#include <string>
#include "Customer.h"
#include "Date.h"

class Company;
class Customer;
using namespace std;


struct Invoice{
    double bill;
    Date DueDate;
    bool IsCovered;
};



struct item {
    string name;
    double price;
};



class Order {

private:
    string event;
    vector<item> menu;
    Invoice receipt;
    Customer* customer;
    Company* from;
    Date DateMade;
    Date DateRequest;

    Customer* get_customer() const;
    Company* get_from() const;

public:
    Order(string type, Date planned, Customer* client = nullptr, Company* office = nullptr);

    double get_bill() const;
    bool get_covered() const;
    Date get_DueDate() const;
    Date get_DateMade() const;
    Date get_DateRequest() const;
    string get_event() const;


    void set_bill(const double& payment);
    void set_IsCovered(const bool& covered);
    void set_customer(Customer* new_customer);
    void set_from(Company* new_from);
    void set_DateRequest(const Date& planned);
    void setItemPrice(const string &name, const double& price);
    void set_event(const string& new_event);

    void add_item(item new_item);
    void remove_item(string name);
    int getMenuSize() const;

    double calculate_bill() const;
    int find_index(string name) const;
    void print() const;

};

#endif //ORDER_H
