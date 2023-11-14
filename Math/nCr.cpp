#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int C[1010][1010];
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


void solve(){
    nCr();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1; 
    // cin >> tt;
    while(tt--){
        solve();        
    }
}