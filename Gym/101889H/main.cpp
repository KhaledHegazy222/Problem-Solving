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


    int a,b,c;
    int a1,a2,a3;
    cin >> a >> b >> c >> a1 >> a2 >> a3;
    cout << max(0,a1 - a) + max(0,a2 - b) + max(0,a3 - c) << endl;
}
