#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __ll128
#define ff first
#define ss second
ll caseS = 1;

vector <ll> fact(21, 1);

//does not handle if given ff-th permutation does not exist
string n_th_Permutation(string s, ll ff){
	int n = s.size();
	for(int i=0; i<n; i++){
		sort(s.begin()+i, s.end());
		int pos = i+ff/fact[n-1-i];
		ff %= fact[n-1-i];
		swap(s[i], s[pos]);
	}
	return s;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt = 1;
    for(int i=1; i<21; i++){
    	fact[i] = fact[i-1] * i;    	
    }

    cin >> tt;
    while(tt--){
        string s; cin >> s;
        ll n; cin >> n;
        cout << n_th_Permutation(s, n) << "\n";
    }
}