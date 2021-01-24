#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Prof.h"
#include "Employee.h"
#include "EmployeeList.h"


using namespace std;

int main() {
    EmployeeList lista;

    int id;
    string name;
    int salary;
    int seniority;
    int prof;
    string readPath;
    string path;
    int choice;

    do {
        cout << "\n\n\t2.DISPLAY ALL EMPLOYEES";
        cout << "\n\n\t3.DELETE EMPLOYEE RECORD";
        cout << "\n\n\t4.DISPLAY THE EMPLOYEE WHO HAS THE NAME";
        cout << "\n\n\t5.DISPLAY THE EMPLOYEE ABOVE SALARY";
        cout << "\n\n\t6.DISPLAY THE EMPLOYEE BELOW SALARY";
        cout << "\n\n\t8.SAVE DATA TO FILE";
        cout << "\n\n\t9.READ DATA FROM FILE";
        cout << "\n\n\t10.EXIT";
        cout << "\n\n\tPlease Enter Your Choice (1-10): ";
        cin >> choice;

        switch (choice) {
            case 1: {

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

                Employee emp(id, name, salary, seniority, Prof(prof));

                lista.addEmployee(emp);
                break;

            }

            case 2:
                lista.displayEmployee();
                break;

            case 3:
                lista.deleteEmployee(1);
                break;
            case 4:
                cout << "name: ";
                cin >> name;
                lista.displayEmployeeByCharacter(name);
                break;
            case 5:
                cout << "salary: ";
                cin >> salary;
                lista.displayEmployeeAboveSalary(salary);
                break;
            case 6:
                cout << "salary: ";
                cin >> salary;
                lista.displayEmployeeBelowSalary(salary);
                break;
                /*case 7:
                    lista.sortEmp();
*/
            case 8:
                cout << "Path do save data: ";
                cin >> path;
                lista.saveDataToFile(path);
                break;
            case 9:
                cout << "Path to read data: ";
                cin >> path;
                lista.readDataFromFile(path);
                break;
            default:
                cout << "test";

        }
    } while (choice != 10);

};








