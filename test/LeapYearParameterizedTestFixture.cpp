#include <gtest/gtest.h>

#include "../include/LeapYearCalendar.h"

class LeapYearParameterizedTestFixture :public ::testing::TestWithParam<int> {
protected:
    LeapYearCalendar leapYearCalendar;
};

TEST_P(LeapYearParameterizedTestFixture, OddYearsAreNotLeapYears) {
    int year = GetParam();
    ASSERT_FALSE(leapYearCalendar.isLeap(year));
}

INSTANTIATE_TEST_SUITE_P(
        LeapYearTests,
        LeapYearParameterizedTestFixture,
        ::testing::Values(
                1, 711, 1989, 2013
        ));
