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

TEST_F(ArrayStringTest, ReplaceEmptyNoNeed) {
    EXPECT_EQ(CArrayString::replaceEmptyString("ABBBB", 5), "ABBBB");
}

TEST_F(ArrayStringTest, PalindromPermuteOneCharLeft) {
    EXPECT_EQ(CArrayString::isPalindromePermutation("ABA"), true);
}

TEST_F(ArrayStringTest, PalindromPermutePureSymmetry) {
    EXPECT_EQ(CArrayString::isPalindromePermutation("ABBA"), true);
}

TEST_F(ArrayStringTest, PalindromPermuteWithSpace) {
    EXPECT_EQ(CArrayString::isPalindromePermutation("atco cta"), true);
}

TEST_F(ArrayStringTest, PalindromPermuteWithSpaceCapital) {
    EXPECT_EQ(CArrayString::isPalindromePermutation("Tact Coa"), false);
}

TEST_F(ArrayStringTest, PalindromPermuteNegative) {
    EXPECT_EQ(CArrayString::isPalindromePermutation("ABCC"), false);
}

TEST_F(ArrayStringTest, OneEditDistanceRemove) {
    EXPECT_EQ(CArrayString::isOneEditDistance("pale", "ple"), true);
}

TEST_F(ArrayStringTest, OneEditDistanceRemoveTail) {
    EXPECT_EQ(CArrayString::isOneEditDistance("pales", "pale"), true);
}

TEST_F(ArrayStringTest, OneEditDistanceReplace) {
    EXPECT_EQ(CArrayString::isOneEditDistance("pale", "bale"), true);
}

TEST_F(ArrayStringTest, OneEditDistanceReplaceTwo) {
    EXPECT_EQ(CArrayString::isOneEditDistance("pale", "bake"), false);
}

TEST_F(ArrayStringTest, CompressStringNormal) {
    EXPECT_EQ(CArrayString::compressString("aabcccccaaa"), "a2b1c5a3");
}

TEST_F(ArrayStringTest, RotateImg) {
    const int side = 4;

    unsigned char **img = new unsigned char*[4];
    unsigned char **expect = new unsigned char*[4];
    for (int i = 0; i< 4; i++) {
        img[i] = new unsigned char[4];
        expect[i] = new unsigned char[4];
    }

    unsigned char img_data [4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    unsigned char expect_data [4][4] = {
        {13, 9, 5, 1},
        {14, 10, 6, 2},
        {15, 11, 7, 3},
        {16, 12, 8, 4}
    };

    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            img[j][i] = img_data[j][i];
            expect[j][i] = expect_data[j][i];
        }
    }

    CArrayString::rotateImg(img, side);

    for (int j = 0; j < side ; j++) {
        for (int i = 0; i < side; i++) {
            EXPECT_EQ(img[j][i], expect[j][i]);
        }
    }
}

TEST_F(ArrayStringTest, NullRowCol) {
    const int rows = 4;
    const int cols = 3;
    int **img = new int*[rows];
    int **expect = new int*[rows];
    for (int i = 0; i < rows; i++) {
        img[i] = new int[rows];
        expect[i] = new int[rows];
    }

    int img_data[rows][cols] = {
        {1, 2, 3},
        {5, 6, 7},
        {0, 10, 11},
        {13, 14, 15}
    };

    int expect_data[rows][cols] = {
        {0, 2, 3},
        {0, 6, 7},
        {0, 0, 0},
        {0, 14, 15}
    };

    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < cols; i++) {
            img[j][i] = img_data[j][i];
            expect[j][i] = expect_data[j][i];
        }
    }

    CArrayString::setNullRowCol(img, rows, cols);

    for (int j = 0; j < rows ; j++) {
        for (int i = 0; i < cols; i++) {
            EXPECT_EQ(img[j][i], expect[j][i]);
        }
    }
}

TEST_F(ArrayStringTest, str2RotatedFromStr1) {
    EXPECT_EQ(CArrayString::isStringRotatedFromAnother("waterbottle", "erbottlewat"), true);
}

TEST_F(ArrayStringTest, str2RotatedFromStr1Negative) {
    EXPECT_EQ(CArrayString::isStringRotatedFromAnother("testwaterbottle", "erbottlewat"), false);
}