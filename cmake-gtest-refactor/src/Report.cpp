#include <iostream>
#include <fstream>
#include "Report.hpp"
#include "Database.hpp"


void report_to_stdout(bool with_bonus, bool include_tax, bool with_super_bonus) {
    for (Employee* e : employees) {
        switch (e->type()) {
        case EMP_TESTER:    std::cout << "Tester ";    break;
        case EMP_DEVELOPER: std::cout << "Developer "; break;
        case EMP_CEO:       std::cout << "CEO ";       break;
        case EMP_MANAGER:   std::cout << "Manager ";   break;
        }
        std::cout << e->person().name() << " " << e->person().surname() << " "
                  << e->person().pesel() << " ";
        double total = e->salary();
        if (with_bonus) {
            switch (e->type()) {
            case EMP_TESTER:
            case EMP_DEVELOPER:
                total += 600;
                if (e->person().age() > 30) {
                    total += 300;
                }
                break;
            case EMP_CEO:
                total += 10000;
                break;
            case EMP_MANAGER:
                total += 500;
                total += e->salary() * 0.3;
                break;
            }
        }
        if (with_super_bonus) {
            total += 500;
            switch (e->type()) {
            case EMP_TESTER:
            case EMP_DEVELOPER:
                total += e->salary() * 0.3;
                break;
            case EMP_CEO:
                total += e->salary();
                break;
            case EMP_MANAGER:
                if (e->person().age() > 35) {
                    total += 500;
                }
                break;
            }
        }
        if (include_tax) {
            if (e->type() == EMP_CEO) {
                total *= 0.96; // legal loopholes
            } else {
                if (total > 6000) {
                    total *= 0.6;
                } else {
                    total *= 0.7;
                }
            }
        }
        std::cout << total << std::endl;
    }
}

void report_to_file(const char* file, bool with_bonus, bool include_tax, bool with_super_bonus) {
    std::ofstream out{file};
    for (Employee* e : employees) {
        switch (e->type()) {
        case EMP_TESTER:    out << "Tester ";    break;
        case EMP_DEVELOPER: out << "Developer "; break;
        case EMP_CEO:       out << "CEO ";       break;
        case EMP_MANAGER:   out << "Manager ";   break;
        }
        out << e->person().name() << " " << e->person().surname() << " "
            << e->person().pesel() << " ";
        double total = e->salary();
        if (with_bonus) {
            switch (e->type()) {
            case EMP_TESTER:
            case EMP_DEVELOPER:
                total += 600;
                if (e->person().age() > 30) {
                    total += 300;
                }
                break;
            case EMP_CEO:
                total += 10000;
                break;
            case EMP_MANAGER:
                total += 500;
                total += e->salary() * 0.3;
                break;
            }
        }
        if (with_super_bonus) {
            total += 500;
            switch (e->type()) {
            case EMP_TESTER:
            case EMP_DEVELOPER:
                total += e->salary() * 0.3;
                break;
            case EMP_CEO:
                total += e->salary();
                break;
            case EMP_MANAGER:
                if (e->person().age() > 35) {
                    total += 500;
                }
                break;
            }
        }
        if (include_tax) {
            if (e->type() == EMP_CEO) {
                total *= 0.96; // legal loopholes
            } else {
                if (total > 6000) {
                    total *= 0.6;
                } else {
                    total *= 0.7;
                }
            }
        }
        out << total << std::endl;
    }
}
