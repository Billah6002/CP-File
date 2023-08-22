#include <bits/stdc++.h>
using namespace std;
#define ll long long

int MaxSieve[10000000];
vector <int> prime;

void sieve(){
    
    MaxSieve[0] = MaxSieve[1] = 1;

    for(ll i=2; i<10000000; i++){
        if(MaxSieve[i]==0){
            prime.push_back(i);
            for(ll j=i*i; j<10000000; j+=i){
                MaxSieve[j] = 1;
            }
        }
    }
}
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


int par[N], Size[N];
int parent(int n){
    if(par[n]==n) return n;
    return par[n] = parent(par[n]);
}
void Union(int a, int b){
    a = parent(a);
    b = parent(b);
    if(Size[a] > Size[b]){
        par[b] = a;
        Size[a] += Size[b];
    }
    else{
        par[a] = b;
        Size[b] += Size[a];
    }
}
int main(){

}
