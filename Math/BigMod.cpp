#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1e9+7;

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

int main(){
    cout << BigMod(25, 2256) << "\n";
}