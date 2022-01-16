#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1e9 + 7;
const ll N = 1e5 + 5;

ll n;
ll A[N];


ll dpCnt[N][2];
ll dpSolve[N][2];


ll cnt(ll idx,ll last){
    if(idx == n)
        return 1;

    ll &ret = dpCnt[idx][last];
    if(~ret)
        return ret;
    ll ch1 = cnt(idx + 1,0);
    ll ch2 = 0;
    if(!last)
        ch2 = cnt(idx + 1,1);
    return ret = (ch1 + ch2) % MOD;
}

ll solve(ll idx,ll last){
    if(idx == n)
        return 0;

    ll &ret = dpSolve[idx][last];
    if(~ret)
        return ret;
    ll c = cnt(idx + 1,0);
    ll ch1 = ((c * A[idx]) % MOD + solve(idx + 1,0)) % MOD;
    ll ch2 = 0;
    if(!last){
        c = cnt(idx + 1,1) ;
        ch2 = ((c * -A[idx]) % MOD + solve(idx + 1,1)) % MOD;
    }
    return ret = (ch1 + ch2) % MOD;
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
        cin >> A[i];



    memset(dpCnt,-1,sizeof dpCnt);
    memset(dpSolve,-1,sizeof dpSolve);

    cout << (solve(0,1) + MOD) % MOD << endl;


}


