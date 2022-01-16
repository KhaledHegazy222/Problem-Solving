#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

set<int> factorize(int n){
    int notPrime = 0;
    set<int>ret;
    for(ll i = 2;i * i <= n;i++){
        if(n % i == 0){
            notPrime = 1;
            ret.insert(i);
            while(n % i == 0)
                n /= i;
        }
    }
    if(n != 1 && notPrime)
        ret.insert(n);
    return ret;
}


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    int n;
    cin >> n;
    auto st = factorize(n);
    set<int>res;
    for(auto div : st){
        for(int i = 1;i<div;i++){
            int x = n - i;
            res.insert(x);
            auto st2 = factorize(x);
            for(auto elem : st2){
                res.insert(x - (elem - 1));
            }
        }
    }
    cout << *res.begin() << endl;




}