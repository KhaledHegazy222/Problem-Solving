#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;



const int MOD = 1e9 + 7;
const int N = 22;
int Mat[N][N],n;

int dp[N][1 << N];

int solve(int idx,int women){
    if(idx == n)
        return 1;
    
    
    int &ret = dp[idx][women];
    if(~ret)
        return ret;
    ret = 0;
    for(int i = 0;i<n;i++){
        if(((women >> i) & 1) && Mat[idx][i]){
            ret = (0ll + ret + solve(idx + 1,women & (~(1 << i)))) % MOD;
        }  
    }
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
    
    cin >> n;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            cin >> Mat[i][j];
    

    memset(dp,-1,sizeof dp);
    cout << solve(0,(1<<n) - 1) << endl;
}


