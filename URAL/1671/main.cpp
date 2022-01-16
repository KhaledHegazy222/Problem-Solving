
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 1e6 + 5;
struct DSU{
    int par[N],cnt;


    void init(int n){
        iota(par,par + n,0);
        cnt = n;
    }
    int find(int x){
        if(par[x] == x) return x;
        return x = find(par[x]);
    }
    int join(int u,int v){
        u = find(u);
        v = find(v);
        if(u == v) return 0;
        if(rand() % 2) swap(u,v);
        par[v] = u;
        cnt--;
        return 1;
    }

}dsu;


int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int n,m;
    cin >> n >> m;
    dsu.init(n);
    vector<pair<int,int>>edges(m);
    for(int i = 0;i<m;i++){
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }
    set<int>st;
    vector<int>v;
    int c;
    cin >> c;
    for(int i = 0;i<c;i++){
        int x;
        cin >> x;
        st.insert(--x);
        v.push_back(x);
    }
    for(int i = 0;i<m;i++){
        if(st.find(i) == st.end())
            dsu.join(edges[i].first,edges[i].second);
    }
    vector<int>res;
    for(int i = c - 1;~i;i--){
        res.push_back(dsu.cnt);
        dsu.join(edges[v[i]].first,edges[v[i]].second);
    }
    reverse(all(res));
    for(auto it : res){
        cout << it << " ";
    }
    cout << endl;
}