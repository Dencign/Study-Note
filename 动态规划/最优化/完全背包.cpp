#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int m, n;
const int N = 1e5 + 10;
ll dp[2][N];
int w[505], v[505];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	for (int i = 1; i <= n; i++) {
		int y = i & 1, beh = y ^ 1;
		for (int j = 1; j <= m; j++) {
			if (j < v[i]) dp[y][j] = dp[beh][j];
			else dp[y][j] = max(dp[beh][j], dp[y][j - v[i]] + w[i]);
            //根据当前行更新
		}
	}
	cout << dp[n & 1][m];
}