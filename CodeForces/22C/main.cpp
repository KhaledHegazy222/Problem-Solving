#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif
    
    ll n,m,v;
    cin >> n >> m >> v;
    if(m < n -1)
        return cout << -1 << endl,0;
    m--;
    vector<ll>vec(n);
    iota(all(vec),0);
    swap(vec[--v],vec[1]);
    vector<pair<ll,ll>>edges;
    edges.push_back({vec[0],vec[1]});
    for(ll i = 1;i < n && m > 0;i++){
        for(ll j = i + 1;j < n && m > 0;j++){
            edges.push_back({vec[i],vec[j]});
            m--;
        }
    }
    if(m != 0)
        cout << -1 << endl;
    else
        for(auto elem : edges)
            cout << elem.first + 1 << " " << elem.second + 1 << endl;


}


