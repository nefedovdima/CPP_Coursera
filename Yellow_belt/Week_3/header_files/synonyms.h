#pragma once

using namespace std;
#include <string>
#include <map>
#include <set>

using Synonyms = map<string, set<string>>;

void AddSynonyms(Synonyms& word_to_syn,
                 const string& first_word,
                 const string& second_word) {
    word_to_syn[first_word].insert(second_word);
    word_to_syn[second_word].insert(first_word);
}

size_t GetSynonymCount(const Synonyms& word_to_syn,
                       const string& word) {
    if (word_to_syn.count(word) == 0) {
        return 0;
    }
    return word_to_syn.at(word).size();
}

bool AreSynonyms(Synonyms& word_to_syn,
                 const string& first_word,
                 const string& second_word) {
    return word_to_syn[first_word].count(second_word);
}
