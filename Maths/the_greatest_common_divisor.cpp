#include <iostream>

using namespace std;

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int gcd_ternar (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int main() {
    cout << gcd_ternar(5, 10) << endl;
    return 0;
}
