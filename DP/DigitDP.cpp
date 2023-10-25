//https://vjudge.net/problem/LightOJ-1068
//Investigation LightOJ - 1068 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
#define ff first
#define ss second
int caseS = 1;

int a, b, c;
vector <int> num;

int dp[10][90][90][2];

int fun(int pos, int digSum, int dig, int smaint){
    if(pos==num.size()){
        if(!dig and !digSum) return 1;
        return 0;
    }
    if(dp[pos][digSum][dig][smaint] != -1) return dp[pos][digSum][dig][smaint];
    int ans = 0;
    int limit = num[pos];
    if(smaint == 1) limit = 9;

    for(int i=0; i<=limit; i++){
        int nsm = (i < num[pos] || smaint);
        int ndigSum = (digSum + i) % c;
        int ndig = (dig* 10 + i) % c;

        ans += fun(pos+1, ndigSum, ndig, nsm);
    }

    return dp[pos][digSum][dig][smaint] = ans;

}

void solve(){
    cin >> a >> b >> c;
    cout << "Case " << caseS++ << ": ";
    if(c >= 100) {
        cout << "0\n";
        return;
    }
    num.clear();
    memset(dp, -1, sizeof(dp));
    while(b){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());

    int ans1 = fun(0, 0, 0, 0); // pos, digSum, dig, smaint

    num.clear();
    memset(dp, -1, sizeof(dp));
    a--;
    while(a){
        num.push_back(a%10);
        a/=10;
    }
    reverse(num.begin(), num.end());

    int ans2 = fun(0, 0, 0, 0); // pos, digSum, dig, smaint

    cout << ans1 - ans2 << "\n";

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1; 
    cin >> tt;
    while(tt--){
        solve();
    }
}