#include <iostream>
using namespace std;
// 下标
void quicksort(int l, int r, int arr[]){
    //确定中间的数有序
    //再分别处理左右两部分
    if (l >= r) return;
    int x = arr[(l + r) / 2];
    int i = l, j = r; 
    while (i <= j){
        while(arr[i] < x)  i++;
        while(arr[j] > x)  j--;
        if (i <= j){
            swap(arr[i], arr[j]);
            i++,j--;
        }
    } 
    if(l < j) quicksort(0, j, arr);
    if(r > i) quicksort(i, r, arr);
}

int main() {
    int arr[] = {2,5,1,10,2,5,6,7,9};
    quicksort(0, 8, arr);
    for (int x : arr)
        cout << x << ' ';
}