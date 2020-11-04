#include <gtest/gtest.h>

#include "../include/LeapYearCalendar.h"

TEST(LeapYearStandaloneTests, 1IsOdd_IsNotLeapYear) {
LeapYearCalendar leapYearCalendar;
ASSERT_FALSE(leapYearCalendar.isLeap(1));
}

TEST(LeapYearStandaloneTests, 711IsOdd_IsNotLeapYear) {
LeapYearCalendar leapYearCalendar;
ASSERT_FALSE(leapYearCalendar.isLeap(711));
}

TEST(LeapYearStandaloneTests, 1989IsOdd_IsNotLeapYear) {
LeapYearCalendar leapYearCalendar;
ASSERT_FALSE(leapYearCalendar.isLeap(1989));
}

TEST(LeapYearStandaloneTests, 2013IsOdd_IsNotLeapYear) {
LeapYearCalendar leapYearCalendar;
ASSERT_FALSE(leapYearCalendar.isLeap(2013));
}
