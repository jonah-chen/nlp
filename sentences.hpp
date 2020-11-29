#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class Sentence
{
    public:
        Sentence(int length, string *words, char end_punctuation, map<size_t, char> punctuation)
        {
            l = length;
            w = words;
            ep = end_punctuation;
            p = punctuation;
        }
        Sentence(string sentence)
        {
            if (!constructable(sentence))
            {
                cout << "An exception occured. The sentence \"" << sentence << "\" is not a valid sentence." << endl;
                throw -1;
            }
            //TODO: write a way to construct the class variables from a string sentence

        }
        /* The constraint for a valid sentence. max_length is the maximum number of characters where a value of 0 means no limit. */
        static bool constructable(string sentence, int max_length = 0)
        {
            return true;
            //TODO: generate the criteria for a valid sentence.
        }
        /* The getter methods for the private members */
        int length() {return l;}
        string *words() {return w;}
        string words(int pos) {return w[pos];}
        char end_punctuation() {return ep;}
        map<size_t, char> punctuation() {return p;}
        char punctuation(size_t pos) {return p.find(pos) == p.end() ? ' ' : p[pos]; /* space means no punctuation lmao */}      

    private:
        int l; // number of words in the sentence
        string *w; // words: all lower case, no punctuation
        char ep; // '.', '!', '?', etc.
        map<size_t, char> p; // pairs (pos, punctuation). 
        // i.e. The sentence: "I eat dog, you eat dog." will have punctuation (2, ',')    
};