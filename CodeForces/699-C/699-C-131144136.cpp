#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e2 + 5;

int A[N],n;


int dp[N][4];

int solve(int idx,int last){
    if(idx == n)
        return 0;
    

    int &ret = dp[idx][last];
    if(~ret)
        return ret;


    ret = 1 + solve(idx + 1,0);
    if(A[idx] == 1){
        if(!((last >> 0) & 1)){
            ret = min(ret,solve(idx + 1,1));
        }
    }
    else if(A[idx] == 2){
        if(!((last >> 1) & 1)){
            ret = min(ret,solve(idx + 1,2));
        }
    }
    else if(A[idx] == 3){
        if(last == 0){
            ret = min(ret,solve(idx + 1,1));
            ret = min(ret,solve(idx + 1,2));    
            ret = min(ret,solve(idx + 1,3));
        }
        else if(last == 1){
            ret = min(ret,solve(idx + 1,2));
        }
        else if(last == 2){
            ret = min(ret,solve(idx + 1,1));
        }
    }
    return ret;

}


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;



    memset(dp,-1,sizeof dp);
    
    cin >> n;
    for(int i = 0;i<n;i++)
        cin >> A[i];
    
    cout << solve(0,0) << endl;

}