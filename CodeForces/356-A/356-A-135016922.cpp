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

    ll n,m;
    cin >> n >> m;
    set<ll>st;
    for(ll i = 0;i<n;i++)
        st.insert(i);
    ll res[n] = {0};

    while(m--){
        ll l,r,x;
        cin >> l >> r >> x;
        l--,r--;
        auto it = st.lower_bound(l);
        while(it != st.end() && *it <= r){
            ll f = *it;
            if(*it != x - 1){
                res[*it] = x;
                st.erase(it);
            }
            it = st.lower_bound(f + 1);
        }
    }

    for(ll i = 0;i<n;i++)
        cout << res[i] << " \n"[i + 1 == n];
    

}