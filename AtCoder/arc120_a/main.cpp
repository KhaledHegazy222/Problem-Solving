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


    ll n;
    cin >> n;
    ll arr[n],mx[n],pref[n];
    for(ll i = 0;i<n;i++){
        cin >> arr[i];
        if(!i){
            mx[i] = pref[i] = arr[i];
        }
        else{
            mx[i] = max(mx[i - 1],arr[i]);
            pref[i] = pref[i - 1] + arr[i];
        }
    }
    vector<ll>res;
    ll sum = 0;
    for(ll i = 0;i<n;i++){
        sum += arr[i] * (n - i);
    }
    sum += mx[n - 1] * n;
    res.push_back(sum);
    for(ll i = n - 2;i>=0;i--){
        sum -= mx[i + 1] * (i + 2);
        sum += mx[i] * (i + 1);
        sum -= pref[i + 1];
        res.push_back(sum);
    }
    reverse(all(res));
    for(auto elem : res)
        cout << elem << endl;


}


