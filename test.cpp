#include <gtest/gtest.h>
#include "arabic_roman.h"
#include <string>

TEST(ARABIC_ROMAN, arabic_to_roman_values) {
    EXPECT_STREQ(arabic_to_roman(0).c_str(), "") << "0 equals empty string";
    EXPECT_STREQ(arabic_to_roman(1).c_str(), "I") << "1 equals I";
    EXPECT_STREQ(arabic_to_roman(5).c_str(), "V") << "5 equals V";
    EXPECT_STREQ(arabic_to_roman(10).c_str(), "X") << "10 equals X";
    EXPECT_STREQ(arabic_to_roman(50).c_str(), "L") << "50 equals L";
    EXPECT_STREQ(arabic_to_roman(100).c_str(), "C") << "100 equals C";
    EXPECT_STREQ(arabic_to_roman(500).c_str(), "D") << "500 equals D";
    EXPECT_STREQ(arabic_to_roman(1000).c_str(), "M") << "1000 equals M";
    EXPECT_STREQ(arabic_to_roman(12).c_str(), "XII") << "12 equals XII";
    EXPECT_STREQ(arabic_to_roman(9).c_str(), "IX") << "9 equals IX";
    EXPECT_STREQ(arabic_to_roman(9, false).c_str(), "VIIII") << "9 equal VIIII if subs disabled";
    EXPECT_STREQ(arabic_to_roman(2014).c_str(), "MMXIV");
    EXPECT_STREQ(arabic_to_roman(2014, false).c_str(), "MMXIIII");
    EXPECT_STREQ(arabic_to_roman(1990).c_str(), "MCMXC");
    EXPECT_STREQ(arabic_to_roman(1954).c_str(), "MCMLIV");
    EXPECT_STREQ(arabic_to_roman(45).c_str(), "XLV");
}

TEST(ROMAN_ARABIC, roman_to_arabic_values) {
    EXPECT_EQ(roman_to_arabic("D"), 500);
    EXPECT_EQ(roman_to_arabic("VI"), 6);     
    EXPECT_EQ(roman_to_arabic("XII"), 12);
    EXPECT_EQ(roman_to_arabic("MMXIV"), 2014);   
    EXPECT_EQ(roman_to_arabic("MMXIIII"), 2014);
    EXPECT_EQ(roman_to_arabic("MCMLIV"), 1954);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
