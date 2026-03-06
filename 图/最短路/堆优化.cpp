#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 10;
ll d[N];
bool isfinal[N];
ll maxnum = 0;

struct Edge{
    int v;
	long long w;
    bool operator < (const Edge &other) const {
        if (w == other.w) return v < other.v;
        return w > other.w;
    }
};
vector<Edge> mp[N];

int n, m; 

void Dijkstra(int st) {
    memset(d, 0x3f, sizeof(d));
    maxnum = d[0];
    d[st] = 0;
    priority_queue<Edge> pq;
    pq.push({st,d[st]});
    while (!pq.empty()) {
        int point = pq.top().v; pq.pop();
        
        if (isfinal[point]) continue;
        isfinal[point] = true;

        for (auto &[x,w] : mp[point]) {
            if (!isfinal[x] && d[x] > d[point] + w ) {
                d[x] = d[point] + w;
                pq.push({x,d[x]});
            }
        }
    }

	(d[n] < maxnum)? cout << d[n] : cout << -1;

}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin >> n >> m; 
	while (m--) {
        int u, v, w;
		cin >> u >> v >> w;
		if (u != v) mp[u].push_back({v,w});
	}
    Dijkstra(1);
	
}