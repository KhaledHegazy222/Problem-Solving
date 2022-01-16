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

    ll T = 0;
    ll n;
    while(cin >> n){

        DSU d1(n),d2(n);
        vector<pair<pair<ll,ll>,ll>>edges;

        for(ll i = 0;i<n - 1;i++){
            ll u,v,c;
            cin >> u >> v >> c;
            edges.push_back({{u,v},c});
        }
        
        


        sort(all(edges),[](pair<pair<ll,ll>,ll>a,pair<pair<ll,ll>,ll>b){
            return a.second < b.second;
        });

        ll cost1 = 0;
        for(auto elem : edges){
            if(d1.join(--elem.first.first,--elem.first.second))
                cost1 += elem.second;
        }
        edges.clear();
        ll k;
        cin >> k;
        while(k--){
            ll u,v,c;
            cin >> u >> v >> c;
            edges.push_back({{u,v},c});
        }
        ll m;
        cin >> m;
        while(m--){
            ll u,v,c;
            cin >> u >> v >> c;
            edges.push_back({{u,v},c});
        }


        sort(all(edges),[](pair<pair<ll,ll>,ll>a,pair<pair<ll,ll>,ll>b){
            return a.second < b.second;
        });

        ll cost2 = 0;
        for(auto elem : edges){
            if(d2.join(--elem.first.first,--elem.first.second))
                cost2 += elem.second;
        }
        if(T)   
            cout << endl;
        T = 1;
        cout << cost1 << '\n' << cost2 << '\n';
    }
}



