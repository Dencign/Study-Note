#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void add(string a, string b) {
    int alen = a.size();
    int blen = b.size();
    int t = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> v;
    for (int i = 0; i < alen || i < blen; i++) {
        if (i < alen) t += (a[i] - '0');
        if (i < blen) t += (b[i] - '0');
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
    string s1, s2;
    cin >> s1 >> s2; 
    add(s1, s2);
}