// #include <bits/stdc++.h>
// #define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
// #define all(a) a.begin(),a.end()

// typedef long long ll;
// typedef unsigned long long ull;

// using namespace std;


// const ll MOD = 1e9 + 7;

// ll n,m;

// int solve(int rem,int current,int mask){
//     if(!rem)
//         return (mask + 1) == (1 << n);
    

//     int ret = 0;
//     if(~current){
//         for(int i = 1;i < n;i++)
//             ret += solve(rem - 1,i,mask | (1 << i));
//     }
//     else{
//         if(current)
//             ret += solve(rem - 1,current - 1,mask | (1 << (current - 1)));
//         if(n - 1 - current)
//             ret += solve(rem - 1,current + 1,mask | (1 << (current + 1)));
//     }
//     return ret;

// }

// signed main(void){

//     #ifdef Khaled
//         freopen("in.txt","r",stdin);
//         //freopen("out.txt","w",stdout);
//     #endif
//     #ifndef Khaled
//         #define endl '\n'
//         fast;
//     #endif
    
//     ll t;
//     cin >> t;
//     while(t--){
//         // memset(dp,-1,sizeof dp);
//         cin >> n >> m;
//         int sol = 0;
//         for(int i = 0;i<m;i++)
//             sol += solve
//             cout << solve(m,-1,0) << endl;;
//         // cout << sol << endl;
//     }
// }


#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const ll MOD = 1e9 + 7;

ll n,m;

ll dp[102][11][1 << 11];


ll solve(ll idx,ll currentDigit,ll mask){
    if(idx == m)
        return (mask + 1) == (1 << n);
    if(idx > m)
        return 0;

    ll &ret = dp[idx][currentDigit][mask];
    if(~ret)
        return ret;
    ret = 0;
    if(currentDigit)
        ret = (ret + solve(idx + 1,currentDigit - 1,mask | (1 << (currentDigit - 1)))) % MOD;
    if(n - 1 - currentDigit)
        ret = (ret + solve(idx + 1,currentDigit + 1,mask | (1 << (currentDigit + 1)))) % MOD;
    ret +=  ((mask + 1) == (1 << n));
    ret %= MOD;
    return ret ;

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
    
    ll t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin >> n >> m;
        ll sol = 0;
        for(ll i = 1;i < n;i++)
            sol = (sol + solve(1,i,(1 << i))) % MOD;
        cout << sol << endl;
    }
}


