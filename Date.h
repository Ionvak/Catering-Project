
#ifndef DATE_H

#define DATE_H

#include <ctime>



class Date{
private:
    long unsigned int duration;
    tm TimeInfo;
    tm dtotm(int duration) const;
    int tmtod(tm timeData) const;
    tm getCurrentTime() const;

public:
    Date(int duration);
    Date(tm timeData);
    Date();

    int getDuration() const;
    tm getTimeData() const;

    void setDuration(const int& duration);
    void setTimeData(const tm& timeData);

    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    Date operator+(const Date& other) const;
    int operator-(const Date& other) const;
    Date& operator+=(const int& duration);

    void print() const;

};

#endif // DATE_H
