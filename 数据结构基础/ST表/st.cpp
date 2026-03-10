#include <bits/stdc++.h>
using namespace std;
// lanqiao 1205
const int N = 5e5 + 10;
int st[N][21];

int getmax(int l, int r) {
    int len = log(r - l + 1) / log (2);
    return max(st[l][len], st[r - (1 << len) + 1][len]);
}

int main() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> st[i][0];
    
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (q--) {
        int x, y; cin >> x >> y;
        cout << getmax(x, y) << '\n';
    }
    
    return 0;
}