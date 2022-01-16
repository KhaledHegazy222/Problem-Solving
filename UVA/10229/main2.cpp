#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll MOD;


vector<vector<ll>> matMul(vector<vector<ll>>a,vector<vector<ll>>b){
    ll r1 = a.size();
    ll c1 = a[0].size();
    ll r2 = b.size();
    ll c2 = b[0].size();

    vector<vector<ll>>ret(r1);
    for(ll i = 0;i<r1;i++){
        ret[i].resize(c2);
        for(ll j = 0;j<c1;j++){
            for(ll k = 0;k < c2;k++){
                ret[i][k] += a[i][j] * b[j][k];
                ret[i][k] %= MOD; 
            }
        }
    }
    return ret;
}


ll power(vector<vector<ll>>b,ll p){
    vector<vector<ll>>ret = {{1,0},{0,1}};
    while(p){
        if(p & 1)
            ret = matMul(ret,b);
        b = matMul(b,b);
        p >>= 1;
    }
    vector<vector<ll>>a = {{0,1}};
    a = matMul(a,ret);
    return a[0][0];
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    vector<vector<ll>>v = {{1,1},{1,0}};
    ll n,m;
    while(cin >> n >> m){
        MOD = 1 << m;
        cout << power(v,n) << endl;
        
    }

}



