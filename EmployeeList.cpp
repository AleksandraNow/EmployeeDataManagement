//
// Created by linux-user on 22.01.2021.
//

#include <iostream>
#include <fstream>
#include "EmployeeList.h"
#include "Employee.h"
#include <algorithm>

using namespace std;

void EmployeeList::addEmployee(Employee e) {
    vector.push_back(e);
}

void EmployeeList::displayEmployee() {
    std::map<Prof, std::string> employeeMap;
    //employeeMap.insert(ProfMap::value_type(architect, "architect"));
    employeeMap.insert(ProfMap::value_type(seller, "seller"));

    employeeMap[architect] = "architect";

    //for (auto &element : vector) {
    for (size_t i = 0; i < vector.size(); ++i) {
        Employee &element = vector[i];

        int salary = element.getSalary();
        int seniority = element.getSeniority();
        Prof profession = element.getProfesssion();
        std::string name = element.getName();
        std::cout << "id: " << i << " name: " << name << " salary: " << salary << " profession:"
                  << employeeMap[profession]
                  << " seniority: " << seniority << std::endl;
    }
}

void EmployeeList::editEmployee(int a, int b) {
    for (auto &element : vector) {
        if (element.getId() == a) {
            element.setSeniority(b);
            int id = element.getId();
            int salary = element.getSalary();
            int seniority = element.getSeniority();
            Prof profession = element.getProfesssion();
            std::string name = element.getName();
            std::cout << "id: " << id << " name: " << name << " salary: " << salary << " profession:" << profession
                      << " seniority: " << seniority << std::endl;
        }
    }
}

void EmployeeList::displayEmployeeAboveSalary(int number) {
    ProfMap employeeMap;
    employeeMap.insert(ProfMap::value_type(architect, "architect"));
    employeeMap.insert(ProfMap::value_type(seller, "seller"));

    for (auto &element : vector) {
        if (element.getSalary() > number) {
            int id = element.getId();
            int salary = element.getSalary();
            int seniority = element.getSeniority();
            Prof profession = element.getProfesssion();
            std::string name = element.getName();
            std::cout << "id: " << id << " name: " << name << " salary: " << salary << " profession:" << profession
                      << " seniority: " << seniority << std::endl;
        }

    }
}

void EmployeeList::displayEmployeeBelowSalary(int number) {
    for (auto &element : vector) {
        if (element.getSalary() < number) {
            int id = element.getId();
            int salary = element.getSalary();
            int seniority = element.getSeniority();
            Prof profession = element.getProfesssion();
            std::string name = element.getName();
            std::cout << "id: " << id << " name: " << name << " salary: " << salary << " profession:" << profession
                      << " seniority: " << seniority << std::endl;
        }

    }
}

void EmployeeList::displayEmployeeByCharacter(std::string name) {
    for (auto &element : vector) {
        if (element.getName() == name) {
            int id = element.getId();
            int salary = element.getSalary();
            int seniority = element.getSeniority();
            Prof profession = element.getProfesssion();
            std::string name = element.getName();
            std::cout << "id: " << id << " name: " << name << " salary: " << salary << " profession:" << profession
                      << " seniority: " << seniority << std::endl;
        }

    }
}

void EmployeeList::deleteEmployee(int number) {
    if (number >= vector.size()) {
        return;
    }
    vector.erase(vector.begin() + number - 1);
}

void EmployeeList::saveDataToFile(std::string path) {
    std::ofstream out;
    out.open(path, std::ios::out);
    if (!out.is_open()) {
        return;
    }
/*
    for (auto &element : vector) {
        if (!(out << element.getId() << " " << element.getName() << " " << element.getSalary() << " "
                  << element.getSeniority() << " " << element.getProfesssion() << "\n")) {
            return;
        }
    }
*/
    for (size_t i = 0; i < vector.size(); ++i) {
        out << (i + 1) << ". " << vector[i] << "\n";
        out << (i + 1) << ". " << vector[i].getId() << "\n";
    }


}

void EmployeeList::readDataFromFile(std::string path) {
    int a, b;
    std::ifstream odczyt(path);

    if (odczyt.is_open()) {
        char wiersz[10000];
        while (odczyt.getline(wiersz, 10000)) {
            std::cout << wiersz << std::endl; //wypisz to co wczytałes z pliku

        }
    } else
        std::cout << "Nie udało się otworzyć pliku";


}


void EmployeeList::sortEmp() {
    std::sort(vector.begin(), vector.end(), comp);
}

