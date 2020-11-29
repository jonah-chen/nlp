#pragma once
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

#define A 'a'
#define Z 'z'
using namespace std;

namespace nlp
{
    struct pwords
    {
        int count;
        string *words;
    };

    struct sentence
    {
        int length; // number of words in the sentence
        string *words; // words: all lower case, no punctuation
        char end_punctuation; // '.', '!', '?', etc.
        pair<size_t, char> punctuation; // pairs (pos, punctuation). 
        // i.e. The sentence: "I eat dog, you eat dog." will have punctuation (2, ',')
    };

    vector<string> processWord(string word)
    {
        vector<string> p;
        // Convert the word to all lowercase
        transform(word.begin(), word.end(), word.begin(),[](unsigned char c){return tolower(c);});

        // Purge punctuation
        while (word.length() > 0 && (word.back() < A || word.back() > Z))
            word.pop_back();
        while (word.length() > 0 && (word.front() < A || word.front() > Z))
            word.erase(0);
        if (word.length() == 0)
            return p;

        // Split strings with EM-dash to multiple words
        size_t emline = word.find("--");
        while (emline != string::npos)
        {
            p.push_back(word.substr(0, emline));
            word = word.substr(emline+2);
            emline = word.find("--");
        }
        p.push_back(word);

        // Purge punctuation again
        for (int i = 0; i < p.size(); i++)
        {
            while (p[i].length() > 0 && (p[i].back() < A || p[i].back() > Z))
                p[i].pop_back();
            while (p[i].length() > 0 && (p[i].front() < A || p[i].front() > Z))
                p[i].erase(0);
            if (p[i].length() == 0)
                p.erase(p.begin()+i);
        }
        return p;
    }

    string purgePunctuation(string word)
    {
        while (word.back() < A || word.back() > Z)
            word.pop_back();
            return purgePunctuation(word);
        while (word.front() < A || word.front() > Z)
            word.erase(0);
        return word;
    }

    string tolowercase(string word)
    {
        transform(word.begin(), word.end(), word.begin(),[](unsigned char c){return tolower(c);});
        return word;
    }
}