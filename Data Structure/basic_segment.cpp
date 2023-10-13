#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Segment tree
const int N = 1e5;
ll seg_tree[4*N], arr[N];

void built(int node, int st, int ed){
	if(st==ed){
		seg_tree[node] = arr[st];
		return;
	}

	int mid = (st+ed)/2;
	built(2*node, st, mid);
	built(2*node+1, mid+1, ed);

	seg_tree[node] = seg_tree[2*node] + seg_tree[2*node+1];
}

void update(int node, int st, int ed, int idx, int val){
	if(st==ed){
		arr[idx] = val;
		seg_tree[node] = val;
		return;
	}
	int mid = (st+ed)/2;
	if(idx <= mid){
		update(2*node, st, mid, idx, val);
	}
	else{
		update(2*node+1, mid+1, ed, idx, val);
	}
	seg_tree[node] = seg_tree[2*node] + seg_tree[2*node+1];
}

ll query(int node, int st, int ed, int l, int r){
	if(st > r || ed < l) return 0;
	if(st>=l and ed <= r) return seg_tree[node];

	int mid = (st+ed)/2;
	ll q1 = query(2*node, st, mid, l, r);
	ll q2 = query(2*node+1, mid+1, ed, l, r);

	return q1+q2;
}


int main(){

}
