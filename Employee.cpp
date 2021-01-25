//
// Created by linux-user on 22.01.2021.
//
#include <iostream>
#include "Employee.h"
using namespace std;

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

std::string Employee::getName() const {
    return name;
}

bool comp(const Employee &l, const Employee &r) {
    return l.getSalary() < r.getSalary();
}

std::ostream& operator<<(std::ostream& out, const Employee& employee){
    out << employee.getSeniority();
    return out;
}

Employee getDataEmployee() {
    std::string name;
    int salary;
    int seniority;
    int professsion;

    cout << "name: ";
    cin >> name;

    cout << "salary: ";
    cin >> salary;

    cout << "seniority: ";
    cin >> seniority;

    cout << "professsion: ";
    cin >> professsion;

    Employee emp(0, name, salary, seniority, Prof(professsion));
    return emp;
}
