#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll n;
vector<ll>tim,speed;


long double dist(long double sec){
    long double mx = 0;
    long double mn = 1e18;
    for(ll i = 0;i<n;i++){
        mx = max(mx,(sec - tim[i]) * speed[i]);
        mn = min(mn,(sec - tim[i]) * speed[i]);
    }
    return mx - mn;
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
    
    while(cin >> n,n){
        tim.resize(n);
        speed.resize(n);
        for(ll i = 0;i<n;i++)
            cin >> tim[i] >> speed[i];
        

        long double l = *max_element(all(tim)),r = 1e15 + 7;
        for(int i = 0;i<100;i++){
            long double mid1 = l + (r - l) / 3;
            long double mid2 = r - (r - l) / 3;
            if(dist(mid1) < dist(mid2)){
                r = mid2;
            }
            else{
                l = mid1;
            }
        }
        cout << fixed << setprecision(3);
        cout << dist(l) << endl;
    }
}


