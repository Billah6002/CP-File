// https://www.hackerrank.com/contests/w3/challenges/gcd-product
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1.5e7 + 10, mod = 1e9 + 7;
int mu[N], isPrime[N], primes[N], pcnt;
int fact[N], inv[N];

void mobius() {
  mu[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!isPrime[i]) {
      primes[pcnt++] = i;
      mu[i] = -1;
    }
    for (int j = 0; j < pcnt && i * primes[j] < N; j++) {
      int p = primes[j];
      isPrime[i * p] = 1;
      if (i % p == 0) {
        mu[i * p] = 0;
        break;
      } else {
        mu[i * p] = -mu[i];
      }
    }
  }
}
ll power(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}

void solve() {
  mobius();
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
  inv[N - 1] = power(fact[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) {
    inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
  }
  for (int i = 1; i < N; i++) {
    mu[i] += mu[i - 1];
  }
  int n, m; cin >> n >> m;
  if (n > m) swap(n, m);
  ll ans = 1;

  auto f = [&](int A, int B) {
    if (A > B) swap(A, B);
    ll ret = 0;
    for (int l = 1, r; l <= A; l = r + 1) {
      r = min(A / (A / l), B / (B / l));
      ret += 1ll * (mu[r] - mu[l - 1]) * (A / l) * (B / l);
    }
    return ret;
  };

  for (int l = 1, r; l <= n; l = r + 1) {
    r = min(n / (n / l), m / (m / l));
    ll pt = f(n / l, m / l);
    ll base = 1ll * fact[r] * inv[l - 1] % mod;
    ans = ans * power(base, pt) % mod;
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
