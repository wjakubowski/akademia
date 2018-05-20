#include "work.hpp"
#include "Database.hpp"
#include <iostream>

std::vector<std::string> dayOfWork(Employee* e) {
    // commute
    std::vector<std::string> stuff;
    if (e->type() != EMP_CEO) {
        stuff.push_back("take a bus to work");
    } else {
        stuff.push_back("fly a private helicopter to work");
    }
    // everyone does that, don't they?
    stuff.push_back("grab a coffee");

    if (e->type() == EMP_DEVELOPER) {
        stuff.push_back("surf the web mindlessly");
        stuff.push_back("play table soccer");
    } else if (e->type() == EMP_CEO) {
        stuff.push_back("Play golf with a senator");
    }
    stuff.push_back("grab another coffee");
    switch(e->type()) {
    case EMP_TESTER:    stuff.push_back("Test stuff");        break;
    case EMP_DEVELOPER: stuff.push_back("Develop stuff");     break;
    case EMP_MANAGER:   stuff.push_back("Manage stuff");      break;
    case EMP_CEO:       stuff.push_back("Manage big stuff");  break;
    }
    stuff.push_back("attend a meeting");
    if (e->type() == EMP_MANAGER) {
        stuff.push_back("ride a bike home");
    } else if (e->type() == EMP_CEO) {
        stuff.push_back("fly a private helicopter home");
    } else {
        if (e->person().age() > 35) {
            stuff.push_back("ride a bus home");
        } else {
            stuff.push_back("ride a bike home");
        }
    }
    return stuff;
}

void dayOfWork() {
    for (Employee* e : employees) {
        switch (e->type()) {
        case EMP_TESTER:    std::cout << "Tester ";    break;
        case EMP_DEVELOPER: std::cout << "Developer "; break;
        case EMP_CEO:       std::cout << "CEO ";       break;
        case EMP_MANAGER:   std::cout << "Manager ";   break;
        }
        std::cout << e->person().name() << " " << e->person().surname() << " work day:\n";
        std::vector<std::string> activities = dayOfWork(e);
        for (int i = 0; i < activities.size(); ++ i) {
            std::cout << " - " << activities[i] << std::endl;
        }
    }
}
