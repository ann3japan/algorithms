#include <iostream>
#include <cassert>

using namespace std;

int fib_recursive(int n) {
    assert(n >= 0);
    if (!n || n == 1) return n;
    else return fib_recursive(n-1) + fib_recursive(n-2);
}

int fib_dynamic(int n) {
    int *fib = new int[n+1];
    int res;
    
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i <= n; ++i)
        fib[i] = fib[i-1] + fib[i-2];
    
    res = fib[n];
    delete[] fib;
    return res;
}

int main() {
    for (int i = 0; i < 50; ++i)
        cout << i << " -> " << fib_dynamic(i) << endl;
    return 0;
}
