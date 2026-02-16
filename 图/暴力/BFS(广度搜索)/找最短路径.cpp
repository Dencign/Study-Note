#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int mp[N][N];
bitset<N> vis[N];
int step[N][N];

int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

queue<pair<int,int>> que;

bool inmap(int x, int y) {
	if(x > 0 && y > 0 && x <= n && y <= m)
		return true;
	return false;
}
//起点坐标
void bfs(int x,int y) {
	if(!vis[x][y])
		que.push({x,y});
	while (!que.empty()) {
		int tx = que.front().first, ty = que.front().second;
		que.pop();
		vis[tx][ty] = true;
		for(int i = 0; i < 4; i++){
			int nx = tx + dx[i], ny = ty + dy[i];
			if (inmap(nx,ny) && !mp[nx][ny] && !vis[nx][ny]) {
				que.push({nx,ny});
				vis[nx][ny] = true;
				step[nx][ny] = min(step[nx][ny], step[tx][ty] + 1); 
			}
		}
	}
}

int main() {
	//图的行数和列数
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d",&mp[i][j]);
    //设置每个格最开始为最大值
	memset(step,0x3f,sizeof(step));
	
    step[1][1] = 0;
	bfs(1,1);
				
	if(vis[n][m])
		cout << step[n][m];
	else
		cout << "-1";
}