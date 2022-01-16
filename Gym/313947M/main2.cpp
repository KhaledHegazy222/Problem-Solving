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
    ll k,m;
    cin >> k >> m;
    multiset<ll>st;
    multimap<ll,ll>mp;
    while(m--){
        ll x;
        cin >> x;
        st.insert(x);
        mp.insert({x,mp.size() + 1});
    }
    ll valid = 0;
    while(st.size()){
        auto elem = *st.begin();
        auto it2 = mp.find(elem);
        ll l = it2->second;
        mp.erase(it2);
        st.erase(st.begin());
        auto it = st.lower_bound(k - elem);
        if(it != st.end() && *it == k - elem)
            return cout << l << " " << mp.find(k - elem)->second << endl,0;
    }
    cout << "NO\n";


}

//
