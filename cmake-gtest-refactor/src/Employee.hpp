#pragma once

#include <stdexcept>
#include "PersonData.hpp"

const int EMP_DEVELOPER = 0;
const int EMP_TESTER    = 1;
const int EMP_MANAGER   = 2;
const int EMP_CEO       = 3;

class Employee {
    PersonData person_;
    int type_;
    double salary_;
public:
    Employee(const PersonData& person, int type, double salary)
        : person_{person}, type_{type}, salary_{salary}
    {
        if (type < EMP_DEVELOPER || type > EMP_CEO)
            throw std::invalid_argument{"Unknown employee type"};
        if (! person.isValid())
            throw std::invalid_argument{"Invalid PESEL"};
    }

    const PersonData& person() const { return person_; }
    int type() const { return type_; }
    double salary() const { return salary_; }
};
