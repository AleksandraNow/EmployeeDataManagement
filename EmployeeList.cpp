//
// Created by linux-user on 22.01.2021.
//

#include <iostream>
#include <fstream>
#include "EmployeeList.h"

//dodanie pracownika
void EmployeeList::add(Employee e) {
    vector.push_back(e);
}

//wyswietelnie listy
void EmployeeList::display() {
    for (auto &element : vector) {
        int id = element.getId();
        int salary = element.getSalary();
        int seniority = element.getSeniority();
        Prof profession = element.getProfesssion();
        std::string name = element.getName();
        std::cout << "id: " << id << " name: " << name << " salary: " << salary << " profession:" << profession
                  << " seniority: " << seniority << std::endl;
    }
}


void EmployeeList::edit(int a, int b) {
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

//wyswietlenie powyzej sal
void EmployeeList::displayAboveSalary(int number) {
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


//wyswietlenie ponizej sal
void EmployeeList::displayBelowSalary(int number) {
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

//na podst okres cechy
void EmployeeList::displayChar(std::string name) {
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

//usuwanie pracownika
void EmployeeList::deleteEmp(int number) {
    if (number >= vector.size()) {
        return;
    }
    vector.erase(vector.begin() + number);
}

//zapis do pliku
void EmployeeList::saveToFile(std::string path) {
    std::ofstream out;
    out.open(path, std::ios::out);
    if (!out.is_open()) {
        return;
    }

    for (auto &element : vector) {
        if (!(out << element.getId() << " " << element.getName() << " " << element.getSalary() << " "
                  << element.getSeniority() << " " << element.getProfesssion() << "\n")) {
            return;
        }
    }

}

//odczyt z pliku
void EmployeeList::load(std::string path) {
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
