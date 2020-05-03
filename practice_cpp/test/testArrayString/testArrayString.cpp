#include "array_n_string.h"
#include "testArrayString.h"

//using ::testing::Return;

ArrayStringTest::ArrayStringTest() {

}

ArrayStringTest::~ArrayStringTest() {};

void ArrayStringTest::SetUp() {};

void ArrayStringTest::TearDown() {};

TEST_F(ArrayStringTest, abcdIsUniqueChars) {
    EXPECT_EQ(CArrayString::isAllCharUnique("abcd"), true);
}

TEST_F(ArrayStringTest, abcdABCDIsUniqueChars) {
    EXPECT_EQ(CArrayString::isAllCharUnique("abcdABCD"), true);
}

TEST_F(ArrayStringTest, abcabcIsNotUniqueChars) {
    EXPECT_EQ(CArrayString::isAllCharUnique("abcabc"), false);
}

TEST_F(ArrayStringTest, emptyIsUniqueChars) {
    EXPECT_EQ(CArrayString::isAllCharUnique(""), true);
}

TEST_F(ArrayStringTest, isCombination) {
    EXPECT_EQ(CArrayString::isStringsHaveSameCombinationChar("abcd", "bcad"), true);
}

TEST_F(ArrayStringTest, ALongIsNotCombinations) {
    EXPECT_EQ(CArrayString::isStringsHaveSameCombinationChar("abcde", "bcad"), false);
}

TEST_F(ArrayStringTest, BLongIsNotCombinations) {
    EXPECT_EQ(CArrayString::isStringsHaveSameCombinationChar("abcd", "bcade"), false);
}

TEST_F(ArrayStringTest, RepeatIsNotCombinations) {
    EXPECT_EQ(CArrayString::isStringsHaveSameCombinationChar("abcde", "aabbccddee"), false);
}

TEST_F(ArrayStringTest, ReplaceEmptyMrJohnSmith) {
    EXPECT_EQ(CArrayString::replaceEmptyString("Mr John Smith    ", 13), "Mr%20John%20Smith");
}

TEST_F(ArrayStringTest, ReplaceSingleEmpty) {
    EXPECT_EQ(CArrayString::replaceEmptyString("A B  ", 3), "A%20B");
}