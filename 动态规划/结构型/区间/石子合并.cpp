#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 2e18;
const int N = 310;
ll dp[N][N], a[N], prefix[N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		prefix[i] = a[i] + prefix[i - 1];
		dp[i][i] = 0;
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			dp[i][j] = INF;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + prefix[j] - prefix[i - 1]); 
			}
		}
	}
	cout << dp[1][n];
}