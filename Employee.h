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

    void setId(int id);

    void setName(const std::string &name);

    int getSalary() const;

    void setSalary(int salary);

    int getSeniority() const;

    void setSeniority(int seniority);

    Prof getProfesssion() const;

    void setProfesssion(Prof professsion);

    int getId() const;

    std::string getName();
};



#endif //UNTITLED_EMPLOYEE_H
