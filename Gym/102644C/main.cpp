


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()


typedef unsigned long long ull;
typedef long long ll;

using namespace std;
const int MOD = 1e9 + 7;

void print(vector<vector<int>>&a){
    for(int i = 0;i<a.size();i++){
        for(int j = 0;j<a[0].size();j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


vector<vector<int>> mul(vector<vector<int>>&a,vector<vector<int>>&b){
    int left = a.size();
    int middle = a[0].size();
    int right = b[0].size();
    vector<vector<int>>res(left,vector<int>(right));
    for(int i = 0;i<left;i++){
        for(int j = 0;j<middle;j++){
            for(int k = 0;k<right;k++){
                res[i][k] += (1ll * a[i][j] * b[j][k])%MOD;
                res[i][k] %= MOD;
            }
        }
    }
    return res;
}



int fib(ll x){
    vector<vector<int>>a(2,vector<int>(1));
    vector<vector<int>>b(2,vector<int>(2));
    b[0][0] = 0;
    b[0][1] = b[1][0] = b[1][1] = 1;
    a[0][0] = 0;
    a[1][0] = 1;
    vector<vector<int>>res(2,vector<int>(2));
    res[0][0] = res[1][1] = 1;
    while(x){
        if(x % 2){
            res = mul(res,b);
        }
        b = mul(b,b);
        x /= 2;
    }

    a = mul(res,a);
    return a[0][0];



}

int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    ll x;
    cin >> x;
    cout << fib(x);
    
}   


