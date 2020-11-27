#pragma once
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cctype>

#define A 'a'
#define Z 'z'
using namespace std;
string processWord(string word)
{
    transform(word.begin(), word.end(), word.begin(),[](unsigned char c){return tolower(c);});
    if (word.back() < A || word.back() > Z)
        word.pop_back();
    if (word.front() < A || word.front() > Z)
        word.erase(0);
    return word;
}

string tolowercase(string word)
{
    transform(word.begin(), word.end(), word.begin(),[](unsigned char c){return tolower(c);});
    return word;
}