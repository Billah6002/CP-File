// https://atcoder.jp/contests/abc150/tasks/abc150_d
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/** Works for non-coprime moduli.
Returns {-1,-1} if the solution does not exist or
input is invalid.
Otherwise, returns {x,L}, where x is the
solution unique to mod L
Here A is the remainder vector M is moduli
vector
*/
ll extended_euclidean(ll a, ll b, ll& x, ll& y) {
   x = 1, y = 0;
   ll x1 = 0, y1 = 1, a1 = a, b1 = b;
   while (b1) {
      ll q = a1 / b1;
      tie(x, x1) = make_tuple(x1, x - q * x1);
      tie(y, y1) = make_tuple(y1, y - q * y1);
      tie(a1, b1) = make_tuple(b1, a1 - q * b1);
   }
   return a1;
}
pair<ll, ll> CRT( vector<ll> A, vector<ll> M ) {
   ll n = A.size();
   ll a1 = A[0];
   ll m1 = M[0];
   for ( ll i = 1; i < n; i++ ) {
      ll a2 = A[i];
      ll m2 = M[i];
      ll g = __gcd(m1, m2);
      if ( a1 % g != a2 % g) return { -1, -1};
      ll p, q;
      extended_euclidean(m1 / g, m2 / g, p, q);
      ll mod = m1 / g * m2;
      if (mod > 1e10) return { -1, -1};
      ll x = (a1 * (m2 / g) * q + a2 * (m1 / g) * p) % mod;
      a1 = x;
      if (a1 < 0) a1 += mod;
      m1 = mod;
   }
   return {a1, m1};
}

void solve() {
   ll n, m; cin >> n >> m;
   vector<ll> A(n), M(n);
   for (int i = 0; i < n; i++) {
      ll x; cin >> x;
      A[i] = x / 2;
      M[i] = x;
   }
   auto ans = CRT(A, M);
   if (ans.first == -1 or ans.first > m) {
      cout << "0\n";
      return;
   }
   cout << (m - ans.first) / ans.second + 1 << "\n";

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
