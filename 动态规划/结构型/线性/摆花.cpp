#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int p = 1e6 + 7; 
int a[105];
ll dp[105][105];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m; cin >> n >> m;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= min(a[i], j); k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % p;
			} 
		}
	}
	cout << dp[n][m];
}