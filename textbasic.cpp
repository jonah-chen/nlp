#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

#include "dir.h"
#include "basicops.h"
using namespace std;

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
                words++;
                s = processWord(s);
                if (counts.find(s) == counts.end())
                    counts[s] = 1;
                else
                    counts[s]++;
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
