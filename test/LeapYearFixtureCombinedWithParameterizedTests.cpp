#include <tuple>

#include <gtest/gtest.h>

#include "../include/LeapYearCalendar.h"


class LeapYearFixtureCombinedWithParameterizedTests : public ::testing::Test
{
protected:
    LeapYearCalendar leapYearCalendar;
};

TEST_F(LeapYearFixtureCombinedWithParameterizedTests, 1996_IsDivisibleBy4_ShouldBeALeapYear) {
    ASSERT_TRUE(leapYearCalendar.isLeap(1996));
}

TEST_F(LeapYearFixtureCombinedWithParameterizedTests, 1700_IsDivisibleBy100AndNotBy400_ShouldNotBeALeapYear) {
    ASSERT_FALSE(leapYearCalendar.isLeap(1700));
}

TEST_F(LeapYearFixtureCombinedWithParameterizedTests, 1600_IsDivisibleBy400_ShouldBeALeapYear) {
    ASSERT_TRUE(leapYearCalendar.isLeap(1600));
}


class LeapYearParametrizedTestFixtureBasedOnFixture :
        public LeapYearFixtureCombinedWithParameterizedTests,
        public ::testing::WithParamInterface<std::tuple<int, bool>> {
};


TEST_P(LeapYearParametrizedTestFixtureBasedOnFixture, ChecksIfLeapYear) {
    bool expected = std::get<1>(GetParam());
    int year = std::get<0>(GetParam());
    ASSERT_EQ(expected, leapYearCalendar.isLeap(year));
}

INSTANTIATE_TEST_CASE_P(
        LeapYearTests,
        LeapYearParametrizedTestFixtureBasedOnFixture,
        ::testing::Values(
                std::tuple<int, bool>(7, false),
                std::tuple<int, bool>(2001, false),
                std::tuple<int, bool>(1996, true),
                std::tuple<int, bool>(1700, false),
                std::tuple<int, bool>(1600, true)));
