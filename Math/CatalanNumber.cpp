//https://vjudge.net/problem/UVA-991
//UVA - 991
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int caseS = 1;

ll C[50];

void CatalanNumber(){
    C[0] = C[1] = 1;
    for(int i=2; i<50; i++){
        for(int k=0; k<i; k++){
            C[i] += C[k]*C[i-1-k];
        }
    }
}

void solve(){
    ll n;
    while(cin >> n){
        if(caseS != 1) cout << "\n";
        caseS++;
        cout << C[n] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1; 
    CatalanNumber();
    
    // cin >> tt;
    while(tt--){
        solve();        
    }
}