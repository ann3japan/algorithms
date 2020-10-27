#include <iostream>

using namespace std;

int gcd (int a, int b) {
    return (!b) ? a : gcd(b, a % b);
}



int main() {
    cout << gcd(678, 891) << endl;
    return 0;
}
