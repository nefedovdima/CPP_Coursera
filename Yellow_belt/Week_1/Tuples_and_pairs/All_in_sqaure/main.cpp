#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

template <typename T>
T Sqr(T el);

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p);

template <typename T>
vector<T> Sqr(const vector<T>& v);

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& m);

template <typename T>
T Sqr(T el) {
    return el * el;
}

template <typename First, typename Second>
pair<First, Second> Sqr(const pair<First, Second>& p) {
    return {p.first * p.first, p.second * p.second};
}

template <typename T>
vector<T> Sqr(const vector<T>& v) {
    vector<T> vec_sqr(v.size());
    for (auto i=0; i < v.size(); ++i) {
        vec_sqr[i] = Sqr(v[i]);
    }
    return vec_sqr;
}

template <typename Key, typename Value>
map<Key, Value> Sqr(const map<Key, Value>& m) {
    map<Key, Value> map_sqr;
    for (auto [k, v] : m) {
        map_sqr[k] = Sqr(v);
    }
    return map_sqr;
}
int main() {
    // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}
