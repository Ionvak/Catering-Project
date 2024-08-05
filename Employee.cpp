
#include <string>
#include <iostream>
#include "Employee.h"
#include "Company.h"


Employee::Employee(string name, string surname, double salary, position job,  Order* assigned, Company* employer)
    : name(name), surname(surname), salary(salary), Position(job), task(assigned), employment(employer) {}



void Employee::setName(const string& name){

    this->name = name;
}



void Employee::setSurname(const string& surname){

    this->surname = surname;
}



void Employee::setSalary(const double& salary){

    this->salary = salary;
}



void Employee::setPosition(const position& job){

    this->Position = job;
}



void Employee::setTask(Order* task){

    this->task = task;
}



void Employee::setEmployment(Company* employment){

    this->employment = employment;
}



string Employee::getName() const{

    return name;
}



string Employee::getSurname() const{

    return surname;
}



double Employee::getSalary() const{

    return salary;
}



position Employee::getPosition() const{

    return Position;
}



Order* Employee::getTask() const{

    return task;
}



Company* Employee::getEmployment() const{

    return employment;
}



string Employee::getPositionString() const{

    switch (Position) {
        case Manager:
            return "Manager";
        case Chef:
            return "Chef";
        case Server:
            return "Server";
        case SalesRep:
            return "Sales Representative";
        case Delivery:
            return "Delivery Personnel";
        case EventStaff:
            return "Event Staff";
        case Designer:
            return "Designer";
        case CustomerService:
            return "Customer Service";
        default:
            return "Unknown";
    }
}



void Employee::print() const{

    cout << "Employee Information:" << endl;
    cout << "Name: " << name << " " << surname << endl;
    cout << "Salary: $" << salary << endl;
    cout << "Position: " << this->getPositionString() << endl;

    cout << "Task: ";
    if(task != nullptr) {
        cout << task->get_event() << endl;
    }
    else{
        cout << "None" << endl;
    }

    cout << "Employment: ";
    if(employment != nullptr) {
        cout << employment->getName() << endl;
    }
    else{
        cout << "None" << endl;
    }

}




