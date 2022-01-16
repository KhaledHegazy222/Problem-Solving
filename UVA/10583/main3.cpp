#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const int N = 50000 + 5;
struct DSU{


    int par[N];
    int n;
    DSU(int x){
        n = x;
        iota(par,par + n,0);

    }

    int find(int x){
        if(x == par[x])
            return x;
        return par[x] = find(par[x]);
    }


    int merge(int a,int b){
        a = find(a);
        b = find(b);
        if(a == b)
            return 0;
        if(rand() % 2)
            swap(a,b);

        par[b] = a;
        return 1;
    }


};



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    #ifndef Khaled
        #define endl '\n'
        fast;
    #endif

    int cs = 1;
    int n,m;
    while(cin >> n >> m,n,m){
        DSU dsu(n);
        int res = n;
        while(m--){
            int u,v;
            cin >> u >> v;
            res -= dsu.merge(--u,--v);
        }
        cout << "Case " << cs++ << ": ";
        cout << res << endl;
    }





}


