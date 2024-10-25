// https://open.kattis.com/problems/stringmultimatching
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 10, C = 256;
int to[N][C], tot, slnk[N], pos[N];
vector <int> order;
set <int> ppos[N];

void init() {
   while (tot >= 0) {
      memset(to[tot], 0, sizeof to[tot]);
      slnk[tot] = 0;
      pos[tot] = -1;
      ppos[tot].clear();
      tot--;
   }
   order.clear();
   tot = 0;
}

int add(string s) {
   int u = 0;
   for (auto c : s) {
      if (!to[u][c]) to[u][c] = ++tot;
      u = to[u][c];
   }
   return u;
}

void build() {
   queue <int> q;
   q.push(0);
   while (!q.empty()) {
      int p = q.front(); q.pop(); order.push_back(p);
      for (int c = 0; c < C; c++) {
         int u = to[p][c];
         if (!u) continue;
         q.push(u);
         if (!p) {
            continue;
         }
         int v = slnk[p];
         while (v and !to[v][c]) {
            v = slnk[v];
         }
         slnk[u] = to[v][c];
      }
   }
}

void solve() {
   int n;
   memset(pos, -1, sizeof pos);
   while (cin >> n) {
      cin.ignore();
      init();
      string arr[n], s;
      map <string, int> mp;
      for (int i = 0; i < n; i++) {
         getline(cin, arr[i]);
         int v = add(arr[i]);
         pos[v] = i;
         mp[arr[i]] = i;
      }
      build();
      getline(cin, s);
      int u = 0;
      for (int i = 0; i < s.size(); i++) {
         while (u and !to[u][s[i]]) {
            u = slnk[u];
         }
         u = to[u][s[i]];
         ppos[u].insert(i);
      }
      vector<int> ans[n];
      reverse(order.begin(), order.end());
      for (int i : order) {
         if (pos[i] != -1) for (int x : ppos[i]) ans[pos[i]].push_back(x);
         if (ppos[i].size() > ppos[slnk[i]].size()) {
            swap(ppos[i], ppos[slnk[i]]);
         }
         if (i != slnk[i]) {
            for (int x : ppos[i]) ppos[slnk[i]].insert(x);
         }
      }
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < ans[mp[arr[i]]].size(); j++) {
            int x = ans[mp[arr[i]]][j];
            if (j) cout << " ";
            cout << x - arr[i].size() + 1;
         }
         cout << "\n";
      }
   }
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