#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 10;
ll d[N];
bool isfinal[N];
ll maxnum = 0;

struct Edge{
    int v;
	int w;
	Edge(){}
	Edge(int a, int b) : v(a), w(b) {}
};
vector<Edge> mp[N];

int n, m; 

void Dijkstra(int x) {
    d[x] = 0;
    for (int i = 1; i <= n; i++) {
		int min = 1;
		for (int j = 1; j <= n; j++) 
			if (isfinal[min] || (!isfinal[j] && d[j] < d[min])) min = j;
		isfinal[min] = true;
		for (auto [v,w] : mp[min]) {
			if (!isfinal[v] && d[v] > d[min] + w) {
				d[v] = d[min] + w;
			}
		}
	}
	if (d[n] < maxnum)
		cout << d[n];
	else
		cout << -1;

}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(d, 0x3f, sizeof(d));
	maxnum = d[1];

	cin >> n >> m; 
	while (m--) {
        int u, v, w;
		cin >> u >> v >> w;
		if (u != v) mp[u].push_back(Edge(v,w));
	}
    Dijkstra(1);
	
}