#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>

using namespace std;

// шаблонный оператор умножения для пар
template <typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1,
                                const pair<First, Second>& p2) {
    // можно создвать переменные шаблонного типа внутри
    First f = p1.first * p2.first;
    Second s = p2.second * p2.second;
    return make_pair(f, s);
}
// Обяъвление шаблонного типа
template <typename T>
T Sqr(T x) {
    return x*x;
}

template <typename First, typename Second>
ostream& operator << (ostream& out, const pair<First, Second>& p);

template <typename T>
ostream& operator << (ostream& out, const vector<T>& vi);

template <typename Key, typename Value>
ostream& operator << (ostream& out, const map<Key, Value>& m);

template <typename First, typename Second>
ostream& operator << (ostream& out, const pair<First, Second>& p) {
    return out << '(' << p.first << ", " << p.second << ')';
}

template <typename Collection>
string Join(const Collection& c, const string& d) {
    stringstream ss;
    bool first = true;
    for (const auto& i : c) {
        if (!first) {
            ss << d;
        }
        first = false;
        ss << i;
    }
    return ss.str();
}

template <typename T>
ostream& operator << (ostream& out, const vector<T>& vi) {
    return out << '[' << Join(vi, ", ") << ']';
}

template <typename Key, typename Value>
ostream& operator << (ostream& out, const map<Key, Value>& m) {
    return out << '{' << Join(m, ", ") << '}';
}


template <typename T>
T Max(T a, T b) {
    if (a > b) return a;
    return b;
}

int main() {
    {
        auto p = make_pair(2, 3.3);
        double pi = 3.14;
        float e = 2.71;
        cout << Sqr(pi) << " ";
        cout << Sqr(e) << " ";
        cout << Sqr(2) << "\n";
        auto res = Sqr(p);
        cout << res.first << " " << res.second << "\n\n";
    }
    {
        cout << "vector input:\n";
        vector<int> vi = {1, 5, 3};
        cout << vi << "\n";
        vector<double> vd = {3.5, 7.1, 11};
        cout << vd << "\n";
        vector<vector<int>> vvi = {{1, 5}, {4, 9, -11}, {27}, {}};
        cout << vvi << "\n";
    }
    {
        cout << "map input:\n";
        map<int, int> mi = {
                {1, 11}, {3, 31}, {7, 71}
        };
        cout << mi << "\n";
    }
    {
        cout << Max(2, 3) << " ";
//        Max(2, 3.5); - компилятор не знает какой тип использовать для шаблонных параметров
        cout << Max<int>(2, 3.5) << " "; // явно указываем, к какому типу приводить шаблонные параматеры
        cout << Max<double>(2, 3.5) << "\n";
        cout << max<double>(2, 3.5) << "\n"; // встроенная функция работает также
    }
    {
        // Объявление шаблонной функции
        // template <typename T> T Foo(T var) {...};
        // Вместо typename можно писать class
        // template <class T> T Foo(T var) {...};
    }
    return 0;
}
