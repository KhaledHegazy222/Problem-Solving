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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int valid = 1;
        for(int i = 1;i <= n;i++){
            int x;
            cin >> x;
            if(i % x)
                valid = 0;
        }
        cout << (valid ? "YES\n" : "NO\n");
    }    

}


