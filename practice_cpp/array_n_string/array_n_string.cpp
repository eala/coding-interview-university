#include <unordered_set>
#include <vector>
#include "array_n_string.h"

using namespace std;

#define ONLY_ASCII 1
bool CArrayString::isAllCharUnique(const string str) {
#if ONLY_ASCII
    const int CHAR_COUNT = 128;
    // early return, if string only contains ASCI codes, but longer than 128, there must duplicate chars
    if (str.length() > CHAR_COUNT) return false;

    int charMap[CHAR_COUNT] = {0};
    for (int i = 0; i < str.length(); i++) {
        // 'A': 65, 'a': 97, starts from Capital A
        if (charMap[str[i] - 'A']) return false;
        else
        {
            charMap[str[i] - 'A'] = 1;
        }
    }
    return true;
#else
    // use unordered_map as hash table, check if char already exists
    unordered_set<char> hash;

    for (int i = 0; i < str.length(); i++) {
        if (hash.end() != hash.find(str[i])) {
            return false;
        } else {
            hash.insert(str[i]);
        }
    }

    return true;
#endif
}

bool CArrayString::isStringsHaveSameCombinationChar(string a, string b) {
    unordered_set<char> hash;

    if (a.length() != b.length()) return false;

    for (int i = 0; i < a.length(); i++) {
        hash.insert(a[i]);
    }

    unordered_set<char>::iterator it;
    for (int i = 0; i < b.length(); i++) {
        it = hash.find(b[i]);

        if (it != hash.end())
            hash.erase(it);
        else
            return false;
    }

    return (hash.size() == 0);
}

string CArrayString::replaceEmptyString(string str, int realLength) {
    if (str.length() == realLength) return str;

    int idx = str.length() - 1;
    str[idx] = '\0';

    for (int i = realLength - 1; i > 0; i--){
        if (str[i] == ' ') {
            str[idx--] = '0';
            str[idx--] = '2';
            str[idx--] = '%';
        } else {
            str[idx--] = str[i];
        }
    }

    return str;
}

bool CArrayString::isPalindromePermutation(string str) {
    // assume it is ASCII
    int charCount[128] = {0};
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') continue;
        int idx = str[i] - 'A';
        assert (idx >= 0 && idx <= 128);
        if (charCount[idx] > 0) {
            charCount[idx]--;
        } else {
            charCount[idx]++;
        }
    }

    int sum = 0;
    for (int i = 0; i < 128; i++) {
        sum += charCount[i];
        if (sum > 1) return false;
    }
    return true;
}

static bool isOneMoreChar(string longStr, string shortStr) {
    bool foundDiff = false;
    char *pLong = &longStr[0];
    char *pShort = &shortStr[0];
    for (int i = 0; i < shortStr.length(); i++) {
        if (*pLong != *pShort){
            if (foundDiff) return false;
            pLong++;
            foundDiff = true;
        }
        pLong++;
        pShort++;
    }
    return true;
}

bool CArrayString::isOneEditDistance(string str1, string str2) {
    bool oneEdited = false;
    // replace
    if (str1.length() == str2.length()) {
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) {
                if (oneEdited) return false;
                oneEdited = true;
            }
        }
        return true;
    } else if (str1.length() - str2.length() == 1) {
        return isOneMoreChar(str1, str2);
    } else if (str2.length() - str1.length() == 1) {
        return isOneMoreChar(str2, str1);
    }
    return false;
}

string CArrayString::compressString(string str) {
    string compressStr;
    int count = 1;
    int idx = 0;
    for (int i = 1; i < str.length(); i++){
        if (str[i] == str[idx]) {
            count++;
        } else {
            compressStr += str[idx];
            compressStr += to_string(count);
            count = 1;
            idx = i;
        }

        if (i == str.length() - 1) {
            compressStr += str[idx];
            compressStr += to_string(count);
        }

    }
    if (str.length() <= compressStr.length())
        return str;
    return compressStr;
}

void CArrayString::rotateImg(unsigned char **img, int side) {
    for (int layer = 0; layer < side / 2; layer++) {
        for (int start = layer; start < side - 1 - layer; start++) {
            unsigned char tmp = img[layer][start];
            img[layer][start] = img[side - 1 - start][layer];
            img[side - 1 - start][layer] = img[side - 1 - layer][side - 1 - start];
            img[side - 1 - layer][side - 1 - start] = img[start][side - 1 - layer];
            img[start][side - 1 - layer] = tmp;
        }
    }
}

void CArrayString::setNullRowCol(int **img, int rows, int cols) {
    vector<int> cols_set;
    vector<int> rows_set;

    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < cols; i++) {
            if (img[j][i] == 0) {
                cols_set.push_back(i);
                rows_set.push_back(j);
            }
        }
    }

    for (int i = 0; i < cols_set.size(); i++) {
        for (int j = 0; j < rows; j++) {
            img[j][cols_set[i]] = 0;
        }
    }

    for (int i = 0; i < rows_set.size(); i++) {
        for (int j = 0; j < cols; j++) {
            img[rows_set[i]][j] = 0;
        }
    }
}

static bool isSubString(string str1, string str2) {
    return std::string::npos != str1.find(str2);
}

bool CArrayString::isStringRotatedFromAnother(string s1, string s2) {
    return isSubString(s1 + s1, s2);
}
