#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e5 + 5;
int H[N],n,k;


ll dp[N];

ll solve(int idx){
    if(idx == n - 1)
        return 0;

    ll &ret = dp[idx];

    if(~ret)
        return ret;


    ret = INT_MAX;
    for(int i = 0;i<k;i++){
        if(idx + i + 1 >= n)
            break;
        ret = min(ret,abs(H[idx] - H[idx + i + 1]) + solve(idx + i + 1));
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

    cin >> n >> k;


    for(int i = 0;i<n;i++)
        cin >> H[i];

    cout << solve(0) << endl;
//

}