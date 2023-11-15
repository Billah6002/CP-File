//https://vjudge.net/problem/UVA-10689
//UVA - 10689
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 10000;

vector <vector<ll>> matrix_multi(vector <vector<ll>> &A, vector <vector<ll>> &B){
    vector <vector<ll>> C(A.size(), vector<ll>(B[0].size(), 0));
    for (int i = 0; i < A.size(); i++){
        for (int j = 0; j < B[0].size(); j++){
            for (int k = 0; k < B.size(); k++){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

void solve(){
	vector <vector<ll>> E_matrix = {{1, 0}, {0, 1}};
	vector <vector<ll>> T_matrix = {{0, 1}, {1, 1}};
	vector <vector<ll>> F_matrix;

	for(int i=0; i<2; i++){
		int val; cin >> val;
		F_matrix.push_back({val});
	}

	ll n, m; cin >> n >> m;
	while(n){
		if(n&1){
			E_matrix = matrix_multi(E_matrix, T_matrix);
		}
		n>>=1;
		T_matrix = matrix_multi(T_matrix, T_matrix);
	}

	E_matrix = matrix_multi(E_matrix, F_matrix);

	ll dig = 1;
	while(m--) dig*=10;
	cout << E_matrix[0][0]%dig << "\n";
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