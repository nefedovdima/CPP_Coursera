#include <iostream>
#include <vector>
#include <fstream>
#include <tuple>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <cstdint>
#include <algorithm>
using namespace std;

struct Date {
    int year;
    string month;
    int day;
    Date(int new_year, const string& new_month, int new_day)
            : year(new_year), month(new_month), day(new_day) {} // список инициализации

    tuple<const int&, const string&, const int&> GetTuple() const {
        return tie(year, month, day);
    }
};

bool operator>(const Date& lhs, const Date& rhs) {
    return lhs.GetTuple() > rhs.GetTuple();
}

bool operator<(const Date& lhs, const Date& rhs) {
    auto lhs_key = tie(lhs.year, lhs.month, lhs.day);
    tuple<const int&, const string&, const int&> rhs_key = tie(rhs.year, rhs.month, rhs.day);
    return lhs_key < rhs_key;
}


class Cities {
public:
    tuple<bool, string> FIndCountry(const string& city) const {
        if (city_to_country.count(city) == 1) {
            return {true, city_to_country.at(city)};
        } else if (ambigious_cities.count(city) == 1) {
            return {false, "Ambigious"};
        } else {
            return {false, "Not exist"};
        }
    }
private:
    map<string, string> city_to_country;
    set<string> ambigious_cities; // двусмысленный
};

enum class Lang {
    DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};

bool operator<(const Region& lhs, const Region& rhs) {
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
            tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
//    set<Region> unique_regions;
    map<Region, int> region_to_cnt;
    for (const Region& reg : regions) {
        ++region_to_cnt[reg];
    }
    int max_cnt = 0;
    for (const auto& [reg, cnt] : region_to_cnt) {
        if (cnt > max_cnt) {
            max_cnt = cnt;
        }
    }
    return max_cnt;
}

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return person_to_info.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person) {
        ++person_to_info[person][TaskStatus::NEW];
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
            const string& person, int task_count) {
        TasksInfo updated_tasks, untouched_tasks;
        if (person_to_info.count(person) == 0)  {
            return {{}, {}};
        }
        int cur_cnt = task_count;
        TasksInfo tasks = person_to_info[person];
        for (auto [task_status, cnt] : tasks) {
            if (cur_cnt > 0) {
                
            }
        }
    }
private:
    map<string, TasksInfo> person_to_info;
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
         ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
         ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
         ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
    ifstream in("input.txt");
    if (in.is_open()) {
        cout << "good\n";
        in.close();
    } else {
        cerr << "input.txt doesnt't open\n";
    }
    // Хотим перегрузить оператор сравнения для дат
    // Вектор хранит объекты только одного типа и вектор довольно мощный
    // может много всего, кроме сравнения
    // tie - связать объекты в tuple
    cout << (Date(2017, "June", 8) >
        Date(2017, "January", 26)) << "\n";
    // tuple - по сути структура, которую не надо отдельно объявлять
    // при этом объекты кортежа не копируются, а берутся по константной ссылке

    tuple<int, string, bool> t(7, "C++", true);
    tuple t2(7, "C++", true); // в стандарте C++17 можно так
    // tie - нужна для того, чтобы взять значения которые где-то храняться, поиспользовать
    // и забыть
    // tie - создает кортеж из ссылок
    // make_tuple - создает кортеж из самих значений
    auto tt = make_tuple(7, "C++", true);
//    auto ttt = tie(7, "C++", true); <- так нельзя !!

    // Синтаксис обрщения к полям кортежа странный
    cout << get<1>(tt) << "\n"; // получить первый элемент кортежа tt

    // Для пары нужно подлючить
    // #include <utility>
    // Пара -способ сохранить структуру, не объявляя эту структуру
    pair<int, string> p(7,"C++");
    pair pp(7, "D++"); // в C++17 можно так
    auto ppp = make_pair(7, "C++");
    cout << p.first << " " << p.second << "\n";
    map<int, string> digits = {
            {1, "one"}
    };
    // structured binding - структурное связывание - начиная с C++17
    // итерирование по словарю не создавая пары
    for (const auto& [key, value] : digits) {
        cout << key << ": " << value << "\n";
    }

    Cities cities;
    bool success;
    string message;
    tie(success, message) = cities.FIndCountry("Yoshkar-Ola");
//    cout << get<0>(f) << " " << get<0>(f) << "\n";
    cout << success << " " << message << "\n";

    auto [suc, mes] = cities.FIndCountry("Yoshkar-Ola");
    cout << suc << " " << mes << "\n";
    // Кортежи —упрощают реализацию операторов
    //Позволяют вернуть несколько значений из функции и сохранить их
    //Пары — частный случай кортежей, но чуть приятнее

    // База регионов
        cout << FindMaxRepetitionCount({
                                               {
                                                       "Moscow",
                                                       "Russia",
                                                       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                       89
                                               }, {
                                                       "Russia",
                                                       "Eurasia",
                                                       {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                                                       89
                                               }, {
                                                       "Moscow",
                                                       "Russia",
                                                       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                       89
                                               }, {
                                                       "Moscow",
                                                       "Russia",
                                                       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                       89
                                               }, {
                                                       "Russia",
                                                       "Eurasia",
                                                       {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                                                       89
                                               },
                                       }) << endl;

        cout << FindMaxRepetitionCount({
            {
                "Moscow",
                "Russia",
                {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                89}, {
                "Russia",
                "Eurasia",
                {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                89
                }, {
                "Moscow",
                "Russia",
                {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
                89}, {
                "Moscow",
                "Toulouse",
                {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                89}, {
                "Moscow",
                "Russia",
                {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                31},}) << endl;

    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

//    TasksInfo updated_tasks, untouched_tasks;
//
//    tie(updated_tasks, untouched_tasks) =
//            tasks.PerformPersonTasks("Ivan", 2);
//    cout << "Updated Ivan's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Ivan's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    tie(updated_tasks, untouched_tasks) =
//            tasks.PerformPersonTasks("Ivan", 2);
//    cout << "Updated Ivan's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Ivan's tasks: ";
//    PrintTasksInfo(untouched_tasks);

    return 0;
}
