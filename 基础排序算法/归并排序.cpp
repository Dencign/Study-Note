#include <bits/stdc++.h>
#include <vector>
using namespace std;

void mergesort(int left, int right, vector<int> &arr, vector<int> &temp){
    if(left >= right)   return;
    int mid = left + (right - left) / 2;
    //拆分
    mergesort(left, mid, arr, temp);
    mergesort(mid + 1, right, arr, temp);
    //合并
    int i = left, j = mid + 1, num = 0;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) 
            temp[left+num] = arr[i++];
        else if (arr[i] >= arr[j])
            temp[left+num] = arr[j++];
        num++;
    } 
    while (i <= mid)    temp[left+(num++)] = arr[i++];
    while (j <= right)  temp[left+(num++)] = arr[j++];

    for (int index = left; index < left + num; index++) 
        arr[index] = temp[index];
}

int main() {
    vector<int> arr = {2,5,1,10,2,5,6,7,9};
    vector<int> temp (9);
    mergesort(0, 8, arr, temp);
    for (int x : arr) 
        cout << x << ' ';
}