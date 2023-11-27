#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int lg = 20;

vector<int> adj[N];
int ance[N][lg];

void dfs(int u, int p){
    for(int i=1; i<lg; i++){
        ance[u][i] = ance[ance[u][i-1]][i-1];
        // mx[u][i] = max(mx[u][i-1], mx[ance[u][i-1]][i-1]);
    }
    for(int v:adj[u]){
        if(v==p) continue;
        ance[v][0] = u;
        //mx[v][0] = w;
        dfs(v, u);
    }
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
        int u, k; cin >> u >> k;
        for(int i=lg-1; i>=0; i--){
            if(k&(1<<i)){
                u = ance[u][i];
            }
        }
        cout << u << "\n";
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