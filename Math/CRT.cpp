#include <bits/stdc++.h> 
#define ll long long
using namespace std; 

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
/** Works for non-coprime moduli.
 Returns {-1,-1} if solution does not exist or input is invalid.
 Otherwise, returns {x,L}, where x is the solution unique to mod L
 Here A is the remainder vector
*/
pair<ll, ll> CRT( vector<ll> A, vector<ll> M ) {
    if(A.size() != M.size()) return {-1,-1}; /** Invalid input*/
 
    ll n = A.size();
 
    ll a1 = A[0];
    ll m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/
 
    /** Merge the solution with remaining equations */
    for ( ll i = 1; i < n; i++ ) {
        ll a2 = A[i];
        ll m2 = M[i];
 
        ll g = __gcd(m1, m2);
        if ( a1 % g != a2 % g ) return {-1,-1}; /** No solution exists*/
 
        /** Merge the two equations*/
        ll p, q;
        extended_euclidean(m1/g, m2/g, p, q);
 
        ll mod = m1 / g * m2; /** LCM of m1 and m2*/
 
        /** We need to be careful about overflow, but I did not
         *  bother about overflow here to keep the code simple.*/
        ll x = (a1*(m2/g)*q + a2*(m1/g)*p) % mod;
 
        /** Merged equation*/
        a1 = x;
        if (a1 < 0) a1 += mod; /** Result is not suppose to be negative*/
        m1 = mod;
    }
    return {a1, m1};
}

int main() 
{	
	vector <ll> v1 = {3, 4, 5};
	vector <ll> v2 = {2, 3, 1};

	cout <<  CRT(v2, v1).first << "\n";
	return 0; 
}
