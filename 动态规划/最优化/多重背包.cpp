#include <iostream>
using namespace std;

const int N = 2e2 + 10;
long long dp[N];
int w, v, s;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, V; cin >> n >> V;

    for (int i = 1; i <= n; i++) {
        cin >> w >> v >> s;
        for (int x = 1; x <= s; x++) {
            for (int j = V; j >= w; j--) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
    }
    cout << dp[V];
    return 0;
}