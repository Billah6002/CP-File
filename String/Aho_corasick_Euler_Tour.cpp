//https://www.spoj.com/problems/ADAJOBS/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6 + 10, C = 26;
int to[N][C], tot, slink[N], tin[N], tout[N], timer;
vector<int> ad[N];

int add(string &s) {
   int u = 0;
   for (auto c : s) {
      c -= 'a';
      if (!to[u][c]) to[u][c] = ++tot;
      u = to[u][c];
   }
   return u;
}
void dfs(int node, int par) {
   tin[node] = timer++;
   for (int v : ad[node]) {
      if (v != par) dfs(v, node);
   }
   tout[node] = timer - 1;
}

void build() {
   queue <int> q; q.push(0);
   while (!q.empty()) {
      int p = q.front(); q.pop();
      for (int c = 0; c < C; c++) {
         int u = to[p][c];
         if (!u) continue;
         q.push(u);
         if (!p) {
            ad[p].push_back(u);
            continue;
         }
         int v = slink[p];
         while (v and !to[v][c]) v = slink[v];
         slink[u] = to[v][c];
         ad[to[v][c]].push_back(u);
      }
   }
   dfs(0, -1);
}

struct segment_tree {
   int size;
   vector <int> segment_tree;
   vector <int> lazy;

   void push(int node, int st, int ed) {
      if (lazy[node] != 0) {
         segment_tree[node] += (ed - st + 1) * lazy[node];
         if (st != ed) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
         }
         lazy[node] = 0;
      }
   }
   void init(int n) {
      size = n;
      segment_tree.assign(n * 4, 0);
      lazy.assign(4 * n, 0);
   }

   void update(int node, int st, int ed, int l, int r, int val) {
      if (lazy[node] != 0) {
         segment_tree[node] += (ed - st + 1) * lazy[node];

         if (st != ed) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
         }
         lazy[node] = 0;
      }
      if (st > r || ed < l) {
         return;
      }
      if (st >= l && ed <= r) {
         segment_tree[node] += (ed - st + 1) * val;
         if (st != ed) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
         }

         return;
      }
      int mid = (st + ed) / 2;
      update(2 * node, st, mid, l, r, val);
      update(2 * node + 1, mid + 1, ed, l, r, val);
      segment_tree[node] = segment_tree[2 * node] + segment_tree[2 * node + 1];
   }

   void update(int l, int r, int val) {
      update(1, 0, size - 1, l , r, val);
   }

   int query(int node, int st, int ed, int l, int r) {
      push(node, st, ed);
      if (st > r || ed < l) {
         return 0;
      }
      if (st >= l && ed <= r) {
         return segment_tree[node];
      }

      int mid = (st + ed) / 2;
      int leftSum = query(2 * node, st, mid, l, r);
      int rightSum = query(2 * node + 1, mid + 1, ed, l, r);
      return leftSum + rightSum;

   }
   int query(int l, int r) {
      return query(1, 0, size - 1, l, r);
   }

};

void solve() {
   int q; cin >> q;
   int tp[q], nd[q];
   string pat[q];
   for (int i = 0; i < q; i++) {
      cin >> tp[i] >> pat[i];
      if (!tp[i]) nd[i] = add(pat[i]);
   }
   build();
   segment_tree st;
   st.init(tot + 1);

   for (int i = 0; i < q; i++) {
      if (tp[i] == 0) {
         st.update(tin[nd[i]], tout[nd[i]], 1);
      }
      else {
         int u = 0, cnt = 0;
         for (auto c : pat[i]) {
            c -= 'a';
            while (u and !to[u][c]) u = slink[u];
            u = to[u][c];
            cnt += st.query(tin[u], tin[u]);
            if (cnt) break;
         }
         if (cnt) cout << "YES\n";
         else cout << "NO\n";
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