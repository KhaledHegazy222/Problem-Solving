#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const ll N = 200000 + 5;
struct DSU{


    ll par[N];
    ll sum[N];
    ll size[N];
    ll n;
    DSU(ll x){
        n = x;
        iota(par,par + n,0);
        iota(sum,sum + n,1);
        fill(size,size + n,1);
    }

    ll find(ll x){
        if(x == par[x])
            return x;
        return par[x] = find(par[x]);
    }


    ll merge(ll a,ll b){
        a = find(a);
        b = find(b);
        if(a == b)
            return 0;
        if(rand() % 2)
            swap(a,b);

        par[b] = a;
        sum[a] += sum[b];
        size[a] += size[b];
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
    ll n,m;
    while(cin >> n >> m){
        DSU D(n);
        map<ll,ll>mp;
        for(ll i = 0;i<n;i++)
            mp[i] = i;
        while(m--){
            ll type;
            cin >> type;
            if(type == 1){
                ll a,b;
                cin >> a >> b;
                D.merge(mp[--a],mp[--b]);
            }
            else if(type == 2){
                ll a,b;
                cin >> a >> b;
                a--;
                b--;
                if(D.find(mp[a]) == D.find(mp[b]))
                    continue;
                D.sum[D.find(mp[a])] -= a + 1;
                D.size[D.find(mp[a])]--;
                D.sum[n] = a + 1;
                D.par[n] = n;
                D.size[n] = 1;
                D.merge(mp[b],n);
                mp[a] = n++;
            }
            else{
                ll a;
                cin >> a;
                a--;
                cout << D.size[D.find(mp[a])] << " " << D.sum[D.find(mp[a])] << endl;
            }
        }
    }

}


