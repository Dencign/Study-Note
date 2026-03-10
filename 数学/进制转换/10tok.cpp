#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 13;

    int a[10];
    int index = 0;

    int k = 2;

    while(x) a[index++] = x % k, x /= k;
    reverse(a, a + index );

    for (int i = 0; i < index; i++) {
        cout << a[i];
    }
}