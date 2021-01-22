#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>


using namespace std;

enum Prof {
    architect = 0,
    seller = 1
};


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

    void setName(const string &name);

    int getSalary() const;

    void setSalary(int salary);

    int getSeniority() const;

    void setSeniority(int seniority);

    Prof getProfesssion() const;

    void setProfesssion(Prof professsion);

    int getId() const;

    string getName();
};


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

void Employee::setName(const string &name) {
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

string Employee::getName() {
    return name;
}

bool comp(const Employee &l, const Employee &r) {
    return l.getId() < r.getId();
}


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
        if (!(out << element.getId() << " " << element.getName() << " " << element.getSalary() << " " << element.getSeniority() << " " << element.getProfesssion() <<  "\n")) {
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

void EmployeeList::sortEmp() {
    for (auto &element : vector) {
        sort(vector.begin(), vector.end(), comp);
        int id = element.getId();
        std::string name = element.getName();
        std::cout << id << " " << name << std::endl;
    }
    sort(vector.begin(), vector.end(), comp);
}


int main() {
    cout << "test" << endl;

    int ch;
    EmployeeList lista;
    int id;
    std::string name;
    int salary;
    int seniority;
    int prof;
    int number;
    int index;
    string readPath;

    string path;


    do {

        int num;
        cout << "\n\n\t1.Add employee";
        cout << "\n\n\t2.Display employees";
        cout << "\n\n\t3.Edit employee";
        cout << "\n\n\t4.Delete employee";
        cout << "\n\n\t5.Search employee base on ID";
        cout << "\n\n\t6.Display employee above salary: ";
        cout << "\n\n\t7.Display employee below salary: ";
        cout << "\n\n\t8.Sort employee based on name";
        cout << "\n\n\t9. Save data to file";
        cout << "\n\n\t10.Read data from file";
        cout << "\n\n\t11. Exit";
        cout << "\n\n\tPlease Enter Your Choice (1-11): ";
        cin >> ch;


        switch (ch) {
            case '1':
                Employee *emp;
                cout << "ID: ";
                cin >> id;
                emp->setId(id);
                cout << "name: ";
                cin >> name;
                emp->setName(name);
                cout << "salary: ";
                cin >> salary;
                emp->setSalary(salary);
                cout << "seniority: ";
                cin >> seniority;
                emp->setSeniority(seniority);
                cout << "professsion: ";
                cin >> prof;
                emp->setProfesssion(static_cast<Prof>(prof));


                emp = new Employee(id, name, salary, seniority, (Prof)prof);
                lista.add(*emp);


            case '2' :
                lista.display();
            case'3':
                cout << "id: ";
                cin >> id;
                cout << "seniority change to : ";
                cin >> number;
                lista.edit(id, number);


            case '4' :
                cout << "index: ";
                cin >> index;
                lista.deleteEmp(id);
            case'5':
                cout << "name: ";
                cin >> name;
                lista.displayChar(name);
            case '6':
                cout << "salary: ";
                cin >> salary;
                lista.displayAboveSalary(salary);
            case '7':
                cout << "salary: ";
                cin >> salary;
                lista.displayBelowSalary(salary);
            case '8':
                lista.sortEmp();
            case'9' :
                cout << "Path do save data: ";
                cin >> path;
                lista.saveToFile(path);
                break;
            default:
                cout << "test";
        }

    } while (ch != '9');

    return 0;



};



