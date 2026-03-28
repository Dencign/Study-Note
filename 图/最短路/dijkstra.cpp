#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 10;
ll d[N];
bool isfinal[N];
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Edge{
    int v; //边
	int w; //权值
};
vector<Edge> mp[N];

int n, m; 

void Dijkstra(int x) {
	//初始化
	memset(d, 0x3f, sizeof(d));
	memset(isfinal, false, sizeof(isfinal));
    d[x] = 0;
    for (int i = 1; i <= n; i++) {
		//找最短路径点
		int min = -1;
		for (int j = 1; j <= n; j++) {
			if (!isfinal[j]) {
				if (min == -1 || d[j] < d[min])
					min = j;
			}
		}
		if (min == -1 || d[min] == INF) break;
		isfinal[min] = true;
		for (auto [v,w] : mp[min]) {
			if (!isfinal[v] && d[v] > d[min] + w) {
				d[v] = d[min] + w;
			}
		}
	}	
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin >> n >> m; 
	while (m--) {
        int u, v, w;
		cin >> u >> v >> w;
		if (u != v) mp[u].push_back(Edge{v,w});
	}

    Dijkstra(1);

	if (d[n] != INF)
		cout << d[n];
	else
		cout << -1;
}