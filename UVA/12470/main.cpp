

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()


typedef unsigned long long ull;
typedef long long ll;
using namespace std;



const int MOD = 1e9 + 9;

void print(vector<vector<int>> x){
    for(int i = 0;i<x.size();i++){
        for(int j = 0;j<x[0].size();j++){
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}



vector<vector<int>> mul(vector<vector<int>>a,vector<vector<int>>b){
    int l = a.size();
    int mid = a[0].size();
    int r = b[0].size();
    vector<vector<int>>res(l,vector<int>(r));
    for(int i = 0;i<l;i++){
        for(int j = 0;j<mid;j++){
            for(int k = 0;k<r;k++){
                res[i][k] += (1ll * a[i][j] * b[j][k]) % MOD;
                res[i][k] %= MOD;
            }
        }
    }
    return res;
}


int fib(ll n){
    if(n<3) return n;
    n-=2;
    vector<vector<int>> res = {{1,0,0},{0,1,0},{0,0,1}};
    vector<vector<int>> a = {{0,0,1},{1,0,1},{0,1,1}};  
    while(n){
        if(n & 1)
            res = mul(res,a);

        a = mul(a,a);
        n/=2;
    }
    
    res = mul({{0,1,2}},res);
    return res[0][res[0].size()-1];
}




int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 


    ll n;
    while(cin >> n && n){
        cout << fib(--n) << endl;
    }


}   