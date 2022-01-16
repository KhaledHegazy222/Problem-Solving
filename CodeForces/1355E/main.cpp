#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll N = 1e5 + 5;
ll n,a,r,m,A[N];    


ll eval(ll h){
    ll sumpos = 0,sumneg = 0;
    for(ll i = 0;i<n;i++){
        if(A[i] > h){
            sumpos += A[i] - h;
        }
        else{
            sumneg += h - A[i];
        }
    }
    ll x = min(sumpos,sumneg);
    ll cost = 0;
    sumneg -= x,sumpos -= x;
    cost += x * min(a + r,m);
    cost += sumneg * a;
    cost += sumpos * r;
    return cost;
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


    cin >> n >> a >> r >> m;
    for(ll i = 0;i<n;i++)
        cin >> A[i];
    
    ll l = 0,r = 1e9 + 5;
    while(l != r){
        ll mid1 = l + (r - l) / 3;
        ll mid2 = r - (r - l) / 3;
        if(eval(mid1) > eval(mid2)){
            l = mid1 + 1;
        }
        else{
            r = mid2 - 1;
        }
    }
    cout << eval(l) << endl;
}


