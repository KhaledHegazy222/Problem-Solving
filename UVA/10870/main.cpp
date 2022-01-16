
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()


typedef unsigned long long ull;
typedef long long ll;

using namespace std;
int MOD = 1e9;


int k,n,B[15],C[15];

void print(vector<vector<int>> x){
    for(int i = 0;i<x.size();i++){
        for(int j = 0;j < x[0].size();j++){
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> mul(vector<vector<int>>& a,vector<vector<int>>& b){
    int l = a.size();
    int m = a[0].size();
    int r = b[0].size();
    vector<vector<int>> res(l,vector<int>(r));
    for(int i = 0;i<l;i++){
        for(int j = 0;j<m;j++){
            for(int k = 0;k<r;k++){
                res[i][k] += (1ll *a[i][j] * b[j][k]) % MOD;
                res[i][k] %= MOD; 
            }
        }
    }
    return res;
}



int l_rec(int n){
    vector<vector<int>> a(1,vector<int>(k));
    vector<vector<int>> b(k,vector<int>(k));

    vector<vector<int>> res(k,vector<int>(k));
    for(int i = 0;i<k;i++){
        a[0][i] = B[i];
        res[i][i] = 1;
        b[i][k-1] = C[k-i-1];
    }

    for(int i = 1;i<k;i++){
        b[i][i-1] = 1;
    }


    while(n){
        if(n & 1){
            res = mul(res,b);
        }

        b = mul(b,b);
        n /= 2;
    }

    a = mul(a,res);

    return a[0][a[0].size()-1];
}






int main(void){
   
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    while(cin >> k >> n >> MOD && k){
        for(int i = 0;i<k;i++){
            cin >> C[i];
        }
        for(int i = 0;i<k;i++){
            cin >> B[i];
        }
        if(n <= k){
            cout << B[n-1] << '\n';
        }
        else{
            cout << l_rec(n-k) << '\n';
        }


    }
}   
