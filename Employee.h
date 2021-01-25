//
// Created by linux-user on 22.01.2021.
//

#ifndef UNTITLED_EMPLOYEE_H
#define UNTITLED_EMPLOYEE_H


#include <string>
#include "Prof.h"

class Employee {
private:
    int id;
    std::string name;
    int salary;
    int seniority;
    Prof professsion;

public:
    Employee(int id, std::string name, int salary, int seniority, Prof professsion);

    int getSalary() const;

    int getSeniority() const;

    void setSeniority(int seniority);

    Prof getProfesssion() const;

    int getId() const;

    std::string getName() const;

    void setProfesssion(Prof professsion);



    friend std::ostream& operator<<(std::ostream& out, const Employee& employee);

    void setName(const std::string &name);

    void setId(int id);

    void setSalary(int salary);
};

Employee getDataEmployee();

bool comp(const Employee &l, const Employee &r);


#endif //UNTITLED_EMPLOYEE_H
