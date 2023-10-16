#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int caseS = 1;

const int MOD = 1000003;

ll BigMod(ll a, ll b){ //a^b %MOD
    ll res = 1;
    while(b){
        if(b&1) {
            res*=a;
            res %= MOD;
        }
        a*=a;
        a%=MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
	ll a, r, n; cin >> a >> r >> n; //a = first value r = ratio, n = n-term
	ll res = BigMod(r, n);
	ll numara = (a*(1-res))%MOD;
	numara = (numara+MOD)%MOD;
	ll deno = ((1-r)%MOD+MOD)%MOD;

	ll ans = (numara*BigMod(deno, MOD-2)) % MOD;
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}