// https://lightoj.com/problem/substring-frequency-ii
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 510 * 510, C = 26;
int to[N][C], tot, slnk[N], dp[N];
vector <int> order;

void init() {
   while (tot >= 0) {
      memset(to[tot], 0, sizeof to[tot]);
      slnk[tot] = 0;
      dp[tot] = 0;
      tot--;
   }
   tot = 0;
   order.clear();
}

int add(string s) {
   int u = 0;
   for (auto c : s) {
      c -= 'a';
      if (!to[u][c]) to[u][c] = ++tot;
      u = to[u][c];
   }
   return u;
}

void build() {
   queue <int> q;
   q.push(0);
   while (!q.empty()) {
      int p = q.front(); q.pop();
      order.push_back(p);
      for (int c = 0; c < 26; c++) {
         int u = to[p][c];
         if (!u) continue;
         q.push(u);
         if (!p) continue;
         int v = slnk[p];
         while (v and !to[v][c]) {
            v = slnk[v];
         }
         slnk[u] = to[v][c];
      }
   }
}

void solve() {
   init();
   int n; cin >> n;
   string s; cin >> s;
   int pat[n];
   for (int i = 0; i < n; i++) {
      string p; cin >> p;
      pat[i] = add(p);
   }
   build();
   int u = 0;
   for (char c : s) {
      c -= 'a';
      while (u and !to[u][c]) u = slnk[u];
      u = to[u][c];
      dp[u]++;
   }
   reverse(order.begin(), order.end());
   for (int x : order) {
      dp[slnk[x]] += dp[x];
   }
   for (int i = 0; i < n; i++) {
      cout << dp[pat[i]] << "\n";
   }

}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int tt = 1, cs = 1;
   cin >> tt;
   while (tt--) {
      cout << "Case " << cs++ << ":\n";
      solve();
   }
}