#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define lll __int128
#define ff first
#define ss second
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
ll inf = 1000000009;
int caseS = 1;

ll arr[N];
tuple<ll, ll, ll, ll> segment[4*N];
//seg, pref, suf, sum

void built(int node, int st, int ed){
	if(st==ed){
		segment[node] = {arr[st], arr[st], arr[st], arr[st]};
		return;
	}
	int mid = (st+ed)/2;
	built(2*node, st, mid);
	built(2*node+1, mid+1, ed);
	auto [seg1, pref1, suf1, sum1] = segment[2*node];
	auto [seg2, pref2, suf2, sum2] = segment[2*node+1];
	ll seg = max(seg1, max(seg2, suf1+pref2));
	ll pre = max(pref1, sum1+pref2);
	ll suf = max(suf2, sum2+suf1);	
	ll sum = sum1 + sum2;
	segment[node] = {seg, pre, suf, sum};
}

tuple<ll, ll, ll, ll> query(int node, int st, int ed, int l, int r){
	if(st>=l and ed<=r) return segment[node];
	if(st>r or ed<l) return {-inf, -inf, -inf, -inf};
	int mid = (st+ed)/2;
	auto [seg1, pref1, suf1, sum1] = query(2*node, st, mid, l, r);
	auto [seg2, pref2, suf2, sum2] = query(2*node+1, mid+1, ed, l, r);
	ll seg = max(seg1, max(seg2, suf1+pref2));
	ll pre = max(pref1, sum1+pref2);
	ll suf = max(suf2, sum2+suf1);	
	ll sum = sum1 + sum2;
	return {seg, pre, suf, sum};
}

void update(int node, int st, int ed, int idx, int val){
	if(st==ed){
		segment[node] = {val, val, val, val};
		return;
	}
	int mid = (st+ed)/2;
	if(idx <= mid){
		update(2*node, st, mid, idx, val);
	}
	else{
		update(2*node+1, mid+1, ed, idx, val);
	}
	auto [seg1, pref1, suf1, sum1] = segment[2*node];
	auto [seg2, pref2, suf2, sum2] = segment[2*node+1];
	ll seg = max(seg1, max(seg2, suf1+pref2));
	ll pre = max(pref1, sum1+pref2);
	ll suf = max(suf2, sum2+suf1);	
	ll sum = sum1 + sum2;
	segment[node] = {seg, pre, suf, sum};
}

void solve(){
	int n, q; cin >> n >> q;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	built(1, 1, n);
	auto [seg1, pref1, suf1, sum1] = segment[1];
	ll ans = max(seg1, max(pref1, max(suf1, sum1)));
	cout << max(0ll, ans) << "\n";
	while(q--){
		int ct, l, r; cin >> l >> r;
		l++;
		update(1, 1, n, l, r);
		auto [seg, pref, suf, sum] = segment[1];
		ll ans = max(seg, max(pref, max(suf, sum)));
		cout << max(0ll, ans) << "\n";
	}
	
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