#include "gtest/gtest.h"
#include "Database.hpp"

TEST(Database, CanAddEmployee) {
    employees.clear(); // Call before each test
    PersonData p{"Jan", "Kowalski", "44051401359", 33};
    ASSERT_TRUE(addEmployee(p, EMP_DEVELOPER, 5000));
    
    ASSERT_EQ(employees.size(), 1);
}

TEST(Database, CantAddTwoEmployeesWithSamePesel) {
    employees.clear(); // Call before each test
    PersonData p{"Jan", "Kowalski", "44051401359", 33};
    addEmployee(p, EMP_DEVELOPER, 5000);

    PersonData q{"Piotr", "Nowak", "44051401359", 50};
    ASSERT_FALSE(addEmployee(q, EMP_TESTER, 5000));
    
    ASSERT_EQ(employees.size(), 1);
}


TEST(Database, CanFindEmployee) {
    employees.clear(); // Call before each test
    const char* pesel = "44051401359";
    PersonData p{"Jan", "Kowalski", pesel, 33};
    addEmployee(p, EMP_DEVELOPER, 5000);

    PersonData q{"Ala", "Nowak", "92071314764", 28};
    addEmployee(q, EMP_MANAGER, 7000);
    
    Employee* e = findEmployee(pesel);
    
    ASSERT_NE(e, nullptr);
    ASSERT_EQ(e->person().pesel(), pesel);
}

TEST(Database, CanRemoveEmployee) {
    employees.clear(); // Call before each test
    const char* pesel = "44051401359";
    PersonData p{"Jan", "Kowalski", pesel, 33};
    addEmployee(p, EMP_DEVELOPER, 5000);

    PersonData q{"Ala", "Nowak", "92071314764", 28};
    addEmployee(q, EMP_MANAGER, 7000);

    
    Employee* e = findEmployee(pesel);
    removeEmployee(e);
    e = findEmployee(pesel);
    
    ASSERT_EQ(e, nullptr);
}

TEST(Database, CEOsInformed) {
    bool old = inform_ceo;
    inform_ceo = true;
    employees.clear(); // Call before each test

    const char* pesel = "44051401359";
    PersonData p{"Jan", "Kowalski", pesel, 33};
    addEmployee(p, EMP_DEVELOPER, 5000);

    // How to check if CEO has been informed? :(
    // Can't really test that
    inform_ceo = old;
}

