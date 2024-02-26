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
	ll boundery = 0;
	point a = {0, 0};
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		point dff = arr[j] - arr[i];
		ans += a.triangle(arr[i], arr[j]);
		ll g = gcd(abs(dff.x), abs(dff.y));
		boundery += g;
	}
	ans = abs(ans);
	ll interior = (ans - boundery + 2) / 2;
	cout << interior << " " << boundery << "\n";

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
