//https://cses.fi/problemset/task/2195/
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
};
 
void solve() {
	int n; cin >> n;
	point arr[n];
	for (int i = 0; i < n; i++) {
		arr[i].read();
	}
	sort(arr, arr + n);
	vector <point> hull;
	for (int i = 0; i < 2; i++) {
		int sz = hull.size();
		for (point c : arr) {
			while (hull.size() - sz >= 2) {
				point a = hull.back();
				point b = hull[hull.size() - 2];
				if (a.triangle(b, c) <= 0) {
					break;
				}
				hull.pop_back();
			}
			hull.push_back(c);
		}
		hull.pop_back();
		reverse(arr, arr + n);
	}
	cout << hull.size() << "\n";
	for (auto [x, y] : hull) {
		cout << x << " " << y << "\n";
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
