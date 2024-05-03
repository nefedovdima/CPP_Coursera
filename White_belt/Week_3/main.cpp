using namespace std;
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>


void PrintVector(const vector<int>& v, const string& title) {
    cout << title << ": {";
    for (size_t i = 0; i + 1 < v.size(); ++i) {
        cout << v[i] << ", ";
    }
    cout << v[v.size()-1] << "}\n";
}

void PrintStrVector(const vector<string>& v, const string& title) {
    cout << title << ": {";
    for (size_t i = 0; i + 1 < v.size(); ++i) {
        cout << v[i] << ", ";
    }
    cout << v[v.size()-1] << "}\n";
}

string Parity(int x) {
    string parity = (x % 2 == 0) ? "even" : "odd";
    return parity;
}

string GetPositivity(int x) {
    if (x > 0) {
        return "positive";
    } else if (x < 0) {
        return "negative";
    } else {
        return "zero";
    }
}

void PrintPositivity(int x) {
    string positivity = GetPositivity(x);
    cout << x << " is " << positivity << "\n";
}

struct LectureTitle {
    string specialization;
    string course;
    string week;
};

struct Lecture {
    string title;
    int duration;
    string author;
};

struct DetailedLecture {
    LectureTitle title;
    int duration;
};

void PrintLecture(const Lecture& lecture) {
    cout <<
         "Title: " << lecture.title <<
         ", duration: " << lecture.duration <<
         ", author: " << lecture.author << "\n";
}

void PrintCourse(
        const vector<Lecture>& lectures) {
    for (const Lecture& lecture : lectures) {
        PrintLecture(lecture);
    }
}

int ComputeDistance(const string& source, const string& destination) {
    int diff = destination.size() - source.size();
    return (diff >= 0 ? diff : -diff);
}

class Route { // class уже не структура, так как нас интересует
    //взаимодействие полей внутри
public:
    Route() {
        source = "Source";
        destination = "Destination";
        UpdateLength();
    }
    Route(const string& new_source, const string& new_destination) {
        source = new_source;
        destination = new_destination;
        UpdateLength();
    }
    ~Route() {
        for (const string& log : compute_distance_log) {
            cout << log << "\n";
        }
    }
    string GetSource() const { return source; } // константный метод - не имеет права менять переданный объект
    string GetDestination() const { return destination; }
    int GetLength() const { return length; }

    void SetSource(const string& new_source) {
        source = new_source;
        UpdateLength();
    }

    void SetDestination(const string& new_destination) {
        destination = new_destination;
        UpdateLength();
    }

private: // запрещаем прямой доступ к полям
    string source;
    string destination;
    int length = 0;
    void UpdateLength() {
        length = ComputeDistance(source, destination);
        compute_distance_log.push_back(source + " - " + destination);
    }
    vector<string> compute_distance_log;
};

void PrintRoute(const Route& route) {
    cout << route.GetSource() << " - " << route.GetDestination() << "\n";
}


