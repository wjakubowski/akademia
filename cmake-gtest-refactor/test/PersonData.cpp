#include "gtest/gtest.h"
#include "PersonData.hpp"

TEST(PersonData, InvalidLengthPeselRejected) {
    PersonData p{"Jan", "Kowalski", "12345", 33};
    ASSERT_FALSE(p.isValid());
}

TEST(PersonData, InvalidCharPeselRejected) {
    PersonData p{"Jan", "Kowalski", "12345c789010", 33};
    ASSERT_FALSE(p.isValid());
}

TEST(PersonData, InvalidChecksumPeselRejected) {
    PersonData p{"Jan", "Kowalski", "123450789010", 33};
    ASSERT_FALSE(p.isValid());
}

TEST(PersonData, ValidPeselAccepted) {
    PersonData p{"Jan", "Kowalski", "44051401359", 33};
    ASSERT_TRUE(p.isValid());
}
