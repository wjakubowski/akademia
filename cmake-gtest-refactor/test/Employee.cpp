#include "gtest/gtest.h"
#include "Employee.hpp"

TEST(Employee, InvalidPeselThrows) {
    PersonData p{"Jan", "Kowalski", "12345", 33};
    ASSERT_THROW({
        Employee e(p, EMP_DEVELOPER, 5000.0);
    }, std::invalid_argument);
}

TEST(PersonData, InvalidTypeThrows) {
    PersonData p{"Jan", "Kowalski", "44051401359", 33};
    ASSERT_THROW({
        Employee e(p, 666, 5000.0);
    }, std::invalid_argument);
}
