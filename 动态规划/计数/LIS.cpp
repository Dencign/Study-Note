// Longest Increasing Subsequence
#include <iostream>
using namespace std;

const int N = 1e3 + 10;
int a[N];
int dp[N];// dp[i] 表示以i结尾的最长上升子序列
int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++) {
        dp[i] = 1; 
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) dp[i] = max(dp[j] + 1, dp[i]);
        }
    } 
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[i]); 
    }
    cout << res;
    return 0;
}