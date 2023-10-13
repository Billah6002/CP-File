#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Max SIeve
const int N= 1e7+10;
int MaxSieve[N];
vector <int> prime;
void sieve(){
    MaxSieve[0] = MaxSieve[1] = 1;
    for(ll i=2; i<N; i++){
        if(MaxSieve[i]==0){
            prime.push_back(i);
            for(ll j=i*i; j<N; j+=i){
                MaxSieve[j] = 1;
            }
        }
    }
}
int main(){

}