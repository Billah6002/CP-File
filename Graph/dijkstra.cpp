#include <bits/stdc++.h>
#define ll long long
using namespace std;


// dijkstra algorithms
const int N = 2e5 + 10;
vector <pair<int, int>> ad[N];
ll ww[N], n;
vector<ll> dist(N, 1e18);

void dijkstra(int s) {
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<> > q;
    q.push({ww[s], s});
    dist[s] = ww[s];

    while (!q.empty()) {
        ll v = q.top()[1];
        ll d_v = q.top()[0];
        q.pop();
        if (d_v != dist[v])
            continue;

        for (auto edge : ad[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (dist[v] + len + ww[to] < dist[to]) {
                dist[to] = dist[v] + len + ww[to];
                q.push({dist[to], to});
            }
        }
    }
}

int main() {}
