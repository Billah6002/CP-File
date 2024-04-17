//https://codeforces.com/gym/101102/problem/I
#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;
int r, c;
char up, down;
ll f(ll val) {
	ll cost = 0;
	for (char c : s) {
		if (c == up) {
			val++;
			if (val > r) {
				cost++;
				val--;
			}
		}
		else {
			val--;
			if (!val) {
				cost++;
				val = 1;
			}
		}
	}
	return cost;
}
ll ternary_search(ll l, ll r) {
	while (r - l > 2) {
		ll m1 = l + (r - l) / 3;
		ll m2 = r - (r - l) / 3;
		if (f(m1) < f(m2)) {
			r = m2;
		} else {
			l = m1;
		}
	}
	// After narrowing down the llerval, search within it
	ll min_x = l;
	ll min_value = f(l);
	for (ll x = l + 1; x <= r; ++x) {
		ll curr_value = f(x);
		if (curr_value < min_value) {
			min_value = curr_value;
			min_x = x;
		}
	}
	return f(min_x);
}
void solve() {
	cin >> r >> c;
	string st, a, b; cin >> st;

	for (char c : st) {
		if (c == '^' or c == 'v') a.push_back(c);
		else b.push_back(c);
	}
	s = a;
	up = '^';
	down = 'v';
	ll ans1 = ternary_search(1, r);
	r = c;
	s = b;
	up = '>'; down = '<';
	ll ans2 = ternary_search(1, c);
	cout << ans1 + ans2 << "\n";

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
}
