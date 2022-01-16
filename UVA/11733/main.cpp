#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const ll N = 1e4 + 5;

struct DSU{
    ll par[N];

    DSU(ll n){
        iota(par,par + n,0);
    }


    ll find(ll x){
        if(x == par[x])
            return x;
        return par[x] = find(par[x]);
    }

    ll join(ll a,ll b){
        a = find(a);
        b = find(b);
        if(a == b)
            return 0;
        if(rand() % 2)
            swap(a,b);
        par[b] = a;
        return 1;
    }
};

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
        ll n,m,a;
        cin >> n >> m >> a;
        DSU D(n + 1);
        vector<pair<pair<ll,ll>,ll>>edges(m);
        for(ll i = 0;i < m;i++)
            cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
        for(ll i = 0;i < n;i++)
            edges.push_back({{i + 1,n + 1},a});

        sort(all(edges),[](pair<pair<ll,ll>,ll> &a,pair<pair<ll,ll>,ll> &b){
            if(a.second != b.second)
                return a.second < b.second;
            return a.first.second > b.first.second;
        });

        ll cost = 0;
        ll airports = 0;
        for(auto elem : edges){
            if(D.join(--elem.first.first,--elem.first.second)){
                cost += elem.second;
                airports += elem.first.second == n;
            }
        }

        cout << "Case #" << cs++ << ": " << cost << " " << airports << endl;
    }

}


