// https://codeforces.com/gym/105950/problem/O
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU {
  vector<int> par, sz;
  DSU(int n) {
    par.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
      sz[i] = 1;
    }
  }
  int find(int u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
  }
  void merge(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return;
    if (sz[u] > sz[v]) swap(u, v);
    par[u] = v;
    sz[v] += sz[u];
  }
};

void solve() {
  int n, m; cin >> n >> m;
  vector<array<int, 3>> edges;
  for (int i = 1; i <= m; i++) {
    int a, b, w; cin >> a >> b >> w;
    edges.push_back({w, a, b});
  }
  sort(edges.begin(), edges.end());
  vector<array<int, 2>> ad[n + 1];
  DSU gp(n);
  for (auto [w, u, v] : edges) {
    if (gp.find(u) == gp.find(v)) continue;
    gp.merge(u, v);
    ad[u].push_back({w, v});
    ad[v].push_back({w, u});
  }
  vector<int> dis(n + 1);
  function<void(int, int, int)> dfs = [&](int u, int p, int mx) {
    dis[u] = mx;
    for (auto [w, v] : ad[u]) {
      if (v == p) continue;
      dfs(v, u, max(mx, w));
    }
  };
  dfs(1, 1, 0);
  int k; cin >> k;
  vector<int> reg(k);
  for (int i = 0; i < k; i++) {
    int x; cin >> x;
    reg[i] = dis[x];
  }
  sort(reg.begin(), reg.end());
  vector<int> leder(k);
  for (int i = 0; i < k; i++) {
    cin >> leder[i];
  }
  sort(leder.begin(), leder.end());
  int i = 0, j = 0, ans = 0;
  while (i < k and j < k) {
    if (reg[i] <= leder[j]) {
      ans++;
      i++; j++;
    }
    else j++;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tt = 1;
  // cin >> tt;
  while (tt--) {
    solve();
  }
}
