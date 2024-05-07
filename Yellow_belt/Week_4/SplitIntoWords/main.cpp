#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> words;
    auto left = s.begin();
    auto right = s.begin();
    while (right != s.end()) {
        left = right;
        right = find(left, end(s), ' ');
        words.push_back({left, right});
        if (right != s.end()) {
            right++;
        }
    }
    return words;

}

int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;
    return 0;
}
