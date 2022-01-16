
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

using namespace std;

bool cmp(pair<ll,ll>a,pair<ll,ll>b){
    return a.second < b.second;
}



int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif

    ll n,r;
    ll avg;
    cin >> n >> r >> avg;
    vector<pair<ll,ll>>v(n);
    ll sum = 0;
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        sum += a;
        v[i].first = a;
        v[i].second = b;
    }

    sort(all(v),cmp);

    ll res = 0;
    for(int i = 0;i<n && sum < avg*n;i++){
        int inc = r - v[i].first;
        if(inc + sum <= avg*n ){
            sum += inc;
            res += inc * v[i].second;
        }
        else{
            res += (avg*n - sum) * v[i].second;
            break;
        }
    }

    cout << res << endl;

}