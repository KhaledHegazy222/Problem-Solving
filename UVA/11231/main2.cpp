#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll solve(int n,int m){
    return ((n - 6) / 2) * ((m - 6) / 2);
}


int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int n,m,d;
    while(cin >> n >> m >> d,(n || m || d)){
        ll res = 0;
        if(d){
            cout << solve(n,m) + solve(n-1,m-1) << endl;
        }
        else{
            cout << solve(n-1,m) + solve(n - 2,m - 1) + solve(8,m-1) << endl;
        }
    }


}