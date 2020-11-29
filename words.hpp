#pragma once
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <fstream>
#include <iostream>

#include "dir.h"

using namespace std;

namespace words
{
    /* The freq struct to count frequencies of words */
    struct freq
    {
        unordered_map<string, int> counts;
        long long total;
    };
    
    /* Processes a continuous string to a potentially multiple strings that satisfies the following conditions
     * 1. All words are single words
     * 2. All words are all lowercase
     * 3. All words have no punctuation at the begining or end. Hyphens and apostrophes are allowed.
     */
    vector<string> process_word(string word)
    {
        vector<string> p;
        // Convert the word to all lowercase
        transform(word.begin(), word.end(), word.begin(),[](unsigned char c){return tolower(c);});

        // Purge punctuation
        while (word.length() > 0 && (word.back() < 'a' || word.back() > 'z'))
            word.pop_back();
        while (word.length() > 0 && (word.front() < 'a' || word.front() > 'z'))
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
            while (p[i].length() > 0 && (p[i].back() < 'a' || p[i].back() > 'z'))
                p[i].pop_back();
            while (p[i].length() > 0 && (p[i].front() < 'a' || p[i].front() > 'z'))
                p[i].erase(0);
            if (p[i].length() == 0)
                p.erase(p.begin()+i);
        }
        return p;
    }

    string purge_punctuation(string word)
    {
        while (word.back() < 'a' || word.back() > 'z')
            word.pop_back();
            return purge_punctuation(word);
        while (word.front() < 'a' || word.front() > 'z')
            word.erase(0);
        return word;
    }

    /* converts a string word to all lowercase */
    string tolowercase(string word)
    {
        transform(word.begin(), word.end(), word.begin(),[](unsigned char c){return tolower(c);});
        return word;
    }

    /* gets the frequencies of the words with keys as words and values as frequencies */
    freq get_freq(int start = 0, int end = ARTICLES, bool verbose = false)
    {
        unordered_map<string, int> counts;
        string s;
        ifstream file;
        long long words = 0;
        
        for (const char* dir:DIRS)
        {
            // verbose statement printing out how many words
            if (verbose)
                cout << words << " words," << counts.size() << " unique words\n";

            file.open(dir);
            if (file.is_open())
            {
                while (file >> s)
                {
                    vector<string> p = process_word(s);

                    for (string word:p)
                    {
                        words++;
                        if (counts.find(word) == counts.end())
                            counts[word] = 1;
                        else
                            counts[word]++;
                    }
                }
                file.close();
            }
        }
        return {counts, words};
    }

    /* compares pairs to sort from smallest to largest */
    bool sort_function (pair<int, string> i, pair<int, string> j) {return i.first > j.first;}

    /* returns a sorted vector from the most to least frequently used word in word_frequencies */
    vector<pair<int, string>> order_freq(freq word_frequencies)
    {
        vector<pair<int,string>> ordered_freq;
        for (auto& it:word_frequencies.counts)
            ordered_freq.push_back({it.second, it.first});
        sort(ordered_freq.begin(), ordered_freq.end(), sort_function);
        return ordered_freq;
    }
}