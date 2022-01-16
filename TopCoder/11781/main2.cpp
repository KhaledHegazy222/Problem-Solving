
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;



const int N = 50 + 5;

int A[N],n;

int dp[N][N];

int solve(int st,int en){
    if(en - st <= 1)
        return 0;
    int &ret = dp[st][en];
    if(~ret) return ret;
    ret = 0;
    for(int i = st + 1;i< en;i++){
        ret = max(ret,A[st] * A[en] + solve(st,i) + solve(i,en));
    }
    return ret;
}

class CasketOfStar{
    public:
    int maxEnergy(vector<int>v){
        memset(dp,-1,sizeof dp);
        n = v.size();
        for(int i =0;i<n;i++){
            A[i] = v[i];;
        }
        return solve(0,n - 1);
    }
};

