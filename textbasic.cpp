#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

#include "dir.h"
#include "basicops.h"
using namespace std;
using namespace nlp;

int main()
{
    unordered_map<string, int> counts;
    string s;
    ifstream file;
    long long words = 0;
    
    for (const char* dir:DIRS)
    {
        cout << words << " words," << counts.size() << " unique words\n";
        file.open(dir);
        if (file.is_open())
        {
            while (file >> s)
            {
                vector<string> p = processWord(s);

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
    while (1)
    {
        cout << "Enter valid word (lowercase): ";
        string input;
        cin >> input;
        cout << counts[input] << " corresponding to " << 100.0*(float)counts[input]/(float)words << "\% of all words\n";
    }
    return 0;
}
