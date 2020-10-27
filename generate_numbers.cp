#include <iostream>

using namespace std;

void generate_nums (int n) {
    static int dig_cmb[100];
    static int top = 0;
    
    if (!n) {
        for (int i = 0; i < top; ++i)
            cout << dig_cmb[i];
        cout << endl;
    } else {
        dig_cmb[top++] = 0;
        generate_nums(n - 1);
        --top;
        
        dig_cmb[top++] = 1;
        generate_nums(n - 1);
        --top;
    }
}

void permutations(int num, int curr, int buffer[]) {
    if (curr == num) {
        for (int i = 0; i < num; ++i)
            cout << buffer[i];
        cout << endl;
    } else {
        for (int var = 0; var < num; ++var) {
            buffer[curr] = var;
            permutations(num, curr + 1, buffer);
        }
    }
}

int main() {
    generate_nums(4);
    cout << endl;
    int buffer[3];
    permutations(3, 0, buffer);
    return 0;
}
