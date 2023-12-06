#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct segment_tree{
	int size;
	vector <ll> segment_tree;

	
	void built(int node, int st, int ed, vector<ll> &arr){
		if(st==ed){
			segment_tree[node] = arr[st];
			return;
		}
		int mid = (st+ed)/2;
		built(2*node, st, mid, arr);
		built(2*node+1, mid+1, ed, arr);
		segment_tree[node] = segment_tree[2*node] + segment_tree[2*node+1];
	}
	void init(ll n, vector <ll> &arr){
		size = n;
		segment_tree.assign(n*4, 0);
		built(1, 0, n-1, arr);
	}

	void update(int node, int st, int ed, int idx, int val){
		if(st==ed){
			segment_tree[node] = val;
			return;
		}
		int mid = (st+ed)/2;
		if(idx <= mid){
			update(2*node, st, mid, idx, val);
		}
		else{
			update(2*node+1, mid+1, ed, idx, val);
		}
		segment_tree[node] = segment_tree[2*node] + segment_tree[2*node+1];
	}

	void update(int idx, int val){
		update(1, 0, size-1, idx, val);
	}

	ll query(int node, int st, int ed, int l, int r){
		if(st > r || ed < l) return 0;
		if(st>=l and ed <= r) return segment_tree[node];

		int mid = (st+ed)/2;
		ll q1 = query(2*node, st, mid, l, r);
		ll q2 = query(2*node+1, mid+1, ed, l, r);

		return q1+q2;
	}
	ll query(int l, int r){
		return query(1, 0, size-1, l, r);
	}

};

void solve(){
	segment_tree st;
	int n, q; cin >> n >> q;
	vector <ll> v(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}

	st.init(n, v);
	while(q--){
		int choise; cin >> choise;
		if(choise==1){
			int id, v; cin >> id >> v;
			st.update(id, v);
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << st.query(l, r-1) << "\n";
		}
	}
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt = 1; 
    // cin >> tt;
    while(tt--){
        solve();
    }
}