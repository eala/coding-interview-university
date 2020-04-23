#include <unordered_set>
#include "array_n_string.h"

bool CArrayString::isAllCharUnique(const string str) {
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
}

bool CArrayString::isStringsHaveSameCombinationChar(string a, string b) {
    unordered_set<char> hash;

    if (a.length() != b.length()) return false;

    for (int i = 0; i < a.length(); i++) {
        hash.insert(a[i]);
    }

    unordered_set<char>::iterator *it;
    for (int i = 0; i < b.length(); i++) {
        it = hash.find(b[i]);
        if (it != hash.end())
            hash.erase(it);
        else
            return false;
    }

    return (hash.size() == 0);
}
