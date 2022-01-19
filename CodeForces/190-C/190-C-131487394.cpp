#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
const int N = 1e6 + 5,M = N;

int head[N],to[M],nxt[M],n,m,ne;
int type[N];
void init(){
    ne = 0;
    memset(head,-1,n * sizeof head[0]);
}

void addEdge(int u,int v){
    nxt[ne] = head[u];
    to[ne] = v;
    head[u] = ne++;
}


void solve(int idx,int &l,int &r){
    if(type[idx]){
        int x,y;
        solve(idx + 1,x,y);
        addEdge(idx,x);
        addEdge(idx,y + 1);
        l = idx; 
        solve(y + 1,x,y);
        r = y;
    }
    else{
        l = idx,r = idx;
    }
}

// int solve(int idx,int par){
//     if(ne == n)
//         return 0;
//     int ret = 1;
//     if(type[idx]){
//         addEdge(idx,idx + 1);
//         ret &= solve(idx + 1,idx);
//         addEdge(idx,ne);
//         ret &= solve(ne,idx);
//     }
//     return ret;
// }

void build(int idx){
    if(type[idx]){
        cout <<"pair<";
        vector<int>ch;
        for(int e = head[idx];~e;e = nxt[e]){
            int v = to[e];
            ch.push_back(v);
        }
        sort(all(ch));
        build(ch[0]);
        cout<<",";
        build(ch[1]);
        cout << ">";
    }
    else
        cout << "int";
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    cin >> n;
    cin.ignore();
    string line;
    getline(cin,line);
    stringstream ss(line);
    n = 0;
    string s;
    while(ss >> s){
        type[n++] = (s == "pair");
    }
    init();

    int x,y;
    solve(0,x,y);
    if(x != 0 || y != n - 1){
        cout << "Error occurred\n";
        return 0;
    }
    build(0);

}