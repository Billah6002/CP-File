//https://www.codechef.com/problems/COUNTRBS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
//from youKnowWho
const int N = 1e6 + 9;
int power(int n, int k, const int mod) {
	int ans = 1 % mod;
	n %= mod;
	if (n < 0) n += mod;
	while (k) {
		if (k & 1) ans = 1ll * ans * n % mod;
		n = 1ll * n * n % mod;
		k >>= 1;
	}
	return ans;
}
const int mod1 = 127657753, mod2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
	pw[0] =  {1, 1};
	for (int i = 1; i < N; i++) {
		pw[i].first = 1ll * pw[i - 1].first * p1 % mod1;
		pw[i].second = 1ll * pw[i - 1].second * p2 % mod2;
	}
	ip1 = power(p1, mod1 - 2, mod1);
	ip2 = power(p2, mod2 - 2, mod2);
	ipw[0] =  {1, 1};
	for (int i = 1; i < N; i++) {
		ipw[i].first = 1ll * ipw[i - 1].first * ip1 % mod1;
		ipw[i].second = 1ll * ipw[i - 1].second * ip2 % mod2;
	}

}
struct Hashing {
	int n;
	string s;
	vector<pair<int, int>> hs;
	Hashing(string g) {
		n = g.size();
		s = g;
		hs.push_back({0, 0});
		for (int i = 0; i < n; i++) {
			pair<int, int> p;
			p.first = (hs[i].first + 1ll * pw[i].first * s[i] % mod1) % mod1;
			p.second = (hs[i].second + 1ll * pw[i].second * s[i] % mod2) % mod2;
			hs.push_back(p);
		}
	}
	pair<int, int> get_hash(int l, int r) {
		assert(1 <= l && l <= r && r <= n);
		pair<int, int> ans;
		ans.first = 1ll * (hs[r].first - hs[l - 1].first + mod1) * ipw[l - 1].first % mod1;
		ans.second = 1ll * (hs[r].second - hs[l - 1].second + mod2) * ipw[l - 1].second % mod2;
		return ans;
	}
	pair<int, int> get_hash() {
		return get_hash(1, n);
	}
};
void solve() {
	int n; cin >> n;
	string s; cin >> s;
	Hashing hash(s);

	map <pair<ll, ll>, ll> mp;
	stack <int> st;
	for (int i = 0; i < n; i++) {
		if (s[i] == ')') {
			auto it = hash.get_hash(st.top() + 1, i + 1);
			st.pop();
			mp[it]++;
		}
		else st.push(i);
	}
	ll ans = 0;
	for (auto [u, v] : mp) {
		ans += (v * (v - 1) / 2);
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	prec();
	ll tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
}
