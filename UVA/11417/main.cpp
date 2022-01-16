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
    int n;
    while(cin >> n,n){
        int res = 0;
        for(int i = 1;i<n;i++){
            for(int j = i + 1;j <= n;j++)
                res += __gcd(i,j);
        }
        cout << res << endl;
    }


}