#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct point{
    ll x,y,z;

    ll dist(point a){
        return abs(a.x - x) + abs(a.y - y) + max(0ll,a.z - z);
    }
};

const ll N = 17 + 1;
ll n;
point A[N];

ll dp[N][(1 << N)];



ll solve(ll idx,ll mask){
    if(mask + 1 == (1 << n))
        return A[idx].dist(A[0]);
    
    ll &ret = dp[idx][mask];
    if(~ret)
        return ret;
    ret = 1e18;
    for(ll i = 0;i<n;i++){
        if(!((mask >> i) & 1))
            ret = min(ret,A[idx].dist(A[i]) + solve(i,mask | (1 << i)));
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
    for(ll i = 0;i<n;i++)
        cin >> A[i].x >> A[i].y >> A[i].z;
    memset(dp,-1,sizeof dp);
    cout << solve(0,1) << endl;    



}



