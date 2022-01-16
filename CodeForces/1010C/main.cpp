
#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    int n,k;
    cin >> n >> k;
    int arr[n];
    int g = 0;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        arr[i] %= k;
        g = __gcd(g,arr[i]);
    }

    int st = g;
    set<int>s;
    for(int st = g,i = 0;i<k;st += g,i++){
        st %= k;
        s.insert(st);
    }
    cout << s.size() << endl;
    for(auto it : s)
        cout << it << " ";
    cout << endl;

}