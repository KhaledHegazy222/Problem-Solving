
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;

ll fact(int n){
    if(n <= 1){
        return 1;
    }
    return n * fact(n-1);
}

ll C(int n,int r){
    return fact(n)/(fact(r)*fact(n-r));
}



int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    int n,r;
    cin >> n >> r;
    ll ncr = C(n,r);
    ll res = ncr *fact(r);
    cout << ncr << " " << res << endl;
}