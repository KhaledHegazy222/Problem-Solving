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

    ll n,d;
    cin >> n >> d;
    multiset<ll>st;
    while(n--){
        ll x;
        cin >> x;
        st.insert(x);
    }
    ll pairs = 0;
    while(st.size()){
        auto elem = *st.begin();
        st.erase(st.begin());
        auto it = st.lower_bound(elem);
        if(it != st.end() && *it - elem <= d){
            pairs++;
            st.erase(it);
        }
    }
    cout << pairs << endl;

}


