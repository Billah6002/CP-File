#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Recursive
// ll extended_euclidean(ll a, ll b, ll& x, ll& y) {
//     if (b == 0) {
//         x = 1;
//         y = 0;
//         return a;
//     }
//     ll x1, y1;
//     ll d = extended_euclidean(b, a % b, x1, y1);
//     x = y1;
//     y = x1 - y1 * (a / b);
//     return d;
// }

//Iterative
ll extended_euclidean(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}


int main(){
    ll x, y;
    ll a=5, m=7; //a = ?/a and m = MOD;
    ll g = extended_euclidean(a, m, x, y);
    if (g != 1) {
        cout << "No solution!";
    }
    else {
        x = (x % m + m) % m;
        cout << x << endl;
    }
}