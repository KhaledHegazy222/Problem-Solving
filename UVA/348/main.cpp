#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll N = 10 + 2;
pair<ll,ll>mat[N];
ll n;

ll dp[N][N];

ll solve(ll st,ll en){
    if(st == en){
        return 0;
    }
    if(st + 1 == en){
        return mat[st].first * mat[st].second * mat[en].second;
    }
    ll &ret = dp[st][en];
    if(~ret)
        return ret;
    ret = 1e15;
    for(ll i = st;i < en;i++){
        ret = min(ret,solve(st,i) + solve(i + 1,en) + mat[st].first * mat[i].second * mat[en].second );
    }
    return ret;

}

void build(ll st,ll en){
    if(st == en){
        cout << "A" << st + 1;
        return;
    }
    if(st + 1 == en){
        cout << "A" << st + 1 << " x " << "A" << en + 1;
        return;
    }
    ll sol = solve(st,en);
    for(ll i = st;i < en;i++){
        if(sol == solve(st,i) + solve(i + 1,en) + mat[st].first * mat[i].second * mat[en].second ){
            if(i > st)
                cout << "(";
            build(st,i);
            if(i > st)
                cout << ")";
            cout << " x ";
            if(en != i + 1)
                cout << "(";
            build(i + 1,en);
            if(en != i + 1)
                cout << ")";
            break;
        }
        
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
    ll cs = 1;
    while(cin >> n , n){
        memset(dp,-1,sizeof dp);
        cout << "Case " << cs++ << ": ";
        for(ll i = 0;i<n;i++)
            cin >> mat[i].first >> mat[i].second;
        cout << "(";
        build(0,n - 1);
        cout << ")\n";
        // cout << solve(0,n - 1) << endl;
    }
    

}


