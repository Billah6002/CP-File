//https://cses.fi/problemset/task/2191
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
struct point {
	ll x, y;
	void read() {
		cin >> x >> y;
	}
	void operator -=(const point &a) {
		x -= a.x; y -= a.y;
	}
	point operator -(const point a) const {
		return point{x - a.x, y - a.y};
	}
	ll operator *(const point &a) const {
		return x * a.y - y * a.x;
	}
	ll triangle(const point &a, const point &b) {
		return (a - *this) * ( b - *this);
	}
};
 
void solve() {
	int n; cin >> n;
	point arr[n];
	for (int i = 0; i < n; i++) {
		arr[i].read();
	}
	point a = {0, 0};
	ll ans = 0;
	for (int i = 0; i + 1 < n; i++) {
		ans += a.triangle(arr[i], arr[i + 1]);
	}
	ans += a.triangle(arr[n - 1],	arr[0]);
	cout << abs(ans) << "\n";
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
}
