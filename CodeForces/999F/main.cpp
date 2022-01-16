#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const ll N = 5e3 + 5;
ll n,k;
ll f[505],h[12],c[100001];

ll dp[501][5001];


ll solve(ll idx,ll prev){
    if(idx == n)
        return 0;

    ll &ret = dp[idx][prev];
    if(~ret)
        return ret;

    ll ch1 = 0;
    
    if(!idx || f[idx - 1] == f[idx]){
        for(ll i = 0;i <= min(k,c[f[idx]] - prev);i++){
            ch1 = max(ch1,h[i] + solve(idx + 1,prev + i));
        }
    }
    else{
        prev = 0;
        for(ll i = 0;i <= min(k,c[f[idx]] - prev);i++){
            ch1 = max(ch1,h[i] + solve(idx + 1,prev + i));
        }
    }

    return ret = ch1;

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

    memset(dp,-1,sizeof dp);

    cin >> n >> k;
    for(ll i = 0;i < n * k;i++){
        ll x;
        cin >> x;
        c[x]++;
    }
    for(ll i = 0;i < n;i++)
        cin >> f[i];

    for(ll i = 1;i <= k;i++)
        cin >> h[i];
    sort(f,f + n);
    cout << solve(0,0) << endl;
        


}


