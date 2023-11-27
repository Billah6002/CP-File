#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int lg = 20;

vector<int> adj[N];
int ance[N][lg];
int depth[N];

void dfs(int u, int p){
    for(int i=1; i<lg; i++){
        ance[u][i] = ance[ance[u][i-1]][i-1];
        // mx[u][i] = max(mx[u][i-1], mx[ance[u][i-1]][i-1]);
    }
    for(int v:adj[u]){
        if(v==p) continue;
        ance[v][0] = u;
        //mx[v][0] = w;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for(int i=lg-1; i>=0; i--){
        if(k&(1<<i)){
            u = ance[u][i];
        }
    }
    if(u==v) return u;
    for(int i=lg-1; i>=0; i--){
        if(ance[u][i] != ance[v][i]){
            u = ance[u][i];
            v = ance[v][i];
        }
    }
    return ance[u][0];
}
void solve() {
    int n; cin >> n;
    for(int i=1; i<n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ance[1][0] = 0;
    dfs(1, -1);

    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1;
    // cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}