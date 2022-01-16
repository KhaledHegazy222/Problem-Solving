#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;



const ll N = 15 + 2;
const ll M = 100 + 2;

ll n,m;
vector<ll>switches;

ll dp[M][1 << N];


ll solve(ll idx,ll mask){
    if(idx == m){
        if(!mask)
            return 0;
        return 20;
    }
    
    ll &ret = dp[idx][mask];
    if(~ret)
        return ret;
    ret = 20;

    mask ^= switches[idx];
    ret = min(ret,1 + solve(idx + 1,mask));
    mask ^= switches[idx];


    ret = min(ret,solve(idx + 1,mask));
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

    ll cs = 1;
    ll t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        switches.clear();
        switches.resize(m);

        for(ll i = 0;i<m;i++){
            for(ll j = 0;j < n;j++){
                ll _;
                cin >> _;
                if(_)   
                    switches[i] |= (1 << j);
            }
            // cout << switches[i] << " ";
        }
        // cout << endl;

        memset(dp,-1,sizeof dp);
        ll sol = solve(0,(1 << n) - 1);
        cout << "Case " << cs++ << ": ";
        if(sol > 15)
            cout << "IMPOSSIBLE\n";
        else
            cout << sol << endl;
    }


}


