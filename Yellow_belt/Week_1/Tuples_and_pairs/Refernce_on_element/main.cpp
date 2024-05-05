#include <iostream>
#include <map>

using namespace std;

template <class Key, class Value>
Value& GetRefStrict(map<Key, Value>& m, Key k) {
    if (m.count(k) == 0) {
        throw runtime_error("No element by key " + to_string(k));
    }
    return m[k];
}

//template<typename KeyType, typename ValueType>
//ValueType& GetRefStrict(map<KeyType, ValueType>& input_map, KeyType key) {
//    if (input_map.count(key) == 0) {
//        throw runtime_error("no such key in dictionary");
//    }
//    return input_map[key];
//}

int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    return 0;
}
