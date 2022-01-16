#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 20;
ll facts[N];

map<ll,int>dp;

bool solve(ll n){
    if(n == 1)  return 1;
    if(dp.find(n) != dp.end())
        return dp[n];
    ll ret = 0;
    for(int i = 2;i<N;i++){
        if(n % facts[i] == 0){
            ret |= solve(n / facts[i]);
        }
    }
    dp[n] = ret;
    return ret;
}


int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    facts[0] = 1;
    for(int i = 1;i<N;i++){
        facts[i] = facts[i-1] * i;
    }

    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << (solve(n) ? "YES\n" : "NO\n");
    }



}