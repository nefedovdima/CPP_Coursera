#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cassert>

using namespace std;
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

void TestAddSynonyms() {
    {
        Synonyms empty;
        AddSynonyms(empty, "a", "b");
        const Synonyms expected = {
                {"a", {"b"}},
                {"b", {"a"}}
        };
        assert(empty == expected);
    }
    {
        Synonyms synonyms = {
                {"a", {"b"}},
                {"b", {"a", "c"}},
                {"c", {"b"}}
        };
        AddSynonyms(synonyms, "a", "c");
        const Synonyms expected = {
                {"a", {"b", "c"}},
                {"b", {"a", "c"}},
                {"c", {"b", "a"}}
        };
        assert(synonyms == expected);
    }
    cout << "TestAddSynonyms OK\n";
}

void TestSynonymsCount() {
    {
        Synonyms empty;
        assert(GetSynonymCount(empty, "a") == 0);
    }
    {
        Synonyms synonyms = {
                {"a", {"b", "c"}},
                {"b", {"a"}},
                {"c", {"a"}}
        };
        assert(GetSynonymCount(synonyms, "a") == 2);
        assert(GetSynonymCount(synonyms, "b") == 1);
        assert(GetSynonymCount(synonyms, "z") == 0);
    }
    cout << "TestSynonymsCount OK\n";
}

void TestAreSynonyms() {
    {
        Synonyms empty;
        assert(!AreSynonyms(empty, "a", "b"));
        assert(!AreSynonyms(empty, "b", "a"));
        Synonyms synonyms = {
                {"a", {"b", "c"}},
                {"b", {"a"}},
                {"c", {"a"}}
        };
        assert(AreSynonyms(synonyms, "a", "b"));
        assert(AreSynonyms(synonyms, "b", "a"));
        assert(AreSynonyms(synonyms, "a", "c"));
        assert(AreSynonyms(synonyms, "c", "a"));
        assert(!AreSynonyms(synonyms, "b", "c"));
        assert(!AreSynonyms(synonyms, "c", "b"));
    }
    cout << "TestAreSynonyms OK\n";
}

void Test() {
    TestAddSynonyms();
    TestAreSynonyms();
    TestSynonymsCount();
}

void solve() {
    int q;
    cin >> q;
    Synonyms word_to_syn;
    for (int i = 0; i < q; ++i) {
        string request;
        cin >> request;
        if (request == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;
            AddSynonyms(word_to_syn, word1, word2);
        } else if (request == "COUNT") {
            string word;
            cin >> word;
            cout << GetSynonymCount(word_to_syn, word);
        } else if (request == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;
            if (AreSynonyms(word_to_syn, word1, word2)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    Test();
    return 0;
}