class SortedStrings {
public:
    void AddString(const string& s) {
        // добавить строку s в набор
        strings.insert(s);
    }
    vector<string> GetSortedStrings() {
        // получить набор из всех добавленных строк в отсортированном порядке
        vector<string> strings_vector;
        for (auto i : strings) {
            strings_vector.push_back(i);
        }
        return strings_vector;
    }
private:
    multiset<string> strings;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

class ReversibleString {
public:
    ReversibleString() = default;
    explicit ReversibleString(const string& str) { data = str; }
    void Reverse() {
        for (int i=0; i<data.size()/2; ++i) {
            swap(data[i], data[data.size()-1-i]);
        }
    }
    string ToString() const {
        return data;
    }
private:
    string data;
};

struct Incognizable {
    int first = 0;
    int second = 0;
};


int main() {
    // MIN-MAX
    string x, y;
    x = "adbcd";
    y = "abmkle";
    cout << min(x, y) << " " << max(x, y) << "\n";


    // SORT
    vector <int> v = {
            1, 5, -6, 3, 11
    };
    PrintVector(v, "init");
    sort(begin(v), end(v));
    PrintVector(v, "sorted");


    //COUNT, COUNT_IF
    int threshold = 3;
    cout << "count: " << count(begin(v), end(v), threshold) << "\n";
    cout << "count_if: " << count_if(begin(v), end(v), [threshold](int x) {
        return x > threshold;
    }) << "\n";


    // RANGE-BASED FOR
    // По - умолчанию range-based for создает копию объекта на каждой итераиции
    for (auto i : v) {
        ++i;
    }
    PrintVector(v, "before ++");
    for (auto& i : v) {
        ++i;
    }
    cout << "after++: ";
    for (const auto& i : v) {
        cout << i << " ";
    }

    // СОРТИРОВКА ЦЕЛЫХ ЧИСЕЛ ПО МОДУЛЮ
    cout << "\n\n"<< "СОРТИРОВКА ЦЕЛЫХ ЧИСЕЛ ПО МОДУЛЮ" << "\n";
    vector<int> vec = {
            5, -22, 11, 0, -6, 13
    };
    PrintVector(vec, "init");
    sort(begin(vec), end(vec), [](int lhs, int rhs) {
        if (lhs < 0) {
            lhs = -lhs;
        }
        if (rhs < 0) {
            rhs = -rhs;
        }
        return lhs < rhs;
    });
    PrintVector(vec, "moduls sort");
    // СОРТИРОВКА БЕЗ УЧЕТА РЕГИСТРА
    cout << "\n" << "СОРТИРОВКА БЕЗ УЧЕТА РЕГИСТРА" << "\n";
    vector <string> vec_s = {
            "Bb", "aA", "Cc"
    };
    PrintStrVector(vec_s, "init str vector");

//     sort(begin(vec_s), end(vec_s),
//        [](const string& l, const string& r) {
//          return lexicographical_compare(
//              begin(l), end(l),
//              begin(r), end(r),
//              [](char cl, char cr) { return tolower(cl) < tolower(cr); }
//          );
//        }
//   );


    sort(begin(vec_s), end(vec_s),
         [](const string& lhs, const string& rhs) {
             return lexicographical_compare(
                     begin(lhs), end(lhs),
                     begin(rhs), end(rhs),
                     [](const char& l, const char& r) { return tolower(l) < tolower(r); }
             );
         }
    );
    PrintStrVector(vec_s, "sort str vector without registr");

    // ОБЛАСТИ ВИДИМОСТИ
    // Переменная в C++ видна после своего объявления и до конца
    // блока из операторных скобок {}, в котором она объявлена.

    // Переменная, объявленная внутри циклов for, while
    // или if не видна за его пределами

    // ИНИЦИАЛИЗАЦИЯ ПЕРЕМЕННЫХ
    cout << "\nИНИЦИАЛИЗАЦИЯ ПЕРЕМЕННЫХ\n";
    // Значение неинициализированных переменных не определено

    // Тернарный оператор сравнения
    // x = (predicate) ? if_true : if_false;

    // Если варианта для переменной два - то инициализация, через
    // тернарный оператор
    int xx = 3;
    cout << "parity of " << xx << " is "
         << Parity(xx) << "\n";

    // Если вариантов для переменной >2 - то инициализация, через
    // функцию
    PrintPositivity(5);
    PrintPositivity(-7);
    PrintPositivity(0);

    // ВВЕДЕНИЕ В СТРУКТУРЫ И КЛАССЫ
    cout << "\nВВЕДЕНИЕ В СТРУКТУРЫ И КЛАССЫ\n";
    // Структуры
    cout << "\nСтруктуры\n";
    Lecture lecture1;
    lecture1.title = "OOP";
    lecture1.duration = 5400;
    lecture1.author = "Dima";

    Lecture lecture2 = {"OOP2", 5444, "Dimon" };
    PrintLecture(lecture1);
    cout << "\n";
    vector<Lecture> course = {lecture1, lecture2};
    PrintCourse(course);

    DetailedLecture lecture3 = {{"C++", "White belt", "OOP"}, 1200};
    cout << lecture3.title.specialization << "\n";

    // struct - структура - набор публичных полей
    // +используем, если контролировать консистентность не нужно


    // Классы
    cout << "\nКлассы\n";
    // class - класс - скрывает данные, предоставляя
    // определенный интерфейс доступа к ним
    // + используем, если поля не связаны друг с другом и эту связь
    // нужно контролировать


    Route route;
    route.SetSource("Moscow");
    route.SetDestination("Dubna");

    cout << "Route from " <<
         route.GetSource() << " to " <<
         route.GetDestination() << " is " <<
         route.GetLength() << "km\n";

    // Смысловая связь между полями класса контролируется в методах.

    SortedStrings strings;
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    PrintRoute(route);
    // Методы могут быть
    /*
      +константными - не изменяют объект в контексте которого они вызваны
      +неконстантными - изменяют объект
      по константной ссылке на объект (const type& name) можно вызвать только константный метод
      по неконстантной ссылке на объект () можно вызвать любой метод
    */

    // Параметраризованный конструктор
    /*
     + Похож на метод без возвращаемого значения
     + Название совпадает с названием класса
    */
    Route new_route = {"Saint-Petersburg", "Yoshkar-Ola"};
    PrintRoute(new_route);

    PrintRoute(Route());
    PrintRoute({});
    PrintRoute(Route("Zvenigorod", "Istra"));

    vector<Route> routes;
    routes.push_back({"Kislo", "Vodsk"});
    // СТРОКА
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;


    // INCOGNIZABLE
    cout << "\nINCOGNIZABLE\n";
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    return 0;
    // Компилятор уничтожает объекты в обратном порядке относительного того, как они создавались.


}
