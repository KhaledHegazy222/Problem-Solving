

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
#define MOD ((ll)1e9+7)

using namespace std;


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    

    int n;
    cin >> n;
    ll res = 1;
    for(int i =1;i<=n;i++){
        res *= i;
        res %= 998244353;
    }
    cout << res << endl;
}


