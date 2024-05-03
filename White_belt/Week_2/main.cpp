#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <map>
using namespace std;
using namespace std::chrono;
// Факториал
/*
int Factorial(int n) {
    int product = 1;
    while (n > 0) {
        product = product * n;
        --n;
    }
    return product;
}

int main() {
    cout << Factorial(5);
    return 0;
}
*/

// Палиндром
/*
bool IsPalindrome(string s) {
    for (int i=0; i < s.size()/2; ++i) {
        if (s[i] != s[s.size()-1-i])
            return false;
    }
    return true;
}
int main() {
    string s;
    cin >> s;
    cout << IsPalindrome(s);

    return 0;
}
*/
/*
vector<string> PalindromeFilter(vector<string> words, int min_length) {
    vector <string> ans;
    for (auto i : words) {
        if (i.size() >= min_length && IsPalindrome(i))
            ans.push_back(i);
    }
    return ans;
}

int main() {
    int n, minlength;
    cin >> n >> minlength;
    vector<string> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
    }
    vector<string> ans = PalindromeFilter(v, minlength);
    for (auto el: ans)
        cout << el << " ";
    return 0;
}*/

// Максимизатор
/*
void UpdateIfGreater(int first, int& second) {
    if (first > second)
        second = first;
}

int main() {
    int a, b;
    cin >> a >> b;
    UpdateIfGreater(a, b);
    cout << a << ' ' << b;
    return 0;
}
 */

// Перемещение строк
/*
void MoveStrings(string& source, string& destination) {
    for (auto i : source) {
        destination.push_back(i);
    }
    source.clear();
}

void PrintString(const string& s) {
    for (auto i : s) {
        cout << i;
    }
    cout << "\n";
}

int main() {
    string src, dest;
    cin >> src >> dest;
    MoveStrings(src, dest);
    PrintString(src);
    PrintString(dest);
    return 0;
}
 */

// GetMoscowPopulation
/*
struct Person {
    string name;
    string surname;
    int age=0;
};

vector<Person> GetMoscowPopulation() {
    vector<Person> v(12000000);
    return v;
}

void PrintPopualtionSize(const vector<Person>& p) {
    cout << "There are " << p.size() << " people in Moscow"
    << endl;
}
int main() {
        auto start = steady_clock::now();
    auto v = GetMoscowPopulation();
    auto finish = steady_clock::now();
    cout << "GetMoscowPopulation: "
         <<duration_cast<milliseconds>(finish - start).count()
         << "ms\n";


    auto start2 = steady_clock::now();
    PrintPopualtionSize(v);
    auto finish2 = steady_clock::now();
    cout << "PrintPopualtionSize: "
    <<duration_cast<milliseconds>(finish2 - start2).count()
    << "ms\n";
    return 0;
}
*/
// Разворот последовательности
/*
void Reverse(vector<int>& v) {
    for (int i=0; i < v.size()/2; ++i) {
        int tmp = v[i];
        v[i] = v[v.size()-1-i];
        v[v.size()-1-i] = tmp;
    }
}

int main() {
    vector<int> v={2, 1, 5, 11, 7};
    Reverse(v);
    for (auto i : v) {
        cout << i << " ";
    }
    return 0;
}
*/

// Разворот последовательности - 2
/*
vector<int> Reversed(const vector<int>& v) {
    vector<int> ans(v.size());
    for (int i=0; i < v.size(); ++i) {
        ans[i] = v[v.size()-1-i];
    }
    return ans;
}

int main() {
    vector<int> vv = {5, 3, 1, 7, 13};
    vector<int> rev_vv = Reversed(vv);
    for (auto i : rev_vv) {
        cout << i << " ";
    }
    return 0;
}
*/

// Средняя температура
/*
int main() {
    vector<float> temp = {15, -30, -   4, 15, -11, 7};
    float avg = 0;
    float sum = 0;
    int n = temp.size();
    for (auto t : temp) {
        sum += t;
    }
    avg = sum / n;
    cout << "Averrage temp: " << avg << endl;
    vector<float> greater_then_avg;
    for (auto t : temp) {
        if (t > avg)
            greater_then_avg.push_back(t);
    }
    for (auto el : greater_then_avg)
        cout << el << " ";
    return 0;
}
*/
/*
 void PrintVector(const vector<bool>& v) {
     for (int i=0; i<v.size(); ++i) {
         cout << i << ": " << v[i] << "\n";
     }
 }
 */
