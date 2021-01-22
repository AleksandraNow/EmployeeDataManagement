//
// Created by linux-user on 22.01.2021.
//

#include "Employee.h"


Employee::Employee(int id, std::string name, int salary, int seniority, Prof professsion) {
    this->id = id;
    this->name = name;
    this->salary = salary;
    this->seniority = seniority;
    this->professsion = professsion;

}

void Employee::setId(int id) {
    Employee::id = id;
}

void Employee::setName(const std::string &name) {
    Employee::name = name;
}

int Employee::getSalary() const {
    return salary;
}

int Employee::getId() const {
    return id;
}

void Employee::setSalary(int salary) {
    Employee::salary = salary;
}

int Employee::getSeniority() const {
    return seniority;
}

void Employee::setSeniority(int seniority) {
    Employee::seniority = seniority;
}

Prof Employee::getProfesssion() const {
    return professsion;
}

void Employee::setProfesssion(Prof professsion) {
    Employee::professsion = professsion;
}

std::string Employee::getName() {
    return name;
}

/*
bool comp(const Employee &l, const Employee &r) {
    return l.getId() < r.getId();
}
*/