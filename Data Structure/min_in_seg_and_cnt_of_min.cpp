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
pair<int, int> segment[4*N];

void built(int node, int st, int ed){
	if(st==ed){
		segment[node].ff = arr[st];
		segment[node].ss = 1;
		return;
	}
	int mid = (st+ed)/2;
	built(2*node, st, mid);
	built(2*node+1, mid+1, ed);
	if(segment[2*node].ff == segment[2*node+1].ff){
		segment[node].ff = segment[2*node].ff;
		segment[node].ss = segment[2*node].ss + segment[2*node+1].ss;
	}
	else if(segment[2*node].ff < segment[2*node+1].ff){
		segment[node]=segment[2*node];
	}
	else{
		segment[node]=segment[2*node+1];
	}
}

pair <int, int> query(int node, int st, int ed, int l, int r){
	if(st>=l and ed <= r){
		return segment[node];
	}
	if(ed<l or st>r) return {inf, 0};

	int mid = (st+ed)/2;
	pair <int, int> q1 = query(2*node, st, mid, l, r);
	pair <int, int> q2 = query(2*node+1, mid+1, ed, l, r);

	if(q1.ff == q2.ff){
		q1.ss += q2.ss;
		return q1;
	}
	else if(q1.ff < q2.ff){
		return q1;
	}
	else{
		return q2;
	}
}
void update(int node, int st, int ed, int idx, int val){
	if(st==ed){
		segment[node].ff=val;
		segment[node].ss = 1;
		return;
	}
	int mid = (st+ed)/2;
	if(idx<=mid){
		update(2*node, st, mid, idx, val);
	}
	else{
		update(2*node+1, mid+1, ed, idx, val);
	}
	if(segment[2*node].ff == segment[2*node+1].ff){
		segment[node].ff = segment[2*node].ff;
		segment[node].ss = segment[2*node].ss + segment[2*node+1].ss;
	}
	else if(segment[2*node].ff < segment[2*node+1].ff){
		segment[node]=segment[2*node];
	}
	else{
		segment[node] = segment[2*node+1];
	}
}

void solve(){
	int n, q; cin >> n >> q;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}
	built(1, 1, n);
	while(q--){
		int ct, l, r; cin >> ct >> l >> r;
		l++;
		if(ct==1) update(1, 1, n, l, r);
		else {
			pair <int, int> ans = query(1, 1, n, l, r);
			cout << ans.ff << " " << ans.ss << "\n";
		}
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