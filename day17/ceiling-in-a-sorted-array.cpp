#include <bits/stdc++.h>
using namespace std;

int findCeil(int arr[], int n, int x) {
    int start = 0, end = n - 1;
    int res = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == x) {
            return arr[mid];
        } else if (arr[mid] < x) {
            res = arr[mid];
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return res;
}

int main() {
    int arr[] = {12,  312, 1,    3,    1,    345, 2,   234, 2345,
                 234, 5,   2345, 2345, 2345, 1,   123, 6,   7};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    int x = 350;
    cout << findCeil(arr, n, x) << endl;
    return 0;
}
