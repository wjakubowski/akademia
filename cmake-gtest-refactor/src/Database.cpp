#include "Database.hpp"
#include "Contact.hpp"
#include <iostream>


std::vector<Employee*> employees;

bool inform_ceo = false;
bool inform_hr = false;

bool addEmployee(const PersonData& person, int type, double salary) {
    if (! person.isValid()) {
        return false;
    }
    for (Employee* e : employees) {
        if (e->person().pesel() == person.pesel()) {
            std::cout << "Error: person with PESEL " << person.pesel() << " already works here" << std::endl;
            return false;
        }
    }
    Employee* e = new Employee{person, type, salary};
    employees.push_back(e);
    if (inform_ceo) {
        inform_ceo_new_employee(e);
    }
    if (inform_hr) {
        inform_hr_new_employee(e);
    }
    return true;
}

void removeEmployee(Employee* e) {
    for (int i = 0; i < employees.size(); ++ i) {
        if (e == employees[i]) {
            employees.erase(employees.begin() + i);
            if (inform_ceo) {
                inform_ceo_removed_employee(e);
            }
            if (inform_hr) {
                inform_hr_removed_employee(e);
            }
            break;
        }
    }
}

Employee* findEmployee(const std::string& pesel) {
    for (Employee* e : employees) {
        if (e->person().pesel() == pesel) {
            return e;
        }
    }
    return nullptr;
}
