//https://cses.fi/problemset/task/2190/
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
	point a, b, c, d;
	a.read();
	b.read();
	c.read();
	d.read();
 
	if ((b - a) * (d - c) == 0) {
		if (a.triangle(b, c) != 0) {
			cout << "NO\n";
			return;
		}
		for (int i = 0; i < 2; i++) {
			if (max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y)) {
				cout << "NO\n";
				return;
			}
			swap(a, c);
			swap(b, d);
		}
		cout << "YES\n";
		return;
	}
	for (int i = 0; i < 2; i++) {
		ll s1 = (b - a) * (c - a);
		ll s2 = (b - a) * (d - a);
		if ((s1 < 0 and s2 < 0) or (s1 > 0 and s2 > 0)) {
			cout << "NO\n";
			return;
		}
		swap(a, c);
		swap(b, d);
	}
	cout << "YES\n";
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
}