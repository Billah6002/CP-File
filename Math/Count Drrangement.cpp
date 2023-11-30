//https://vjudge.net/problem/LightOJ-1095
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1000000007;
int caseS = 1;

ll C[1010][1010], darr[1010];
void nCr(){
    C[0][0] = 1;
    for(int i=1; i<1010; i++){
        for(int j=0; j<=i; j++){
            if(j==0) C[i][j] = 1;
            else
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
}
void darrange(){
    darr[1] = 0;
    darr[0] = 1;
    darr[2] = 1;
    for(int i=3; i<1010; i++){
        darr[i] = (i-1)*(darr[i-1] + darr[i-2]) % MOD;
    }
}
void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    ll fix = C[m][k];

    ll dpos = 0;
    for(int i=0; i<=n-m; i++){
        dpos += (C[n-m][i] * darr[n-i-k])%MOD;
        dpos %= MOD;
    }

    cout << "Case " << caseS++ << ": ";
    cout << ((fix * dpos)%MOD) << "\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    nCr();
    darrange();
    int tt = 1; 
    cin >> tt;
    while(tt--){
        solve();
    }
}