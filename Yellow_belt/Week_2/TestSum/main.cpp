#include <iostream>
#include <vector>
#include <cassert>


using namespace std;

int Sum(int x, int y) {
    return x + y;
}

void TestSum() {
    assert(Sum(2, 3) == 5);
    assert(Sum(-2, -3) == -5);
    assert(Sum(-2, 0) == -2);
    assert(Sum(-2, 2) == 0);
    cout << "TestSum OK\n";
}
int main() {
    TestSum();
    return 0;
}
