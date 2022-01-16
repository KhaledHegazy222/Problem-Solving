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


vector<vector<ll>> power(vector<vector<ll>>b,ll p){
    ll d = b.size();
    vector<vector<ll>>ret(d);
    for(ll i = 0;i<d;i++){
        ret[i].resize(d);
        for(ll j = 0;j<d;j++){
            ret[i][j] = ( i == j);
        }
    }
    while(p){
        if(p & 1)
            ret = matMul(ret,b);
        b = matMul(b,b);
        p >>= 1;
    }
    return ret;
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    ll d,n,m;
    while(cin >> d >> n >> m,(d || n || m)){
        vector<vector<ll>>Mat(d);
        for(ll i = 0;i<d;i++){
            Mat[i].resize(d);
            for(ll j = 0;j<d;j++){
                Mat[i][j] = (i + 1 == j);
                if(!j)
                    cin >> Mat[i][j];
            }
        }
        MOD = m;
        vector<vector<ll>>a(1);
        a[0].resize(d);
        for(ll i = d - 1;i >= 0;i--)
            cin >> a[0][i];
        if(n <= d){
            cout << a[0][d - n] << endl;
            continue;
        }
        auto ret = power(Mat,n - d);
        a = matMul(a,ret);
        cout << a[0][0] << endl;


    }

}//




