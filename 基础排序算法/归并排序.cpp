#include <bits/stdc++.h>
#include <vector>
using namespace std;

void mergesort(int left, int right,vector<int> &v,vector<int> &temp) {
    if (left >= right) return;
    int mid = (left + right) / 2;

    mergesort(left, mid, v, temp);
    mergesort(mid + 1, right, v, temp);

    int i = left, j = mid + 1;
    int index = left;
    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) {
            temp[index] = v[i++];
        } else {
            temp[index] = v[j++];
        }
        index++;
    }

    while (i <= mid) temp[index++] = v[i++];
    while (j <= right) temp[index++] = v[j++];

    for (int i = left; i <= right; i++) {
        v[i] = temp[i];
    }
}


int main() {
    vector<int> arr = {2,5,1,10,2,5,6,7,9};
    vector<int> temp (9);
    mergesort(0, 8, arr, temp);
    for (int x : arr) 
        cout << x << ' ';
}