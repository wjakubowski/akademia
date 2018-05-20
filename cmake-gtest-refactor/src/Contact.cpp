#include <iostream>
#include <string>
#include "Contact.hpp"

void inform_ceo_new_employee(Employee* e) {
    std::cout << "CEO has been informed about hiring "
        << e->person().name() << " " << e->person().surname() << std::endl;
}

void inform_ceo_removed_employee(Employee* e) {
    std::cout << "CEO has been informed about firing"
        << e->person().name() << " " << e->person().surname() << std::endl;
}

void inform_hr_new_employee(Employee* e) {
    std::cout << "HR has been informed about hiring "
        << e->person().name() << " " << e->person().surname() << std::endl;
}

void inform_hr_removed_employee(Employee* e) {
    std::cout << "HR has been informed about firing"
        << e->person().name() << " " << e->person().surname() << std::endl;
}
