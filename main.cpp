#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Prof.h"
#include "Employee.h"


using namespace std;





class EmployeeList {
public:
    std::vector<Employee> vector;

    void add(Employee e);

    void display();

    void deleteEmp(int number);

    void saveToFile(std::__cxx11::string path);

    void load(std::__cxx11::string path);

    void displayAboveSalary(int number);

    void displayBelowSalary(int number);

    void displayChar(string name);

    void sortEmp();


    void edit(int a, int b);
};

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
/*
void EmployeeList::sortEmp() {
    for (auto &element : vector) {
        sort(vector.begin(), vector.end(), comp);
        int id = element.getId();
        std::string name = element.getName();
        std::cout << id << " " << name << std::endl;
    }
    sort(vector.begin(), vector.end(), comp);
}

*/
int main() {
    cout << "test" << endl;

    int ch;
    EmployeeList lista;
    Employee emp = *new Employee(1, "ola", 12, 15, Prof(0));
    Employee wx = *new Employee(1, "ola", 12, 15, Prof(0));
    Employee gtf = *new Employee(1, "ola", 12, 15, Prof(0));

    lista.add(emp);
    lista.add(wx);
    lista.add(gtf);

    int id;
    std::string name;
    int salary;
    int seniority;
    int prof;
    int number;
    int index;
    string readPath;

    string path;
    cin >> ch;



        switch (ch) {
            case 1:
/*
                cout << "ID: ";
                cin >> id;

                cout << "name: ";
                cin >> name;

                cout << "salary: ";
                cin >> salary;

                cout << "seniority: ";
                cin >> seniority;

                cout << "professsion: ";
                cin >> prof;
                // Employee emp = *new Employee(id,name,salary,seniority, Prof(prof) );


                //lista.add(emp);
                */
            case 2:
                lista.display();
                break;

            case 3:
                lista.deleteEmp(1);
                break;
            case 4:
                cout << "name: ";
                cin >> name;
                lista.displayChar(name);
                break;
            case 5:
                cout << "salary: ";
                cin >> salary;
                lista.displayAboveSalary(salary);
            case 6:
                cout << "salary: ";
                cin >> salary;
                lista.displayBelowSalary(salary);
            /*case 7:
                lista.sortEmp();
                */
            case 8:
                cout << "Path do save data: ";
                cin >> path;
                lista.saveToFile(path);
                break;
            default:
                cout << "test";

        }
    };








