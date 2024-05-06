#pragma once

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <sstream>

using namespace std;
template <class T>
ostream& operator<< (ostream& os, const set<T> s) {
    os << "{";
    bool first = true;
    for (const auto& el : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << el;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator<< (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& [k, v] : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << k << ": " << v;
    }
    return os << "}";
}

template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u
           << " Hint: " << hint;
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string &test_name) {
        try {
            func();
            cerr << test_name << " OK\n";

        } catch (const runtime_error &re) {
            ++fail_count;
            cerr << test_name << " fail: " << re.what() << "\n";
        }
    }
    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " tests failed. Terminate";
            exit(1); // завершить программу с кодом возврата 1
        }
    }
private:
    int fail_count = 0;
};
