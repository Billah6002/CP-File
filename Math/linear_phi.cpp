#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 10;
int phi[N], primes[N / 10];
bool com[N];
int pcnt = 0;

void totient() {
  phi[1] = 1;
  for (int i = 2; i < N; i++) {
    if (!com[i]) {
      primes[pcnt++] = i;
      phi[i] = i - 1;
    }
    for (int j = 0; j < pcnt; j++) {
      int p = primes[j];
      if (1LL * i * p >= N) break;
      com[i * p] = true;
      if (i % p == 0) {
        phi[i * p] = phi[i] * p;
        break;
      } else {
        phi[i * p] = phi[i] * (p - 1);
      }
    }
  }
}

const int mod = 1e9 + 7;
ll BigMod(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}

void solve() {
  totient();
  int n, k; cin >> n >> k;
  ll ans = 0;
  for (int d = 1; d <= k; d++) {
    ans += 1ll * phi[d] * BigMod(k / d, n) % mod;
    ans %= mod;
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
