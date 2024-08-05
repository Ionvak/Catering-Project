
#include <iostream>
#include <string>
#include <vector>
#include "Company.h"



    Company::Company(string name, int phone, string email, string address)
        : name(name), phone(phone), email(email), address(address) {}



    Company::~Company(){

        for (Employee* employee : employees) {
            delete employee;
        }
        for (Order* order : OrderList) {
            delete order;
        }
        for (Customer* customer : clients) {
            delete customer;
        }
    }



    string Company::getName() const{

        return name;
    }



    int Company::getPhone() const{

        return phone;
    }



    string Company::getEmail() const{

        return email;
    }



    string Company::getAddress() const{

        return address;
    }



    void Company::setName(const string& name){

        this->name = name;
    }



    void Company::setPhone(const int& phone){

        this->phone = phone;
    }



    void Company::setEmail(const string& email){

        this->email = email;
    }



    void Company::setAddress(const string& address){

        this->address = address;
    }



    void Company::addEmployee(string name, string surname, double salary, position job){

        employees.push_back(new Employee(name, surname, salary, job));
    }



    void Company::removeEmployee(string name, string surname){

        for (auto it = employees.begin(); it != employees.end(); it++){
            if ((*it)->getName() == name && (*it)->getSurname() == surname){
                delete *it;
                employees.erase(it);
                break;
            }
        }
    }



    int Company::getEmployeesize() const{

        return employees.size();
    }



    void Company::addOrder(string event, Date dateRequest, Customer* customer, Company* from){

        OrderList.push_back(new Order(event,dateRequest,customer,from));
    }



    void Company::removeOrder(string event){

        for (auto it = OrderList.begin(); it != OrderList.end(); it++) {
            if ((*it)->get_event() == event) {
                delete *it;
                OrderList.erase(it);
                break;
            }
        }
    }



    int Company::getOrdersize() const{

        return OrderList.size();
    }



    void Company::addCustomer(string name, string surname, string email, string address, int phone){

        clients.push_back(new Customer(name, surname, email, address, phone));
    }



    void Company::removeCustomer(string name, string surname){

        for (auto it = clients.begin(); it != clients.end(); it++) {
            if ((*it)->getName() == name && (*it)->getSurname() == surname) {
                delete *it;
                clients.erase(it);
                break;
            }
        }
    }

    int Company::getCustomersize() const{

        return clients.size();
    }



    void Company::print() const{

        cout << "Company: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;

        cout << "Employees: " << endl;
        for (auto employee : employees) {
            employee->print();
        }

        cout << "Orders: " << endl;
        for (auto order : OrderList) {
            order->print();
        }

        cout << "Customers: " << endl;
        for (auto customer : clients) {
            customer->print();
        }
    }



