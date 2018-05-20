#include <fstream>
#include <cstdio>
#include <map>
#include "gtest/gtest.h"
#include "PersonData.hpp"
#include "Database.hpp"
#include "Employee.hpp"
#include "Report.hpp"

class ReportTest : public ::testing::Test {
protected:
    // Common data
    const char* pesel1 = "44051401359";
    PersonData p1{"Jan", "Kowalski", pesel1, 33};

    const char* pesel2 = "92071314764";
    PersonData p2{"Ala", "Nowak", pesel2, 28};

    const char* pesel3 = "90080517455";
    PersonData p3{"Zbigniew", "Wozniak", pesel3, 25};

    const char* pesel4 = "90060804786";
    PersonData p4{"Zbigniew", "Kapusta", pesel4, 35};

    const char* pesel5 = "67040500538";
    PersonData p5{"Zenon", "Iksinski", pesel5, 40};

    // Executed before each test
    void SetUp() override {
        employees.clear(); // just in case
        addEmployee(p1, EMP_DEVELOPER, 5000);
        addEmployee(p2, EMP_MANAGER, 7000);
        addEmployee(p3, EMP_TESTER, 5000);
        addEmployee(p4, EMP_CEO, 85000);
        addEmployee(p5, EMP_MANAGER, 8000);
    }
    // Executed after each test
    void TearDown() override {
        employees.clear();
    }

    const char* path = "tmp.out";


    void readAndCompare(const std::map<std::string, double>& expected) {
        // Read back and check values
        std::ifstream in{path};

        std::string position, name, surname, pesel;
        double total;
        while (! in.eof()) {
            in >> position >> name >> surname >> pesel >> total;
            if (! in) break;
            auto it = expected.find(pesel);
            if (it != expected.end()) {
                EXPECT_DOUBLE_EQ(total, it->second);
            } else {
                FAIL() << "Unexpected PESEL read: " << pesel;
            }
        }

        in.close();
        std::remove(path); // remove the temporary file created earlier
    }
};

TEST_F(ReportTest, BasicVersionWorksAsIntended) {
    report_to_file(path, false, false, false);
    readAndCompare({
        {pesel1, 5000},
        {pesel2, 7000},
        {pesel3, 5000},
        {pesel4, 85000},
        {pesel5, 8000}
    });
}

TEST_F(ReportTest, SimpleBonusWorksAsIntended) {
    report_to_file(path, true, false, false);
    readAndCompare({
        {pesel1, 5900},
        {pesel2, 9600},
        {pesel3, 5600},
        {pesel4, 95000},
        {pesel5, 10900}
    });
}

TEST_F(ReportTest, SuperBonusWorksAsIntended) {
    report_to_file(path, false, false, true);
    readAndCompare({
        {pesel1, 7000},
        {pesel2, 7500},
        {pesel3, 7000},
        {pesel4, 170500},
        {pesel5, 9000}
    });
}

TEST_F(ReportTest, BaseTaxesWorkAsIntended) {
    report_to_file(path, false, true, false);
    readAndCompare({
        {pesel1, 3500},
        {pesel2, 4200},
        {pesel3, 3500},
        {pesel4, 81600},
        {pesel5, 4800}
    });
}

TEST_F(ReportTest, BonusTaxesWorkAsIntended) {
    report_to_file(path, true, true, false);
    readAndCompare({
        {pesel1, 4130},
        {pesel2, 5760},
        {pesel3, 3920},
        {pesel4, 91200},
        {pesel5, 6540}
    });
}

TEST_F(ReportTest, SuperBonusTaxesWorkAsIntended) {
    report_to_file(path, false, true, true);
    readAndCompare({
        {pesel1, 4200},
        {pesel2, 4500},
        {pesel3, 4200},
        {pesel4, 163680},
        {pesel5, 5400}
    });
}
