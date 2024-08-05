
#include "Date.h"
#include <iostream>
#include <ctime>
#include <math.h>


    tm Date::getCurrentTime() const{

        time_t now = time(nullptr);
        return *localtime(&now);
    }



    int Date::tmtod(tm timeData) const{

        time_t timeValue = mktime(&timeData);
        return (timeValue )/(60*60*24) + 25567;
    }



    tm Date::dtotm(int duration) const{

       time_t timeValue = (duration - 25567) * (24 * 60 * 60);
       return *localtime(&timeValue);
    }



     Date::Date(int duration) : duration(duration), TimeInfo(dtotm(duration)){

        tm currentTime = getCurrentTime();
        if (duration < tmtod(currentTime)) {
            std::cerr << "\nDate value chosen for initialization is outdated and thus cannot be used, the variable has been assigned the present date instead.\n";
            TimeInfo = currentTime;
            duration = tmtod(TimeInfo);
        }

        else{
            TimeInfo = dtotm(duration);
            this->duration = duration;
        }
    }



    Date::Date(tm timeData){

        tm currentTime = getCurrentTime();
        if (tmtod(timeData) < tmtod(currentTime)) {
            std::cerr << "\nDate value chosen for initialization is outdated and thus cannot be used, the variable has been assigned the present date instead.\n\n";
            TimeInfo = currentTime;
            duration = tmtod(TimeInfo);
        }

        else{
            TimeInfo = timeData;
            duration = tmtod(timeData);
        }
    }



    Date::Date() : Date(getCurrentTime()) {}



    void Date::setDuration(const int& duration){

        this->duration = duration;
        TimeInfo = dtotm(duration);
        tm currentTime = getCurrentTime();
        if (duration < tmtod(currentTime)) {
            TimeInfo = currentTime;
            this->duration = tmtod(TimeInfo);
        }
    }



    void Date::setTimeData(const tm& timeData){

        this->TimeInfo = timeData;
        duration = tmtod(timeData);
        tm currentTime = getCurrentTime();
        if (duration < tmtod(currentTime)) {
            TimeInfo = currentTime;
            this->duration = tmtod(TimeInfo);
        }
    }



    int Date::getDuration() const{

        return duration;
    }



    tm Date::getTimeData() const{

        return TimeInfo;
    }



    bool Date::operator<(const Date& other) const{

        return duration < other.duration;
    }



    bool Date::operator>(const Date& other) const{

        return duration > other.duration;
    }



    bool Date::operator==(const Date& other) const{

        return duration == other.duration;
    }



    bool Date::operator!=(const Date& other) const{

        return duration != other.duration;
    }



    int Date::operator-(const Date& other) const{

        return duration - other.duration;
    }



    Date Date::operator+(const Date& other) const{

        return duration + abs(*this - other);
    }



    Date& Date::operator+=(const int& duration){

        this->duration += duration;
        TimeInfo = dtotm(this->duration);
        tm currentTime = getCurrentTime();
        if (this->duration < tmtod(currentTime)) {
            TimeInfo = currentTime;
            this->duration = tmtod(TimeInfo);
        }
        return *this;
    }



    void Date::print() const{
        std::cout << TimeInfo.tm_year + 1900 << '/' << TimeInfo.tm_mon + 1 << '/' << TimeInfo.tm_mday << std::endl;
    }
