#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 12;

ll dp[N][1 << N];

int n;

ll solve(int idx,int mask){
    if(mask + 1 == (1 << n))
        return 1;
    


    ll &res = dp[idx][mask];
    if(~res) return res;
    res = 0;
    for(int i = 0;i < n;i++){
        if(i == idx) continue;
        if(((mask >> i) & 1) == 0){
            res += solve(idx + 1,mask | ( 1 << i));
        }
    }
    return res;
}



int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    int t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin >> n;
        ll cnt = solve(0,0);
        ll res = 1;
        for(int i = 2;i<=n;i++)
            res *= i;
        cout << cnt << "/" << res << endl;
    }

}