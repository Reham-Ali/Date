#include <iostream>
using namespace std;

class Date 
{
private:
    int day, month, year;
    static const int daysInMonth[13]; // Array to store the number of days in each month
    bool isLeapYear() const; // Check if the year is a leap year

public:
    // Constructors
    Date();
    Date(int d, int m, int y);
    Date(const Date& d); // Copy constructor

    // Setter functions
    void setDate(int d, int m, int y);
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    // Getter functions
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Printing functions
    void printFormat1() const; // Print date as mm/dd/yyyy
    void printFormat2() const; // Print date as Month day, year
    void printFormat3() const; // Print date as dd-Month-yyyy

    // Increment functions
    void incDay(int n = 1);
    void incMonth(int n = 1);
    void incYear(int n = 1);

    // String functions to return formatted dates
    string getDateInFormat1() const; // Return date as mm/dd/yyyy
    string getDateInFormat2() const; // Return date as Month day, year
    string getDateInFormat3() const; // Return date as dd-Month-yyyy
};

// Define static member
const int Date::daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


bool Date::isLeapYear() const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


Date::Date() : day(1), month(1), year(1500) {}


Date::Date(int d, int m, int y) 
{
    setDate(d, m, y);
}


Date::Date(const Date& d) : day(d.day), month(d.month), year(d.year) {}


void Date::setDate(int d, int m, int y) {
    setDay(d);
    setMonth(m);
    setYear(y);
}

void Date::setDay(int d) {
    if (month == 2 && isLeapYear()) {
        if (d >= 1 && d <= 29) day = d;
        else cout << "Invalid day for February in a leap year.\n";
    }
    else if (d >= 1 && d <= daysInMonth[month]) {
        day = d;
    }
    else {
        cout << "Invalid day value.\n";
    }
}

void Date::setMonth(int m) {
    if (m >= 1 && m <= 12) month = m;
    else cout << "Invalid month value.\n";
}

void Date::setYear(int y) {
    if (y >= 1500 && y <= 3000) year = y;
    else cout << "Invalid year value. Year should be between 1500 and 3000.\n";
}



int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}


void Date::printFormat1() const {
    cout << month << "/" << day << "/" << year << endl;
}


void Date::printFormat2() const {
    const string months[13] = { "", "January", "February", "March", "April", "May", "June",
                                "July", "August", "September", "October", "November", "December" };
    cout << months[month] << " " << day << ", " << year << endl;
}


void Date::printFormat3() const
{
    const string months[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    cout << day << "-" << months[month] << "-" << year << endl;
}


void Date::incDay(int n) 
{
    day += n;
    while (day > daysInMonth[month] || (month == 2 && isLeapYear() && day > 29))
    {
        day -= (month == 2 && isLeapYear()) ? 29 : daysInMonth[month];
        incMonth();
    }
}


void Date::incMonth(int n) 
{
    month += n;
    while (month > 12)
    {
        month -= 12;
        incYear();
    }
}


void Date::incYear(int n) 
{
    year += n;
}


string Date::getDateInFormat1() const 
{
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}


string Date::getDateInFormat2() const
{
    const string months[13] = { "", "January", "February", "March", "April", "May", "June",
                                "July", "August", "September", "October", "November", "December" };
    return months[month] + " " + to_string(day) + ", " + to_string(year);
}


string Date::getDateInFormat3() const
{
    const string months[13] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    return to_string(day) + "-" + months[month] + "-" + to_string(year);
}


int main() 
{
    Date date1(25, 12, 2012);
    date1.printFormat1();   
    date1.printFormat2();  
    date1.printFormat3();  

    
    date1.incDay();
    cout << "After incrementing a day: " << date1.getDateInFormat1() << endl;

    return 0;
}
