#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

ll BigMod(ll a, ll b){ //a^b %MOD
    a %= mod;
    ll res = 1;
    while(b){
        if(b&1) {
            res*=a;
            res %= mod;
        }
        a*=a;
        a%=mod;
        b >>= 1;
    }
    return res;
}

ll C[1010][1010];
void nCr(){
    C[0][0] = 1;
    for(int i=1; i<1010; i++){
        for(int j=0; j<=i; j++){
            if(j==0) C[i][j] = 1;
            else
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
    }
}

ll dp[1010];

ll f(ll n, ll k) { // sum(1...n) ^ k
    if(k==0) {
        return n;
    }
    if(dp[k] != -1) return dp[k];
    ll lf = BigMod(n+1, k+1);
    lf--;
    if(lf < 0) lf += mod;
    ll pw = k+1;
    ll dv = C[pw][1];
    ll mi = 0, ct = 1;
    for(int i=2; i<pw+1; i++) {
        mi += C[pw][i] * f(n, k-ct) % mod;
        ct++;
        mi %= mod;
    }
    lf -= mi;
    if(lf < 0) lf += mod;
    return dp[k] = (lf * (BigMod(dv, mod - 2))) % mod;
}
void solve() {
    nCr();
    memset(dp, -1, sizeof dp);
    ll n = 1000000000000000ll, m = 534;
    ll ans1 = f(n, m);
    cout << ans1 << "\n";
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