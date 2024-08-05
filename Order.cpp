
#include "Order.h"
#include <iostream>
#include <string>



    Order::Order(string type, Date planned, Customer* client , Company* office)
        : event(type), customer(client), from(office), DateRequest(planned) {

        time_t currentTime = time(nullptr);
        tm* localTime = localtime(&currentTime);
        DateMade = Date(*localTime);
        receipt.bill = this->calculate_bill();
        receipt.IsCovered = false;
        receipt.DueDate = (Date(*localTime) += 30);
    }



    double Order::get_bill() const{

        return receipt.bill;
    }



    bool Order::get_covered() const{

        return receipt.IsCovered;
    }



    Date Order::get_DueDate() const{

        return receipt.DueDate;
    }



    Date Order::get_DateMade() const{

        return DateMade;
    }



    Date Order::get_DateRequest() const{

        return DateRequest;
    }



    std::string Order::get_event() const{

        return event;
    }



    Customer* Order::get_customer() const{

        return customer;
    }



    Company* Order::get_from() const{

        return from;
    }



    void Order::set_bill(const double& payment){

        receipt.bill = payment;
    }



    void Order::set_IsCovered(const bool& covered){

        receipt.IsCovered = covered;
    }



    void Order::set_customer(Customer* new_customer){

        customer = new_customer;
    }



    void Order::set_from(Company* new_from){

        from = new_from;
    }



    void Order::set_DateRequest(const Date& planned){

        DateRequest = planned;
    }



    void Order::setItemPrice(const string& name, const double& price){

        for (auto& menuItem : menu) {
            if (menuItem.name == name) {
                menuItem.price = price;
                break;
            }
        }
    }



    void Order::set_event(const string& new_event){

        event = new_event;
    }



    int Order::getMenuSize() const{

        return menu.size();
    }



    double Order::calculate_bill() const{

        double total = 0.0;
        for (auto menuItem : menu) {
            total += menuItem.price;
        }
        return total;
    }



    int Order::find_index(string name) const{

        for (size_t i = 0; i < menu.size(); ++i){
            if (menu[i].name == name) {
                return i;
            }
        }
        return -1;
    }



    void Order::add_item(item new_item){

        menu.push_back(new_item);
        receipt.bill = this->calculate_bill();
    }



    void Order::remove_item(string name){

        int index = find_index(name);
        if (index != -1) {
            menu.erase(menu.begin() + index);
        }
        receipt.bill = this->calculate_bill();
    }



    void Order::print() const{

        std::cout << "------------------------" << std::endl;
        std::cout << "        ORDER RECEIPT        " << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "Event: " << event << std::endl;
        std::cout << "Date Made: ";
        DateMade.print();
        std::cout << "Date Request: ";
        DateRequest.print();
        std::cout << "------------------------" << std::endl;
        std::cout << "Menu Items:" << std::endl;
        for (auto menuItem : menu) std::cout << "- " << menuItem.name << " $" << menuItem.price << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "Subtotal: $" << receipt.bill << std::endl;
        std::cout << "Tax: $" << receipt.bill * 0.1 << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "Total: $" << receipt.bill * 1.1 << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "Customer: ";
        if(customer) cout << customer->getName() << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "Thank you for your order!" << std::endl;
        std::cout << "------------------------" << std::endl;
}
