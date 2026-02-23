#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];
int n;

int main() {
    stack<int> s;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
    while (!s.empty() && s.top() >= a[i]) 
        s.pop();
    if (s.empty()) 
        cout << -1 << ' ';
    else 
        cout << s.top() << ' ';
    s.push(a[i]);
    }
}