#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

void EnsureNextSymbolAndSkip(stringstream& stream) {
    if (stream.peek() != '/') {
        stringstream ss;
        ss << "expected /, but has: " << stream.peek();
        throw runtime_error(ss.str());
        // ss.str - возвращает из потока строчку, которая в нем записана
    }
    stream.ignore(1);
}

Date ParseDate(const string& s) {
    stringstream stream(s);
//    stream.peek() - посмотреть какой следующий символ в потоке
    Date date;
    stream >> date.year;
    EnsureNextSymbolAndSkip(stream);
    stream >> date.month;
    EnsureNextSymbolAndSkip(stream);
    stream >> date.day;
    return date;
}

void EnsureEqual(const string& left, const string& right) {
    if (left != right) {
        stringstream ss;
        ss << left << " != " << right;
        throw runtime_error(ss.str());
    }
}

class Rational {
public:
    Rational() {
        num = 0;
        denom = 1;
    }
    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Denom is zero");
        }
        num = numerator;
        denom = denominator;
        Normalize();
    }
    int Numerator() const {
        return num;
    }
    int Denominator() const {
        return denom;
    }
private:
    int num;
    int denom;
    void Normalize() {
        int gcdiv = std::gcd(num, denom);
        num = num / gcdiv;
        denom = denom / gcdiv;
        if (denom < 0) {
            num = -num;
            denom = -denom;
        }
    }
};

Rational operator / (const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Division on zero-numerator ratio");
    } else {
        return {lhs.Numerator() * rhs.Denominator(),
                        lhs.Denominator() * rhs.Numerator()};
    }
}

int main() {
    string date_str = "2017a01/25";
    try {
        Date date = ParseDate(date_str);
        cout << setw(2) << setfill('0')
             << date.day << "."
             << setw(2) << setfill('0')
             << date.month << "."
             << date.year;
    } catch (exception& ex) {
        cout << ex.what();
    }
    // stream.peek() == ? проверить что следующий символ = ?
    // throw exception() - бросить исключение
    //  try {} catch {}
    cout << "\n";
    try {
        EnsureEqual("C++ White", "C++ White");
        EnsureEqual("C++ White", "C++ Yellow");
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument& ex) {
        cout << ex.what() << "\n";
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error& ex) {
        cout << ex.what() << "\n";
    }

    cout << "OK" << endl;
    return 0;
}
