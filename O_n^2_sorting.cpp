#include <iostream>

using namespace std;

void bubble_sort (int a[], int n) {
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j)
            if (a[i] > a[j]) swap(a[i], a[j]);
}

void selection_sort (int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min]) min = j;
        }
        swap(a[i], a[min]);
    }
}

void insertion_sort (int a[], int n) {
    for (int i = 1; i < n; ++i)
        for (int j = i; j > 0 && a[j-1] > a[j]; --j)
            swap(a[j-1], a[j]);
}

void shell_sort(int a[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2)
        for (int i = gap; i<n; ++i)
            for (int j = i-gap; j>=0; j -= gap) {
                if (a[j+gap] >= a[j]) break;
                else swap(a[j+gap], a[j]);
            }
}

int main() {
    int a[10] = {8, 3, 6, 3, 1, 5, 9, 2, 4, 7};
    insertion_sort(a, 10);
    for (int i = 0; i < 10; ++i)
        cout << a[i] << " ";
    return 0;
}
