#include <iostream>

using namespace std;

//brute force
int find_max_sum(int *a, int l, int r) {
    int max_sum = a[l];
    int n = r-l+1;
    if (l!=r) {
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=i; j<n; ++j) {
            sum += a[j];
            if (sum>max_sum) {
                max_sum = sum;
                l = i;
                r = j;
            }
        }
    }
    }
    return max_sum;
}

// divide and conquer
int div_n_con (int *a, int l, int r) {
    if (l==r) return a[r];
    int mid = (l+r)/2;
    int left_max = div_n_con(a, l, mid);
    int right_max = div_n_con(a, mid+1, r);
    int left_sum = a[l], right_sum = a[r], sum = 0;

    for (int i=mid; i>=0; --i) {
        sum += a[i];
        right_sum = max(right_sum, sum);
    }

    sum = 0;
    for (int j=mid+1; j<r; ++j) {
        sum += a[j];
        left_sum = max(left_sum, sum);
    }

    int res = max(left_max, right_max);
    return max(res, left_sum+right_sum);
}

int main() {
    int a[6] = {-31, 41, 59, 26, 41, 58};

    cout << div_n_con(a, 0, 5);
    return 0;
}
