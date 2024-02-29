//https://vjudge.net/problem/AtCoder-abc259_b
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
	bool operator <(const point a) {
		return make_pair(x, y) < make_pair(a.x, a.y);
	}
	pair<double, double> rotate(double deg) {
		deg = deg * M_PI / 180.0;
		return {x * cos(deg) - y * sin(deg), x * sin(deg) + y * cos(deg)};
	}
};

void solve() {
	cout << fixed << setprecision(15);
	point a;
	a.read();
	int deg; cin >> deg;
	pair<double, double> ans = a.rotate(deg);
	cout << ans.first << " " << ans.second << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
}