#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


// Минимальная строка
/*
int main() {
    string a, b, c;
    cin >> a >> b >> c;
    if (a <= b && a <= c)
        cout << a;
    else if (b <= a and b <= c)
        cout << b;
    else
        cout << c;
    return 0;
}
*/
//

// Квадратное уравнение
/*
int main() {
    double a= 0;
    double b = 0;
    double c = 0;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0 && c != 0)
            cout << "No solution\n";
        else if (b == 0 && c == 0)
            cout << "(-inf, inf)\n";
        else
            cout << -c / b << "\n";
    }
    else {
        double D = b *b - 4 * a * c;
        if (D > 0)
            cout << (-b - sqrt(D)) / (2*a) << " " << (-b + sqrt(D)) / (2*a) << "\n";
        else if (D == 0)
            cout << -b / (2*a) << "\n";
        else
            cout << "No solution\n";
    }
    return 0;
}
*/
// Деление
/*
int main() {
    int a, b;
    cin >> a >> b;
    if (b == 0)
        cout << "Impossible\n";
    else
        cout << a / b << "\n";
    return 0;
}
*/

// Расчет стоимости товара
/*
int main() {
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    if (n > b)
        cout << n * (1 - y / 100) << '\n';
    else if (n > a)
        cout << n * (1 - x / 100) << '\n';
    else
        cout << n;
    return 0;
}
*/

// Четные числа
/*
int main() {
    int a, b;
    cin >> a >> b;
    for (int i=a; i<=b; ++i) {
        if (i % 2 == 0)
            cout << i << ' ';
    }
    return 0;
}
*/

// Второе вхождение буквы f
/*
int main() {
    string s;
    cin >> s;
    int cnt_f = 0;
    for (int i=0; i < s.size(); ++i){
        if (s[i] == 'f') {
            if (cnt_f == 0)
                ++cnt_f;
            else {
                ++cnt_f;
                 cout << i;
                break;
            }
        }
    }
    if (cnt_f == 1) {
        cout << -1;
    }
    else if (cnt_f == 0)
        cout << -2;
    return 0;
}
 */

// НОД
/*
int main() {
    int a, b;
    cin >> a >> b;
    while (b != 0) {
        // a, b = b, a % b;
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    cout << a;
    return 0;
}
*/

// Двоичные числа
int main() {
    int x;
    cin >> x;
    vector <int> v;
    while (x != 0) {
        v.push_back(x % 2);
        x = x / 2;
    }
    int n = v.size();
    while (n > 0) {
        cout << v[n-1] << "";
        --n;
    }
    return 0;
}