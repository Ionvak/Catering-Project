
#include <iostream>
#include <vector>
#include <string>
#include "Date.h"
#include "Company.h"
#include "Customer.h"
#include "Order.h"
#include "Employee.h"

using namespace std;


template <typename T>
void TEST(const T& a,const T& b){

    if(a != b){
        cerr << "Expected value not achieved" << endl;
        cout << "Expected: " << b << '\n';
        cout << "Recieved: " << a << "\n\n";
    }
}


int main()
{
    //Date class method and operator tests:
    time_t curr = time(nullptr);
    tm CurrentTime = *localtime(&curr);
    int dCurrentTime = curr/(60*60*24) + 25567;

    tm tmInitialize{};
    tmInitialize.tm_year = CurrentTime.tm_year;
    tmInitialize.tm_mon = CurrentTime.tm_mon;
    tmInitialize.tm_mday = CurrentTime.tm_mday + 45;

    time_t timeValue = mktime(&tmInitialize);
    int dInitialize = timeValue/(60*60*24) + 25567;

    Date test1;
    Date test2(tmInitialize);
    Date test3(dInitialize);

    TEST(test1.getDuration(),dCurrentTime);
    TEST(test2.getDuration(),dInitialize);
    TEST(test3.getDuration(),dInitialize);


    test3 = test1 + test2;
    int diff = test3 - test1;
    test1 += 120;

    TEST(test3.getDuration(),dCurrentTime+44);
    TEST(diff,44);
    TEST(test1.getDuration(),dCurrentTime+120);

    test1.print();
    test2.print();
    test3.print();

    //end of Date tests

    //Customer tests

    Order order("wedding",test1 += 46);

    Customer test4("Douglass","James","DJ45@hotmail.com","45 boulevard lane",534634353);

    string temp = "Douglass";
    TEST(test4.getName(),temp);
    temp = "James";
    TEST(test4.getSurname(),temp);
    temp = "DJ45@hotmail.com";
    TEST(test4.getEmail(),temp);
    temp = "45 boulevard lane";
    TEST(test4.getAddress(),temp);
    TEST(test4.getPhone(),534634353);

    TEST(test4.getOrderCount(),0);
    test4.addOrder(&order);
    TEST(test4.getOrderCount(),1);
    test4.removeOrder(&order);
    TEST(test4.getOrderCount(),0);

    test4.addOrder(&order);

    cout << endl;
    test4.print();

    //Customer tests end

    //Employee tests

    Employee test5("mary","josephine",54000.00,Manager,&order);

    temp = "mary";
    TEST(test5.getName(),temp);
    temp = "josephine";
    TEST(test5.getSurname(),temp);
    TEST(test5.getSalary(),54000.00);
    TEST(test5.getPosition(),Manager);

    cout << endl;
    test5.print();

    //Employee tests end

    //Order tests

    Order test6("conference",test2,&test4);

    item item1{"Fish filet",25.99};
    item item2{"Pork chops",14.49};
    temp = "conference";

    TEST(test6.get_event(),temp);
    TEST(test6.get_covered(),false);
    TEST(test6.get_bill(),0.00);
    TEST(test6.getMenuSize(),0);

    test6.add_item(item1);
    TEST(test6.get_bill(),25.99);
    TEST(test6.getMenuSize(),1);

    test6.remove_item("Fish filet");
    TEST(test6.get_bill(),0.00);
    TEST(test6.getMenuSize(),0);

    test6.add_item(item2);

    cout << endl;
    test6.print();

    //Order tests end

    //Company tests

    Company test7("WUT catering",37483920,"wutcatr32@gmail.com","warsaw, 24/5 stolcaw");
    temp = "WUT catering";
    TEST(test7.getName(),temp);
    TEST(test7.getPhone(),37483920);
    temp = "wutcatr32@gmail.com";
    TEST(test7.getEmail(),temp);
    temp = "warsaw, 24/5 stolcaw";
    TEST(test7.getAddress(),temp);

    TEST(test7.getCustomersize(),0);
    TEST(test7.getOrdersize(),0);
    TEST(test7.getEmployeesize(),0);

    test7.addCustomer("Joey","Cole","JClm7654@gmail.com","louisana 43 lake",838583811);
    test7.addEmployee("Malissa","White",32000.00,Delivery);
    test7.addOrder("party", test3);

    TEST(test7.getCustomersize(),1);
    TEST(test7.getOrdersize(),1);
    TEST(test7.getEmployeesize(),1);

    test7.removeCustomer("Joey","Cole");
    test7.removeEmployee("Malissa","White");
    test7.removeOrder("party");

    TEST(test7.getCustomersize(),0);
    TEST(test7.getOrdersize(),0);
    TEST(test7.getEmployeesize(),0);

    test7.addCustomer("Joey","Cole","JClm7654@gmail.com","louisana 43 lake",838583811);
    test7.addEmployee("Malissa","White",32000.00,Delivery);
    test7.addOrder("party", test3);

    cout << endl;
    test7.print();

    //Company tests end


    return 0;
}
