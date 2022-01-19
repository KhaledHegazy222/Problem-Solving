#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
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
    fast;
    int n;
    cin >> n;
    deque<int>dq(n);
    for(int i = 0;i<n;i++)
        cin >> dq[i];
    if(count(all(dq),0) == n)
        return cout << 0 << endl,0;
    while(dq.front() == 0)
        dq.pop_front();
    while(dq.back() == 0)
        dq.pop_back();
    int lst = -1;
    ll res = 1;
    n = dq.size();
    for(int i = 0;i<n;i++){
        if(dq[i]){
            res *= i - lst;
            lst = i;
        }
    }
    cout << res << endl;
}