#include <iostream>
#include <vector>
#include <cstdint>
#include <limits>
#include <set>
#include <fstream>
using namespace std;

enum class RequestType {
    ADD,
    REMOVE,
    NEGATE
};

void ProcessRequest(
        set<int>& numbers,
        RequestType request_type,
        int request_data) {
    if (request_type == RequestType::ADD) {
        numbers.insert(request_data);
    } else if (request_type == RequestType::REMOVE) {
        numbers.erase(request_data);
    } else if (request_type == RequestType::NEGATE) {
        if (numbers.count(request_data) == 1) {
            numbers.erase(request_data);
            numbers.insert(-request_data);
        }
    }
}

void ProcessRequestSwitch(
        set<int>& numbers,
        RequestType request_type,
        int request_data) {
    switch (request_type) {
        case RequestType::ADD:
            numbers.insert(request_data);
            break;
        case RequestType::REMOVE:
            numbers.erase(request_data);
            break;
        case RequestType::NEGATE: {  // фигурные скобки обязательны
            bool contains = numbers.count(request_data) == 1;
            if (contains) {
                numbers.erase(request_data);
                numbers.insert(-request_data);
            }
            break;
        }
        default:
            cout << "Unknown request" << endl;
    }
}

int main() {
    // 1. Приведение к беззнаковому типу
    // Average temperature
    vector<int> t = {-8, -7, 3};
    int sum = 0;
    for (int x : t) {
        sum += x;
    }
    // sum - знаковое
    // t.size() - безнаковое
    int avg = sum / t.size();
    // при деление происходит приведение к size_t (unsigned)

    cout << static_cast<unsigned>(sum) << "\n";
    cout << static_cast<unsigned>(sum) / t.size() << "\n";
    cout << avg << "\n";

    // 2. Переполнение int-а
    int x = 2'000'000'000;
    cout << x << " ";
    x *= 2;
    cout << x << "\n";

//     Особенности:
//     Ограниченность по памяти и диапазона значений
//     ~ всё ради эффективности
//     Знаковость и беззнаковость
//     ~ экономия на отрицательных числах

//     #include <cstdint> - для использования int_32_t и uint32_t
//     int64_t, uint64_t
//  sizeof(int) - узнать размер типа в байтах
//  sizeof(int) - узнать размер типа в байтах
    cout << sizeof(int16_t) << "\n";
    int y;
    cout << sizeof(y) << "\n";
    // sizeof(var) - узнать размер переменной нек=го типа

//    #include <numeric> - для получения макс/мин значения типа
    cout << numeric_limits<int>::min() << " " <<
         numeric_limits<int>::max() << "\n";


    // Преобразования целочисленных типов
    cout << numeric_limits<int>::max() +1 << " " <<
         numeric_limits<int>::min() - 1;
    // происходит переполнение

    int a = 2'000'000'000;
    int b = 1'000'000'000;
    cout << (a + b) / 2 << "\n";
    // промежуточные вычисления не умещаются в тип

    int z = -5;
    unsigned int uz = z;
    cout << z << " " << uz << "\n";
    cout << numeric_limits<unsigned int>::max() << "\n";
    // при преобразовании int < 0 -> unsigned происходит циклическое переполнение

    // ПРАВИЛА ВЫВЕДЕНИЕ ОБЩЕГО ТИПА (целочисленного)
//    1. Перед сравнениями и арифметическими операциями числа приводятся к общему типу.
//    2. Все типы размера меньше int приводятся к int.
//    3. Из двух типов выбирается больший по размеру.
//    4. Если размер одинаковый, выбирается беззнаковый.

//    Чтобы узнать тип выражения можно вызвать ошибку компиляции на нем
//    (sum / t.size() + vector<int>());

    int xx = -1;
    unsigned yy = 1;
    cout << (xx < yy); // xx (int) приводится к unsigned как
    cout << (-1 < 1u); // u - модификатор типа
        // numeric_limits<unsigned int>::max() -1
    // g++ main.cpp -Werror - компиляция, при которой предупреждения
    // считаются ошибками

    vector<int> v = {4,  5};
    for (int i = 0; i < v.size(); ++i) {
        cout << i << " " << v[i] << "\n";
    }
    // i < v.size() - сравнения знакового и безнакового типа
    // теретически int мб отрицательной
    // также частая проблема v.size()-1  при v.size() = 0
    // будет переполнение v.size()-1 = numeric_limits<size_t>::max()
//    [i + 1 < v.size()] или [i < static_cast<int>(v.size()) - 1]
    // Решения:
//    1. Объявить size_t
//    2. i < static_cast<size_t>(int)

    vector<int> vec = {1, 4, 5};
//    Бесконечный цикл, т.к. i >=0 всегда т.к. i беззнаковое
//    for (size_t i = v.size()-1;
//         i >= 0;
//         --i) {
//        cout << v[i] << " ";
//    }
//    Будем итерироваться k, которая на единицу больше - замена переменной
    for (size_t k = vec.size();
    k > 0;
    --k) {
        size_t i = k-1;
        cout << vec[i] << " ";
    }

    // Enumeration - перечислимы тип данных
    // сравнение происходит в том же порядке, что и определение
    set<int> numbers;
    ProcessRequest(numbers, RequestType::ADD, 8);
    ProcessRequest(numbers, RequestType::NEGATE, 8);
    ProcessRequest(numbers, RequestType::REMOVE, -8);
    cout << "\n" << (RequestType::ADD < RequestType::NEGATE) << "\n";

    // Оператор Switch
//    В отличие от if, оператор switch не позволяет проверять произвольные логические выражения.
//    Он позволяет сравнить заданную переменную
//    (или результат выражения) с различными конкретными значениями и выполнить
//    различные действия в зависимости от того, с каким значением произошло совпадение.
//    Важная особенность оператора switch заключается в том, что при
//    необходимости объявить переменную в одной из его веток всю ветку придётся заключить в блок из фигурных скобок:
    ProcessRequestSwitch(numbers, RequestType::ADD, 7);
    // Выведет 0
    cout << static_cast<int>(RequestType::ADD) << endl;

    // Выведет 1
    cout << static_cast<int>(RequestType::REMOVE) << endl;

    // Выведет 2
    cout << static_cast<int>(RequestType::NEGATE) << endl;

//    int32_t xxx = RequestType::ADD; - так кастовать слету нельзя, нужен статик каст

    // Средняя температура-2
    cout << numeric_limits<int64_t>::max() << "\n";
    cout << static_cast<int64_t>(1e14) << "\n";
    ifstream in_file("average_temp.txt");
    if (in_file.is_open()) {
        int n, temp;
        in_file >> n;
        int64_t summa = 0;
        vector<int> tt(n);
        for (size_t i = 0; i < n; ++i) {
            in_file >> temp;
            tt[i] = temp;
            summa += temp;
        }
        int64_t average = summa / n;
        cout << "average temp: " << average << "\n";
        set<size_t> gt_avg;
        for (size_t i =0; i < n; ++i) {
            if (tt[i] > average) {
                gt_avg.insert(i);
            }
        }
        cout << gt_avg.size() << "\n";
        for (auto i : gt_avg) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        cerr << "file doesn't exist\n";
    }

    // Масса блоков
    cout << numeric_limits<int64_t>::max() <<"\n";
    cout << static_cast<uint64_t>(1e19) << "\n";
    cout << numeric_limits<uint64_t>::max() <<"\n";
    ifstream inp_file("blocs_mass.txt");
    if (inp_file.is_open()) {
        int n, ro, w, h, d;
        uint64_t sum_mass = 0;
        inp_file >> n >> ro;
        for (size_t i = 0; i < n; ++i) {
            inp_file >> w >> h >> d;
            sum_mass += static_cast<uint64_t>(w) * h * d * ro;
            // приводим один из множителей к uint64_t, чтобы не было переполнения при умножении
        }
        cout << "sum_mass = " << sum_mass << "\n";
    } else {
        cerr << "blocs_mass.txt doesn't open\n";
    }
    return 0;
}

