
#ifndef COMPANY_H

#define COMPANY_H


using namespace std;
#include <string>
#include <vector>
#include "Employee.h"
#include "Order.h"
#include "Customer.h"
class Employee;


class Company{

private:
    string name;
    int phone;
    string email;
    string address;
    vector<Employee*> employees;
    vector<Order*> OrderList;
    vector<Customer*> clients;

public:
    Company(string name, int phone, string email, string address);
    ~Company();
    string getName() const;
    int getPhone() const;
    string getEmail() const;
    string getAddress() const;

    void setName(const string& name);
    void setPhone(const int& phone);
    void setEmail(const string& email);
    void setAddress(const string& address);

    void addEmployee(string name, string surname, double salary, position job);
    void removeEmployee(string name, string surname);
    int getEmployeesize() const;

    void addOrder(string event, Date dateRequest, Customer* customer = nullptr, Company* from = nullptr);
    void removeOrder(string event);
    int getOrdersize() const;

    void addCustomer(string name, string surname, string email, string address, int phone);
    void removeCustomer(string name, string surname);
    int getCustomersize() const;
    void print() const;
};


#endif //COMPANY_H
