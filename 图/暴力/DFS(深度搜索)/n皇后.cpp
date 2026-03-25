#include <iostream>
using namespace std;
using ll = long long;

const int N = 12;
int vis[N][N];
int n, ans;

void dfs(int depth){
    if (depth == n + 1) {
        ans++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[depth][i]) continue;
        // 标记相同列 以及45°斜角的所有棋盘 会自动前往下一行所以不用标记
        for (int y = 1; y <= n; y++)  vis[y][i]++; 
        for (int x = depth, y = i; x <= n && y <= n; x++, y++) vis[x][y]++;
        for (int x = depth, y = i; x >= 1 && y >= 1; x--, y--) vis[x][y]++;
        for (int x = depth, y = i; x <= n && y >= 1; x++, y--) vis[x][y]++;
        for (int x = depth, y = i; x >= 1 && y <= n; x--, y++) vis[x][y]++;
        
        dfs(depth + 1);

        for (int y = 1; y <= n; y++)  vis[y][i]--; 
        for (int x = depth, y = i; x <= n && y <= n; x++, y++) vis[x][y]--;
        for (int x = depth, y = i; x >= 1 && y >= 1; x--, y--) vis[x][y]--;
        for (int x = depth, y = i; x <= n && y >= 1; x++, y--) vis[x][y]--;
        for (int x = depth, y = i; x >= 1 && y <= n; x--, y++) vis[x][y]--;
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n;
    dfs(1);
    cout << ans;
    return 0;
}