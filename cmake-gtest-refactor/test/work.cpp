#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "work.hpp"

using ::testing::ElementsAre;

TEST(Work, CEOWorksAsExpected) {
    PersonData p{"Jan", "Kowalski", "44051401359", 33};
    Employee e{p, EMP_CEO, 100000};

    auto work = dayOfWork(&e);
    ASSERT_THAT(work, ElementsAre(
                "fly a private helicopter to work",
                "grab a coffee",
                "Play golf with a senator",
                "grab another coffee",
                "Manage big stuff",
                "attend a meeting",
                "fly a private helicopter home"));
}

TEST(Work, ManagerWorksAsExpected) {
    PersonData p{"Jan", "Kowalski", "44051401359", 33};
    Employee e{p, EMP_MANAGER, 10000};

    auto work = dayOfWork(&e);
    ASSERT_THAT(work, ElementsAre(
                "take a bus to work",
                "grab a coffee",
                "grab another coffee",
                "Manage stuff",
                "attend a meeting",
                "ride a bike home"));
}

TEST(Work, YoungDeveloperWorksAsExpected) {
    PersonData p{"Jan", "Kowalski", "44051401359", 33};
    Employee e{p, EMP_DEVELOPER, 10000};

    auto work = dayOfWork(&e);
    ASSERT_THAT(work, ElementsAre(
                "take a bus to work",
                "grab a coffee",
                "surf the web mindlessly",
                "play table soccer",
                "grab another coffee",
                "Develop stuff",
                "attend a meeting",
                "ride a bike home"));
}

TEST(Work, DeveloperWorksAsExpected) {
    PersonData p{"Jan", "Kowalski", "44051401359", 38};
    Employee e{p, EMP_DEVELOPER, 10000};

    auto work = dayOfWork(&e);
    ASSERT_THAT(work, ElementsAre(
                "take a bus to work",
                "grab a coffee",
                "surf the web mindlessly",
                "play table soccer",
                "grab another coffee",
                "Develop stuff",
                "attend a meeting",
                "ride a bus home"));
}

TEST(Work, YoungTesterWorksAsExpected) {
    PersonData p{"Jan", "Kowalski", "44051401359", 33};
    Employee e{p, EMP_TESTER, 10000};

    auto work = dayOfWork(&e);
    ASSERT_THAT(work, ElementsAre(
                "take a bus to work",
                "grab a coffee",
                "grab another coffee",
                "Test stuff",
                "attend a meeting",
                "ride a bike home"));
}

TEST(Work, TesterWorksAsExpected) {
    PersonData p{"Jan", "Kowalski", "44051401359", 38};
    Employee e{p, EMP_TESTER, 10000};

    auto work = dayOfWork(&e);
    ASSERT_THAT(work, ElementsAre(
                "take a bus to work",
                "grab a coffee",
                "grab another coffee",
                "Test stuff",
                "attend a meeting",
                "ride a bus home"));
}
