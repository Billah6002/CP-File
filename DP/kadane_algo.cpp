#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll kadane_algo(vector <ll> &v){
	ll mx = -1e18, max_end = 0;
	for(int i=0; i<v.size(); i++){
		max_end += v[i];
		if(max_end > mx){
			mx = max_end;
		}
		if(max_end < 0) max_end = 0;
	}
	return mx;
}

void solve(){
	vector <ll> v = {1, 2, -5, 6};
    cout << kadane_algo(v) << "\n";
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