#include <iostream>

using namespace std;

class CArrayString {
    public:
        static bool isAllCharUnique(const string str);
        static bool isStringsHaveSameCombinationChar(string a, string b);
        static string replaceEmptyString(string str, int replacedLength);
        static bool isPalindromePermutation(string str);
        static bool isOneEditDistance(string str1, string str2);
        static string compressString(string str);
        static void rotateImg(unsigned char **img, int side);
        static void setNullRowCol(int **img, int rows, int cols);
        static bool isStringRotatedFromAnother(string s1, string s2);
};