// Очередь
/*
int main() {
    vector<bool> is_worry;
    int worry_cnt = 0;
    int q;
    cin >> q;
    for (int i=0; i<q; ++i) {
        string command;
        cin >> command;
        if (command == "COME") {
            int k;
            cin >> k;
            is_worry.resize(is_worry.size()+k);
        }
        else if (command == "WORRY") {
            int num;
            cin >> num;
            is_worry[num] = true;
            ++worry_cnt;
        } else if (command == "QUITE") {
            int num;
            cin >> num;
            is_worry[num] = false;
            --worry_cnt;
        }
        else if (command == "WORRY_COUNT") {
            cout << "worry_cnt:" <<worry_cnt << "\n";
        }
        cout << "is_worry:\n";
        PrintVector(is_worry);
    }

    is_worry.resize(5);
    cout << "resize 5 \n";
    PrintVector(is_worry);
    cout << "assign 3 true\n";
    is_worry.assign(3, true);
    PrintVector(is_worry);
    return 0;
}*/
/*
10
COME 7
COME 2
COME -1
WORRY 5
WORRY 2
WORRY_COUNT
QUITE 5
COME 6
COME -7
WORRY_COUNT*/
/*
int main() {
    vector<int> month_length = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int current_month = 0;
    vector<vector<string>> dela(month_length[current_month]);
    int q = 0;
    cin >> q;
    for (int i=0; i<q; ++i) {
        string cmd;
        cin >> cmd;
            if (cmd == "ADD") {
                int day;
                string delo;
                cin >> day >> delo;
                dela[day-1].push_back(delo);
            }
            else if (cmd == "DUMP") {
                int day;
                cin >> day;
                cout <<dela[day-1].size() << " ";
                for (int i=0; i<dela[day-1].size(); ++i) {
                    cout << dela[day-1][i] << " ";
                }
                cout << "\n";
            }
            else if (cmd == "NEXT") {
                int next_month_length = month_length[(current_month+1) % 12];
                if (next_month_length < month_length[current_month]) {
                    int diff = month_length[current_month] - next_month_length;
                    for (int i=0; i<= diff; ++i) {
                        for ( auto el : dela[next_month_length+i-1])
                            dela[next_month_length-1].push_back(el);
                    }
                }
                dela.resize(next_month_length);
                ++current_month;
            }

        for (int i=0; i<dela.size(); ++i) {
            cout << i << ": ";
            for (auto el: dela[i])
                cout << el << " ";
            cout << "\n";
        }

    }
    return 0;
}
*/
/*
12
ADD 5 Salary
ADD 31 Walk
ADD 30 WalkPreparations
NEXT
DUMP 5
DUMP 28
NEXT
DUMP 31
DUMP 30
DUMP 28
ADD 28 Payment
DUMP 28
*/


// Анаграммы
/*
map<char, int> BuildCharCounters(const string& s) {
    map<char, int> counter;
    for (const char& ch : s) {
        ++counter[ch];
    }
    return counter;
}
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        string left, right;
        cin >> left >> right;
        if (BuildCharCounters(left) == BuildCharCounters(right))
            cout << "YES" << "\n";
        else
            cout << "NO\n";

    }

    return 0;
}
*/

// Справочник столиц
/*
int main() {
    map<string, string> country_to_capital;
    int q;
    cin >> q;
    for (int i=0; i<q; ++i){
        string cmd;
        cin >> cmd;
        if (cmd == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            if (country_to_capital.count(country) == 0) {
                country_to_capital[country] = new_capital;
                cout << "Introduce new country " << country << " with capital " << new_capital << "\n";
            }
            else if (country_to_capital[country] == new_capital)
                cout << "Country " << country << " hasn't changed its capital\n";
            else {
                string old_capital = country_to_capital[country];
                country_to_capital[country] = new_capital;
                cout << "Country " << country << " has changed its capital from "
                << old_capital << " to " << new_capital << "\n";
            }
        }
        else if (cmd == "RENAME") {
            string old_country_name, new_country_name;
            if (old_country_name == new_country_name ||
            country_to_capital.count(old_country_name) == 0 ||
            country_to_capital.count(new_country_name) == 1
            )
                cout << "Incorrect rename, skip\n";
            else {
                country_to_capital[old_country_name] = new_country_name;
                cout << "Country " << old_country_name << " with capital "
                << country_to_capital[new_country_name] << " has been renamed to "  <<new_country_name << "\n";
            }
        }
        else if (cmd == "ABOUT") {
            string country;
            cin >> country;
            if (country_to_capital.count(country) == 0)
                cout << "Country " << country << " doesn't exist\n";
            else {
                cout << "Country " << country << " has capital " << country_to_capital[country] << "\n";
            }

        }
        else if (cmd == "DUMP") {
            if (country_to_capital.empty())
                cout << "There are no countries in the world\n";
            else {
                for (auto [country, capital] : country_to_capital) {
                    cout << country << ": " << capital << "\n";
                }
            }
        }
    }

    return 0;
}
*/
/*
6
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME RussianEmpire RussianRepublic
ABOUT RussianRepublic
RENAME RussianRepublic USSR
CHANGE_CAPITAL USSR Moscow
DUMP
 */

// Автобусные остановки-1
int main() {
    map<string, vector<string>> stop_to_buses;
    map<string, vector<string>> bus_to_stops;
    int q;
    cin >> q;
    for (int i=0; i<q; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "NEW_BUS") {
            string bus;
            cin >> bus;
            int stop_count;
            cin >> stop_count;
            for (int i=0; i < stop_count; ++i) {
                string stop;
                cin >> stop;
                bus_to_stops[bus].push_back(stop);
                stop_to_buses[stop].push_back(bus);
            }
        }
        else if (cmd == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            if (stop_to_buses.count(stop) == 0)
                cout << "No stop\n";
            else {
                for (auto bus: stop_to_buses[stop]) {
                    cout << bus << " ";
                }
                cout << "\n";
            }
        }
        else if (cmd == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            if (bus_to_stops.count(bus) == 0) {
                cout << "No bus\n";
            }
            else {
                for (const string& stop : bus_to_stops[bus]) {
                    cout << "Stop " << stop << ": ";
                    if (stop_to_buses[stop].size() == 1)
                        cout << "no interchange";
                    else {
                        for (const string& b : stop_to_buses[stop]) {
                            if (b != bus)
                                cout << b << " ";
                        }
                    }
                    cout << "\n";
                }
            }
        }
        else if (cmd == "ALL_BUSES") {
            if (bus_to_stops.empty())
                cout << "No buses\n";
            else {
                for (const auto& [bus, stops] : bus_to_stops) {
                    cout << "Bus " << bus << ": ";
                    for (const string& stop : bus_to_stops[bus]) {
                        cout << stop << " ";
                    }
                    cout << "\n";
                }
            }
        }

    }

    return 0;
}

/*
10
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
ALL_BUSES
 */