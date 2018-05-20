#pragma once

#include <vector>
#include "Employee.hpp"

// WE NEED IT ONLY TO CLEAR DATABASE IN TESTS
// DO NOT USE DIRECTLY IN PRODUCTION CODE!
extern std::vector<Employee*> employees;

// Whether CEO/HR are interested in hired/fired employees
// Set to true to start notifying them
extern bool inform_ceo;
extern bool inform_hr;

bool addEmployee(const PersonData& person, int type, double salary);

// Remember to delete e after calling that!
void removeEmployee(Employee* e);

Employee* findEmployee(const std::string& pesel);
