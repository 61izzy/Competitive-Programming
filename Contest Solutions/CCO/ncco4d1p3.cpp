#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, l, dist[2][5001];
vector<vector<pair<int, int>>> adj(5001);
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[0][1] = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> l;
        adj[a].push_back({b, l});
        adj[b].push_back({a, l});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        pair p = pq.top(); pq.pop();
        for (pair i : adj[p.second]) {
            if (p.first + i.second < dist[0][i.first]) {
                dist[1][i.first] = dist[0][i.first];
                dist[0][i.first] = p.first + i.second;
                pq.push({dist[0][i.first], i.first});
            }
            else if (p.first + i.second > dist[0][i.first] && p.first + i.second < dist[1][i.first]) {
                dist[1][i.first] = p.first + i.second;
                pq.push({dist[1][i.first], i.first});
            }
        }
    }
    cout << (dist[1][n] == 0x3f3f3f3f ? -1 : dist[1][n]) << "\n";
}
