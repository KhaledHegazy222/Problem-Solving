#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int t;
    cin >> t;
    while(t--){
        int g,l;
        cin >> g >> l;
        if(l % g != 0){
            cout << -1 << endl;
            continue;
        }
        cout << g << " " << l << endl;
    }


}