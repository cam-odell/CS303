#ifndef EMPLOYEE_DATA_H
#define EMPLOYEE_DATA_H

#include <string>
#include <iostream>
#include <iomanip>


// Base class for all types of employees
class Employee {
public:
    // Constructor with arguments for name, hourly rate, and vacation hours
    Employee(const std::string& name, double hourlyRate, float vacationHours)
        : name_(name), hourlyRate_(hourlyRate), vacationHours_(vacationHours) {}

    // Virtual destructor to ensure correct destruction of derived objects
    virtual ~Employee() {}

    // Pure virtual functions to be implemented by derived classes
    virtual double calculateWeeklySalary(float hoursWorked) const = 0;
    virtual double calculateHealthCareContributions(float hoursWorked) const = 0;
    virtual float calculateVacationDays() const = 0;

    // Getter functions for the private member variables
    std::string getName() const { return name_; }
    double getHourlyRate() const { return hourlyRate_; }
    float getVacationHours() const { return vacationHours_; }

protected:
    // Protected member variables accessible by derived classes
    std::string name_;
    double hourlyRate_;
    float vacationHours_;
};

// Derived class for professional employees
class Professional : public Employee {
public:
    // Constructor with arguments for name, yearly salary, vacation days, and hours worked
    Professional(const std::string& name, double yearlySalary, float vacationDays, float hoursWorked)
        // Call to base class constructor with arguments for name, hourly rate, and vacation hours
        : Employee(name, yearlySalary / (52.0 * hoursWorked), 200) {}

    // Override the virtual functions of the base class
    double calculateWeeklySalary(float hoursWorked) const override {
        return hourlyRate_ * hoursWorked;
    }

    double calculateHealthCareContributions(float hoursWorked) const override {
        return hourlyRate_ * hoursWorked * 0.07;
    }

    float calculateVacationDays() const override {
        return vacationHours_ / 8;
    }
    void printInformation() const {
        std::cout << "Professional employee name: " << name_ << std::endl;
        std::cout << "Professional employee weekly salary: " << std::fixed << std::setprecision(2) << calculateWeeklySalary(40) << std::endl;
        std::cout << "Professional employee healthcare contributions: " << std::fixed << std::setprecision(2) << calculateHealthCareContributions(40) << std::endl;
        std::cout << "Professional employee total vacation days: " << calculateVacationDays() << "\n\n";
    }
};

// Derived class for nonprofessional employees
class Nonprofessional : public Employee {
public:
    // Constructor with arguments for name, hourly rate, and vacation hours
    Nonprofessional(const std::string& name, double hourlyRate, float vacationHours)
        // Call to base class constructor with arguments for name, hourly rate, and vacation hours
        : Employee(name, hourlyRate, vacationHours) {}

    // Override the virtual functions of the base class
    double calculateWeeklySalary(float hoursWorked) const override {
        return hourlyRate_ * hoursWorked;
    }

    double calculateHealthCareContributions(float hoursWorked) const override {
        return hourlyRate_ * hoursWorked * 0.03;
    }

    float calculateVacationDays() const override {
        return vacationHours_ / 120;
    }
    void printInformation() const {
        std::cout << "Nonprofessional employee name: " << name_ << std::endl;
        std::cout << "Nonprofessional employee weekly salary: " << calculateWeeklySalary(30) << std::endl;
        std::cout << "Nonprofessional employee healthcare contributions: " << calculateHealthCareContributions(30) << std::endl;
        std::cout << "Nonprofessional employee vacation days earned: " << std::fixed << std::setprecision(2) << calculateVacationDays() << "\n\n";
    }
};


#endif // EMPLOYEE_DATA_H
