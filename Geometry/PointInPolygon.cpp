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

bool intersect(point a, point b, point c, point d) {
	if ((b - a) * (d - c) == 0) {
		if (a.triangle(b, c) != 0) {
			return false;
		}
		for (int i = 0; i < 2; i++) {
			if (max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y)) {
				return false;
			}
			swap(a, c);
			swap(b, d);
		}
		return true;
	}
	for (int i = 0; i < 2; i++) {
		ll s1 = (b - a) * (c - a);
		ll s2 = (b - a) * (d - a);
		if ((s1 < 0 and s2 < 0) or (s1 > 0 and s2 > 0)) {
			return false;
		}
		swap(a, c);
		swap(b, d);
	}
	return true;
}

bool is_on_segment(point a, point b, point c) {
	if (a.triangle(b, c) != 0) {
		return false;
	}
	ll nx = min(a.x, b.x);
	ll mx = max(a.x, b.x);
	ll ny = min(a.y, b.y);
	ll my = max(a.y, b.y);

	return (nx <= c.x and c.x <= mx) and (ny <= c.y and c.y <= my);
}

void solve() {
	int n, m; cin >> n >> m;
	point arr[n];
	for (int i = 0; i < n; i++) {
		arr[i].read();
	}

	while (m--) {
		point p;
		p.read();
		point ed = {p.x + 1, 3000000001LL};

		int cnt = 0;
		bool boun = false;
		for (int i = 0; i < n; i++) {
			int j = i + 1;
			if (j == n) j = 0;
			if (is_on_segment(arr[i], arr[j], p)) {
				boun = true;
				break;
			}
			if (intersect(arr[i], arr[j], p, ed)) {
				cnt++;
			}
		}
		if (boun) {
			cout << "BOUNDARY\n";
		}
		else if (cnt % 2 == 0) {
			cout << "OUTSIDE\n";
		}
		else cout << "INSIDE\n";
	}

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