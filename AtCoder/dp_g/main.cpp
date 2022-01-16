#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e5 + 5,M = N;

int head[N],nxt[M],to[M],n,m,ne;

void init(){
    memset(head,-1,(n + 1) * sizeof head[0]);
    ne = 0;
}


void addEdge(int f,int t){
    nxt[ne] = head[f];
    to[ne] = t;
    head[f] = ne++;
}


int dp[N];



int solve(int u){
    
    int &ret = dp[u];
    if(~ret)   
        return ret;
    ret = 0;
    int flag = 0;
    for(int e = head[u];~e;e = nxt[e]){
        flag = 1;
        int v = to[e];
        ret = max(ret,solve(v));
    }

    return ret = ret + flag;


}


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    memset(dp,-1,sizeof dp);


    cin >> n >> m;
    init();
    while(m--){
        int a,b;
        cin >> a >> b;
        addEdge(--a,--b);
    }
    int sol = 0;
    for(int i = 0;i<n;i++){
        sol = max(sol,solve(i));
    }

    cout << sol << endl;

}