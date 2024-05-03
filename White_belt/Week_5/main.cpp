#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

class Date {
public:
    explicit Date(int _year, int _month, int _day) {
        year = _year;
        if (_month < 1 || _month > 12) {
            throw invalid_argument("Month value is invalid: " + to_string(_month));
        }
        month = _month;
        if (_day < 1 || _day > 31) {
            throw invalid_argument("Day value is invalid: " + to_string(_day));
        }
        day = _day;
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
private:
    int year = 0;
    int month = 0;
    int day = 0;
};

bool operator<(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} < vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}


ostream& operator<<(ostream& os, const Date& d) {
    cout << setw(4) << setfill('0') << d.GetYear() << "-"
         << setw(2) << setfill('0') << d.GetMonth() << "-"
         << setw(2) << setfill('0') << d.GetDay();
    return os;
}

Date ParseDate(string& date) {
    istringstream date_stream(date);
    bool ok = true;

    int year;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    ok = ok && (date_stream >> day);
    ok = ok && date_stream.eof();

    if (!ok) {
        throw logic_error("Wrong date format: " + date);
    }
    return Date(year, month, day);
}

class DataBase {
public:
    void AddEvent(const Date& date, const string& event) {
        date_to_event[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (date_to_event.count(date) == 0 || date_to_event[date].count(event) == 0) {
            return false;
        } else {
            date_to_event[date].erase(event);
            return true;
        }
    }
    int DeleteDate(const Date& date) {
        int del_count = 0;
        if (date_to_event.count(date) != 0) {
            del_count = date_to_event[date].size();
            date_to_event.erase(date);
        }
        return del_count;
    }

    void FindDate(const Date& date) const {
        if (date_to_event.count(date) == 0) {
            return;
        }
        for (const string& event : date_to_event.at(date)) {
            cout << event << "\n";
        }
    }

    void Print() const {
        for (const pair<Date, set<string>> item : date_to_event) {
            for (const string& event : item.second) {
                cout << item.first << " " << event << "\n";
            }
        }
    }
private:
    map <Date, set<string>> date_to_event;
};

int main() {
    auto db = DataBase();

    try {
        std::ifstream file("data.txt");
        if (!file) {
            std::cerr << "Unable to open data.txt" << std::endl;
            return 1;
        }
        std::string line;
        while (std::getline(file, line)) {
            if (line.empty()) {
                continue;
            }
            stringstream ss(line);
            string comand;
            ss >> comand;
            if (comand == "Add") {
                string data, event;
                ss >> data >> event;
                Date date = ParseDate(data);
                db.AddEvent(date, event);
            } else if (comand == "Del") {
                string data, event;
                ss >> data;
                Date date = ParseDate(data);
                if (!ss.eof()) {
                    ss >> event;
                }
                if (!event.empty()) {
                    bool ok = db.DeleteEvent(date, event);
                    if (ok) {
                        cout << "Deleted successfully\n";
                    } else {
                        cout << "Event not found\n";
                    }
                } else {
                    int del_count = db.DeleteDate(date);
                    cout << "Deleted " << del_count << " events\n";
                }
            } else if (comand == "Find") {
                string data;
                ss >> data;
                Date date = ParseDate(data);
                db.FindDate(date);

            } else if (comand == "Print") {
                db.Print();
            } else {
                throw logic_error("Unknown command: " + comand);
            }
//            db.Print();

        }
    } catch (exception& ex) {
        cout << ex.what();
    }
    return 0;
}
