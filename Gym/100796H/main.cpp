#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


ll sum(int n){
    return 1ll * n * (n + 1) / 2;
}

ll sumRange(int l,int r){
    if(l > r)
        swap(l,r);

    ll ret = sum(r);
    if(l){
        ret -= sum(l - 1);
    }
    return ret;

}

int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;


    int n,m;
    cin >> n >> m;
    if(n > m)
        swap(n,m);

    cout << sumRange(m,m - n + 1) + sum(n) << endl;


    

}