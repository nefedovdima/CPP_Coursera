#include <fstream>

#include "tests.h"
#include "synonyms.h"


void solve() {
    ifstream in("input.txt");
    if (in.is_open()) {
        int q;
        in >> q;
        Synonyms word_to_syn;
        for (int i = 0; i < q; ++i) {
            string request;
            in >> request;
            if (request == "ADD") {
                string word1, word2;
                in >> word1 >> word2;
                AddSynonyms(word_to_syn, word1, word2);
            } else if (request == "COUNT") {
                string word;
                in >> word;
                cout << GetSynonymCount(word_to_syn, word) << "\n";
            } else if (request == "CHECK") {
                string word1, word2;
                in >> word1 >> word2;
                if (AreSynonyms(word_to_syn, word1, word2)) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    } else {
        cerr << "input.txt doesn't open\n";
    }
}

int main() {
    Test();
    solve();
    return 0;
}
