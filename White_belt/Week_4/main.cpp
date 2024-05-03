#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <numeric>
#include <map>
#include <set>

using namespace std;

struct Day {
    int value;
    explicit Day(int new_value) {
        value = new_value;
    }
};

struct Month {
    int value;
    explicit Month(int new_value) {
        value = new_value;
    }
};

struct Year {
    int value;
    explicit Year(int new_value) {
        value = new_value;
    }
};

struct Date {
    int day;
    int month;
    int year;
    Date(Day new_day, Month new_month, Year new_year) {
        day = new_day.value;
        month = new_month.value;
        year = new_year.value;
    }
};

void PrintDate(const Date& date) {
    cout << date.day << "." << date.month << "." << date.year << "\n";
}

struct Specialization {
    string title;
    explicit Specialization(string new_title) {
        title = new_title;
    }
};

struct Course {
    string title;
    explicit Course(string new_title) {
        title = new_title;
    }
};

struct Week {
    string title;
    explicit Week(string new_title) {
        title = new_title;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    LectureTitle(const Specialization& new_specialization,
                 const Course& new_course, const Week& new_week) {
        specialization = new_specialization.title;
        course = new_course.title;
        week = new_week.title;
    }
};

void PrintLectureTitle(const LectureTitle& lec_title) {
    cout << "(" <<lec_title.course
         << ", " << lec_title.specialization
         << ", " << lec_title.week << ")" << "\n";
}

struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

class FunctionPart {
public:
    FunctionPart(char new_operation, double new_value) {
        operation = new_operation;
        value = new_operation;
    }
    double Apply(double source_value) const {
        if (operation == '+') {
            return source_value + value;
        } else {
            return source_value - value;
        }
    }
    void Invert() {
        if (operation == '+') {
            operation = '-';
        } else {
            operation = '+';
        }
    }
private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(char operation, double value) {
        parts.push_back({operation, value});
    }
    double Apply(double value) const {
        for (const FunctionPart& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert() {
        for (FunctionPart& part: parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector<FunctionPart> parts;
};


Function MakeWeightFunction(const Params& params, const Image& image) {
    Function function;
    function.AddPart('+', image.freshness * params.a - params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

// w = q - f*a - b + r*c
// q = w + f*a + b - r*c
double ComputeImageWeight(const Params& params, const Image& image) {
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);

}
double ComputeQualityByWeight(const Params& params,
                              const Image& image, double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}

void ReadAll(const string& path) {
    ifstream input(path); // создание потока для чтения

    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            cout << line << '\n';
        }
    } else {
        cout << "error\n";
    }
}

void PPrint(const vector<string>& names, const vector<double>& values,
            const int width=10, const int precision=3, const bool fixed_manip=false, const char fill=' ', const bool left_manip=false) {
    cout << setfill(fill);
    if (left_manip) {
        cout << left;
    }
    for (const auto& n : names) {
        cout << setw(width) << n;
    }
    cout << endl;
    if (fixed_manip) {
        cout << fixed;
    }
    cout << setprecision(precision);
    for (const auto& v : values) {
        cout << setw(width) << v;
    }
}

struct Student {
    string first_name;
    string last_name;
    int day;
    int month;
    int year;
};

struct Duration {
    int hour;
    int min;
    Duration(int h = 0, int m = 0) {
        int total = h * 60 + m;
        hour = total / 60;
        min = total % 60;
    }
};

Duration ReadDuration(istream& stream) {
    int h = 0;
    int m = 0;
    stream >> h;
    stream.ignore(1);
    stream >> m;
    return Duration {h, m};
}

void PrintDuration(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':'
           << setw(2) << duration.min;
}

ostream& operator<<(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':'
           << setw(2) << duration.min;
    return stream;
}

istream& operator>>(istream& stream, Duration& duration) {
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;
    return stream;
}

Duration operator+(const Duration& lhs, const Duration& rhs) {
    return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

void PrintDursVector(const vector<Duration>& durs) {
    for (const auto& d : durs) {
        cout << d << " ";
    }
    cout << endl;
}

bool operator< (const Duration& lhs, const Duration& rhs) {
    if (lhs.hour == rhs.hour) {
        return lhs.min < rhs.min;
    } else {
        return lhs.hour < rhs.hour;
    }
}

class Rational {
public:
    Rational() {
        num = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
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

bool operator ==(const Rational& lhs, const Rational& rhs) {
    return lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator();
}


// a/b + c/d = a*d + b*c / b*d
Rational operator +(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator()*rhs.Denominator() + rhs.Numerator()*lhs.Denominator(),
                    lhs.Denominator()*rhs.Denominator());
}

Rational operator -(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator()*rhs.Denominator() - rhs.Numerator()*lhs.Denominator(),
                    lhs.Denominator()*rhs.Denominator());
}

Rational operator *(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator /(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

istream& operator>>(istream& is, Rational& ratio) {
    int num = 0;
    int denom = 1;

    char c;
    if (is >> num) {
        if (is >> c) {
            if (c == '/' && is >> denom) {
                ratio = Rational(num, denom);;
            }
        }
    }

    return is;
}

ostream& operator <<(ostream& os, const Rational& ratio) {
    os << ratio.Numerator() << '/' << ratio.Denominator();
    return os;
}

//a/b - a/d =
bool operator <(const Rational& lhs, const Rational rhs) {
    return (lhs - rhs).Numerator() < 0;
}
int main() {
    // Структрура Date
    cout << "Структрура Date\n";
    Date date = {Day{10}, Month{11}, Year{12}};
    // explicit - явный. Запрещено неявное приведение типов
    PrintDate(date);

    // Структура LectureTitle
    cout << "Структура LectureTitle\n";
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th"));
    PrintLectureTitle(title);

    cout << "ComputeImageWeight\n";
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    // w = q - f*a - b + r*c
    // q = w + f*a + b - r*c
    cout << ComputeImageWeight(params, image) << "\n";

    cout << "Работа с потоками ввода-вывода" << endl;
    // Базовые классы для работы с потоками
    //istream - поток ввода (cin)
    // ostream - поток вывода(cout)
    // iostream - запись и чтение

    // Потоки для работы с файлами (наследуются от базовых)
    // #include <fstream>
    // ifsream - (наследник istream) - для чтения
    // ofstream - (наследник ostream) - для записи
    // fstream - запись и чтение (наследник iostream)

    // Оператор ввода >>
    // getline(поток, строка для считанных данных). Возвращает ссылку на поток
    // А поток можно привести к типу bool.
    // getline считывает строку до определенного разделителя.
    // По-умолчанию до '\n' == endl

    ifstream input("hello.txt"); // создание потока для чтения
    string line;
    if (input.is_open()) {
        while (getline(input, line)) {
            cout << line << '\n';
        }
    } else {
        cout << "error\n";
    }

    ifstream input_date("date.txt");
    string year;
    string month;
    string day;

    if (input_date) {
        // считывание до разделителя
        getline(input_date, year, '-');
        getline(input_date, month, '-');
        getline(input_date, day, '-');
    }
    ifstream input_date_int("date_int.txt");
    int year_int;
    int month_int;
    int day_int;

    if (input_date_int) {
        input_date_int >> year_int;
        input_date_int.ignore(1); // пропустить считывание из потока 1-го мивола
        input_date_int >> month_int;
        input_date_int.ignore(1);
        input_date_int >> day_int;
    }
    cout << year_int << "." << month_int << "." << day_int << endl;

    const string path = "output.txt";
    // ofstream output(path, ios::app); // ios::app - ppaned - режим дозаписи
    // output << "world" << endl;
    ReadAll(path);

    cout << "Манипуляторы потоков\n";
    // Манипуляторы потоков

    vector<string> names = {"a", "b", "c"};
    vector<double> values = {5, 0.01, 0.000005};
    PPrint(names, values, 10, 2, true,'.', true);

    // fixed - задать фиксированную точность вывода
    // setw - задать ширину поля ввода (сбрасывается при первом выводе)
    // setprecision(prec) - точность вывода вещественных чисел
    // setfill - заполнитель для setw;
    //left - выравнивание по левому краю

    // Задача.Работа с файлами
    cout << "\nЗадача.Работа с файлами" << endl;
    fstream input_stream("input_.txt");
    ofstream otput_stream("output.txt", ios::app);
    string l;
    //while (getline(input_stream, l)) {
    //    otput_stream << l << endl;
    //}

    // Задача. Вывод с точностью"
    cout << "Задача. Вывод с точностью" << endl;
    ifstream in("in.txt");
    ofstream out("out.txt");
    out << fixed<< setprecision(3);
    double num;
    while (in) {
        in >> num;
        out << num << "\n";
    }
    // Чтение и вывод таблицы
    cout << "Чтение и вывод таблицы" << endl;
    ifstream inp("inp.txt");
    ofstream outp("outp.txt");
    outp << setfill(' ');
    size_t n, m;
    inp >> n >> m;
    int data;
    for (size_t i=0; i < n; ++i) {
        for (size_t j=0; j < m; ++j) {
            inp >> data;
            inp.ignore(1);
            outp << setw(10) << data;
            if (j+1 != m) {
                outp << " ";
            }
        }
        if (i+1 < n) {
            outp << "\n";
        }
    }
    // Список студентов
    {
        cout << "\nСписок студентов\n";
        ifstream input("students_in.txt");

        vector<Student> students;
        int number;
        input >> number;
        for (size_t i; i < number; ++i) {
            string first_name;
            string second_name;
            int birth_day;
            int birth_month;
            int birth_year;
            input >> first_name >> second_name >> birth_day
                  >> birth_month >> birth_year;
            students.push_back({first_name, second_name,
                                birth_day, birth_month, birth_year});
        }
        size_t m;
        input >> m;
        for (size_t j=0; j < m; ++j) {
            string request;
            int no;
            input >> request >> no;
            if (no > number) {
                cout << "bad request\n";
                continue;
            }
            Student student = students[no-1];
            if (request == "name") {
                cout << student.first_name << " " << student.last_name << "\n";
            } else if (request == "date") {
                cout << student.day << "." << student.month << "." << student.year << endl;
            } else {
                cout << "bad request\n";
            }
        }
    }

    // Перегрузка операторов
    cout << "\nПерегрузка операторов\n";
    stringstream dur_ss("01:50");
    Duration duration1 = ReadDuration(dur_ss);
    PrintDuration(cout, duration1);
    cout << endl;
    cout << duration1 << endl;
    // Опертор вывода должен возвращать ссылку на поток, в который он производит запись
    operator<<(operator<<(cout, "hello"), " world!");
    cout << endl;

    stringstream dur_sstream("11:35");
    Duration dur1 {0, 0};
    dur_sstream >> dur1;
    cout << dur1 << endl;
    // Оператор вывода в поток
    // ostream& operator<<(ostream& s, const Obj& o)

    // Оператор ввода в поток
    // istream& operator>>(istream& s, Obj& o)
    Duration dur2 = {23, 44};
    cout << dur2 << endl;
    Duration dur3 = dur1 + dur2;

    vector<Duration> durs = {
            dur3, dur1, dur2
    };
    PrintDursVector(durs);
    sort(begin(durs), end(durs));
    PrintDursVector(durs);

    // bool operator <(const TObj& lhs, const TObj& rhs) {}

    // TObj& operator +(const TObj& lhs, TObj& rhs) {}

    // перегрузка оператора:
    // ??? operator ???(???) {}

    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 6;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 7;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 8;
        }
    }
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 9;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 11;
        }
    }

    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 12;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 13;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 14;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 15;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 16;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 17;
        }
    }

    {
        istringstream input("2/4/6/8");
        Rational r1;
        input >> r1;
        bool correct = r1 == Rational(1, 2);
        if (!correct) {
            cout << "Multiple-slashed number sequence value read incorrectly: " << r1 << endl;
            return 18;
        }
    }
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;

    return 0;
}
