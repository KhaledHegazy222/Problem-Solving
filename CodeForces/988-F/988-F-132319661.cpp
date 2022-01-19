#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 2e3 + 5;

int n,m,a;


int type[N],existUmp[N],weight[N];


int dp[N][N];


int solve(int idx,int holding){
    if(!~holding && type[idx]){
        return 1e9;
    }
    if(idx == a)
        return 0;

    int &ret = dp[idx][holding + 1];
    if(~ret)
        return ret;
    ret = 1e9;
    if(~holding){ // holding one
        ret = min(ret,weight[holding] + solve(idx + 1,holding));
    }
    ret = min(ret,solve(idx + 1,-1));
    if(existUmp[idx])
        ret = min(ret,weight[idx] +  solve(idx + 1,idx));
    

    return ret;


}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif

    cin >> a >> n >> m;
    for(int i = 0;i < n;i++){
        int l,r;
        cin >> l >> r;
        for(int j = l + 1;j <= r;j++)
            type[j] = 1;
    }
    // for(int i = 1;i <= a;i++){
    //     if(type[i] && type[i - 1])
    //         type[i] = 2;
    // }
    // for(int i = 0;i<=a;i++){
    //     if(type[i] == 2)
    //         type[i] = 1;
    //     else    
    //         type[i] = 0;
    // }
    for(int i = 0;i<m;i++){
        int pos,w;
        cin >> pos >> w;
        if(existUmp[pos]){
            weight[pos] = min(weight[pos],w);
        }
        else{
            existUmp[pos] = 1;
            weight[pos] = w;
        }
    }


    memset(dp,-1,sizeof dp);

    cout << (solve(0,-1) >= 1e9 ? -1 : solve(0,-1)) << endl;



}