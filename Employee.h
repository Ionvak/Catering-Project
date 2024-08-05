
#ifndef EMPLOYEE_H

#define EMPLOYEE_H


#include <string>
#include <vector>
#include "Order.h"
enum position { Manager, Chef, Server, SalesRep, Delivery, EventStaff, Designer, CustomerService };

#include "Company.h"


using namespace std;




class Employee {
private:
    string name;
    string surname;
    double salary;
    position Position;
    Order* task;
    Company* employment;

    Order* getTask() const;
    Company* getEmployment() const;

public:
    Employee(string name, string surname, double salary, position position, Order* assigned = nullptr, Company* employer = nullptr);

    string getName() const;
    string getSurname() const;
    double getSalary() const;
    position getPosition() const;
    string getPositionString() const;

    void setName(const string& name);
    void setSurname(const string& surname);
    void setSalary(const double& salary);
    void setPosition(const position& job);
    void setTask(Order* task);
    void setEmployment(Company* employment);

    void print() const;
};

#endif //EMPLOYEE_H
