#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define lll __int128
#define ff first
#define ss second
typedef tree<ll, null_type, less_equal <ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
const ll N = 1e5 + 10;
const ll MOD = 1e9+7;
ll inf = 1e18;
ll caseS = 1;

struct segment_tree{
	int size;
	vector <ll> segment_tree;
	vector <ll> lazy;

	void push(ll node, ll st, ll ed){
		if (lazy[node] != 0) {
            segment_tree[node] += (ed - st + 1) * lazy[node];

            if (st != ed) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
	}
	void built(ll node, ll st, ll ed, vector <ll> &arr){
		if(st==ed){
			segment_tree[node] = arr[st];
			return;
		}
		int mid = (st + ed)/2;
		built(2*node, st, mid, arr);
		built(2*node+1, mid+1, ed, arr);
		segment_tree[node] = segment_tree[2*node] + segment_tree[2*node + 1];
	}
	void init(ll n, vector <ll> &arr){
		size = n;
		segment_tree.assign(n*4, 0);
		lazy.assign(4*n, 0);
		// built(1, 0, n-1, arr);
	}

	void update(int node, ll st, ll ed, ll l, ll r, ll val){
		
	    if (lazy[node] != 0) {
            segment_tree[node] += (ed - st + 1) * lazy[node];

            if (st != ed) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        if (st > r || ed < l) {
            return;
        }
        if (st >= l && ed <= r) {
            segment_tree[node] += (ed - st + 1) * val;
            if (st != ed) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }

            return;
        }
        int mid = (st + ed) / 2;
        update(2 * node, st, mid, l, r, val);
        update(2 * node + 1, mid + 1, ed, l, r, val);
        segment_tree[node] = segment_tree[2 * node] + segment_tree[2 * node + 1];
	}

	void update(int l, int r, int val){
		update(1, 0, size-1, l , r, val);
	}

	ll query(ll node, ll st, ll ed, ll l, ll r){
		push(node, st, ed);
        if (st > r || ed < l) {
            return 0;
        }
        if (st >= l && ed <= r) {
            return segment_tree[node];
        }

        int mid = (st + ed) / 2;
        ll leftSum = query(2 * node, st, mid, l, r);
        ll rightSum = query(2 * node + 1, mid + 1, ed, l, r);
        return leftSum + rightSum;
    
	}
	ll query(int l, int r){
		return query(1, 0, size-1, l, r);
	}

};

void solve(){
	segment_tree st;
	int n, q; cin >> n >> q;
	vector <ll> v(n, 0);
	for(int i=0; i<n; i++){
		v[i] = 0;
	}

	st.init(n, v);
	while(q--){
		int choise; cin >> choise;
		if(choise==1){
			int l, r, v; cin >> l >> r >> v;
			st.update(l, r-1, v);
		}
		else{
			int l, r;
			cin >> l >> r;
			// cout << st.query(l, r-1) << "\n";
			long long ans = st.query(l, r-1);
			cout << ans << "\n";
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