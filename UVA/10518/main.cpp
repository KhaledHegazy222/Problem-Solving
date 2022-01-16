
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;

ll n,MOD;

void print(vvll x){
    for(int i = 0;i<x.size();i++){
        for(int j = 0;j<x[0].size();j++){
            cout << x[i][j] << " "; 
        }
        cout << endl;
    }
    cout << "----------------\n";
}




vvll mul(vvll a,vvll b){
    vvll res(a.size(),vll(b[0].size()));
    for(int i = 0;i<a.size();i++){
        for(int j = 0;j<a[0].size();j++){
            for(int k = 0;k<b[0].size();k++){
                res[i][k] += a[i][j] * b[j][k];
                res[i][k] %= MOD;
            }
        }
    }
    return res;
}



ll calls(ll fib){
    if(fib < 2) return 1 % MOD;


    fib--;



    vvll res = {{1,0,0},{0,1,0},{0,0,1}};
    vvll a = {{1,1,1}};
    vvll b = {{0,1,0},{1,1,0},{0,1,1}};



    while(fib){
        if(fib & 1)
            res = mul(res,b);
        b = mul(b,b);

        fib >>= 1;
    }
    a = mul(a,res);
    return a[0][1];

}



int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    int tc = 1;
    while(1){
        cin >> n >> MOD;
        if(!n && !MOD) return 0;
        cout << "Case " << tc++ << ": " << n << " " << MOD << " " << calls(n) << '\n';
    }






}   
