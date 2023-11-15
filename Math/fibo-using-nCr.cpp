//https://vjudge.net/problem/UVA-900
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll inf = 1000000009;
int caseS = 1;

ll C[100][100];
void nCr(){
    C[0][0] = 1;
    for(int i=1; i<100; i++){
        for(int j=0; j<=i; j++){
            if(j==0) C[i][j] = 1;
            else
                C[i][j] = (C[i-1][j-1] + C[i-1][j]);
        }
    }
}

void solve(){
    ll n;
    while(cin >> n and n){
        ll ans = 0;
        for(int i=0; i<=n/2; i++){
        	ans += C[n-i][i];
        }
        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1; 
    nCr();
    // cin >> tt;
    while(tt--){
        solve();        
    }
}