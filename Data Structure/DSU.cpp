#include <bits/stdc++.h>
#define ll long long
using namespace std;


// DSU
const int N = 1e6+10;
int par[N], Size[N];
int parent(int n){
    if(par[n]==n) return n;
    return par[n] = parent(par[n]);
}
void Union(int a, int b){
    a = parent(a);
    b = parent(b);
    if(Size[a] > Size[b]){
        par[b] = a;
        Size[a] += Size[b];
    }
    else{
        par[a] = b;
        Size[b] += Size[a];
    }
}

int main(){}
