#include <bits/stdc++.h>
#define ll long long
using namespace std;


// dijkstra algorithms
vector<pair<int, ll>> Adj[1005];
int dist[1005], n;//n number of nodes

void dijkstra(int s){

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pq;
    pq.push({0, s});
    bool mark[n+1] = {false};
    while(!pq.empty()){
        auto [w, v] = pq.top();
        pq.pop();
        mark[v] = true;
        for(auto [u, wt]:Adj[v]){
            if(mark[u]) continue;
            if(w+wt < dist[u]){
                dist[u] = w+wt;
                pq.push({w+wt, u});
            }
        }
    }

}

int main(){}
