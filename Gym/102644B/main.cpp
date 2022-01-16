
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()


typedef unsigned long long ull;
typedef long long ll;
using namespace std;



const int MOD = 1e9 + 7;

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
    vector<vector<int>>res(a.size(),vector<int>(b[0].size()));
    for(int i = 0;i<a.size();i++){
        for(int j = 0;j<a[0].size();j++){
            for(int k = 0;k<b[0].size();k++){
                res[i][k] += (1ll * a[i][j] * b[j][k]) % MOD;
                res[i][k] %= MOD;
            }
        }
    }
    return res;
}



int count(ll len){

    // 1 -> Happy
    // 0 -> Sad
    vector<vector<int>>a = {{20,6},{7,19}};
    int cnt = 0;
    vector<vector<int>>res = {{1,0},{0,1}};
    vector<vector<int>>c = {{20,6},{7,19}};

    while(len){
        if(len % 2){
            res = mul(res,a);
        }        
        a = mul(a,a);
        len /= 2;

    }
    return res[1][1];
}




int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 

    ll n;
    cin >> n;
    cout << count(n);


}   