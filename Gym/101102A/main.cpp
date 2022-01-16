#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int MOD = 1e9 + 7;

const int N = 150 + 5;

int n,m,k,w,s1[N],s2[N];


int dp[N][100 * N][2];

int solve(int idx,int sum,int turn){

    if(sum < 0)
        return 0;

    int &ret = dp[idx][sum][turn];
    if(~ret)
        return ret;
    if(turn){
        if(idx == n)
            return !sum;
        
        int ch1 = solve(idx + 1,sum,turn);
        int ch2 = solve(idx + 1,sum - s1[idx],turn);
        return ret = (ch1 + ch2) % MOD;
    }
    else{

        if(idx == m)
            return !sum;
        
        int ch1 = solve(idx + 1,sum,turn);
        int ch2 = solve(idx + 1,sum - s2[idx],turn);
        return ret = (ch1 + ch2) % MOD;
    }


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
    int t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof dp);

        cin >> n >> m >> k >> w;
        for(int i = 0;i<n;i++)
            cin >> s1[i];
        for(int i = 0;i<m;i++)
            cin >> s2[i];

        int res = 0;
        for(int i = 0;i<=w;i++){
            if(abs(i - (w - i)) <= k)
                res = (res + 1ll * solve(0,i,0) * solve(0,w - i,1)) % MOD;
        }
            
        cout << res << endl;
    }    
}


