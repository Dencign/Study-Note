#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void multi(string a, int b) {
    if (b == 0) {
        cout << 0 << '\n';
        return;
    }
    int alen = a.size();
    int t = 0;
    reverse(a.begin(), a.end());
    vector<int> v;
    for (int i = 0; i < alen; i++) {
        t = t + (a[i] - '0') * b;
        v.push_back(t % 10);
        t /= 10;
    }
    if (t) v.push_back(t);
    reverse(v.begin(), v.end());
    for (auto &x: v) {
        cout << x;
    } cout << '\n';
}

int main() {
    string s1;
    int s2;
    cin >> s1 >> s2; 
    multi(s1, s2);
}