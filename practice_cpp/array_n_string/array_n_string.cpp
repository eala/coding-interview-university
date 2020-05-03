#include <unordered_set>
#include "array_n_string.h"

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
    if (realLength == 0) return "";

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
