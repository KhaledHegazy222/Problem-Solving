#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int MOD = 1e9 + 7;


vector<vector<int>> matMul(vector<vector<int>>a,vector<vector<int>>b){
    int r1 = a.size();
    int c1 = a[0].size();
    int r2 = b.size();
    int c2 = b[0].size();

    vector<vector<int>>ret(r1,vector<int>(c2));
    for(int i = 0;i<r1;i++){
        for(int j = 0;j<c1;j++){
            for(int k = 0;k < c2;k++){
                ret[i][k] = (ret[i][k] + 1ll * a[i][j] * b[j][k]) % MOD;
            }
        }
    }
    return ret;
}


vector<vector<int>> power(vector<vector<int>>b,int p){
    int d = b.size();
    vector<vector<int>>ret(d,vector<int>(d));
    for(int i = 0;i<d;i++){
        for(int j = 0;j<d;j++){
            ret[i][j] = (i == j);
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

    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>>a (1,vector<int>(n,1));
    vector<vector<int>>Mat (n,vector<int>(n));
    while(m--){
        int a,b;
        cin >> a >> b;
        --a,--b;
        Mat[a][b] = 1;
    }
    Mat = power(Mat,k);
    a = matMul(a,Mat);
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum = (0ll + sum + a[0][i]) % MOD;
    }
    cout << sum << endl;
}   



