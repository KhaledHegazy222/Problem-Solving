#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int M = 2e5 + 2, MOD = 1e9 + 7;
int A[10][M];

void modify(vector<int>&v){
    vector<int>x(v);
    for(int i = 1;i<10;i++){
        v[i] = x[i - 1];
    }
    v[0] = x[9];
    v[1] += x[9];
    for(int i = 0;i<10;i++){
        if(v[i] >= MOD)
            v[i] -= MOD;
    }

}



int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    for(int i = 0;i<10;i++){
        vector<int>v(10);
        v[i] = 1;
        for(int j = 0;j<M;j++){
            ll sum = 0;
            for(auto it : v){
                sum = (sum + it) % MOD;
            }
            A[i][j] = sum;
            modify(v);
        }
    }

    int t;
    cin >> t;
    while(t--){
        int m;
        string s;
        cin >> s >> m;
        ll sum = 0;
        for(int i = 0;i<10;i++){
            ll cnt = count(all(s),'0' + i);
            sum = (sum +  A[i][m] * cnt )   % MOD;   
        }
        
        cout << sum << '\n';
    }

}