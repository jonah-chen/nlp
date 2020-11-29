#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <map>
#include <vector>
#include <unordered_set>

#include "dir.h"
#include "words.h"
using namespace std;
using namespace words;

struct sentence
{
    int length; // number of words in the sentence
    string *words; // words: all lower case, no punctuation
    char end_punctuation; // '.', '!', '?', etc.
    pair<size_t, char> punctuation; // pairs (pos, punctuation). 
    // i.e. The sentence: "I eat dog, you eat dog." will have punctuation (2, ',')
};


int main()
{
    freq freqs = get_freq();
    vector<pair<int,string>> ordered_freq = order_freq(freqs);

    while (1)
    {
        cout << "rank: \n";
        int x;
        cin >> x;
        cout << ordered_freq[x].first << ":"<< ordered_freq[x].second << "\n";
    }
    return 0;
}
