//https://codeforces.com/contest/651/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;              
        }
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

void solve(){
    int n; cin >> n;

    pair<int, int> arr[n];

    unordered_map<ll, ll> mx, my;
    unordered_map<pair<int, int>, int, hash_pair> mc;
    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        arr[i].ff = x; arr[i].ss = y;
        mx[x]++;
        my[y]++;
        mc[{x, y}]++;
    }
    ll ans = 0;
    for(int i=0; i<n; i++){
        auto [u, v] = arr[i];
        ans += mx[u]-1;
        ans += my[v] - (mc[arr[i]]-1) - 1;
        mx[u]--;
        my[v]--;
        mc[arr[i]]--;
    }
    cout << ans << "\n";
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