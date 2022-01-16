#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int cur,need,b;
int vals[10],dist[10000];


void bfs(int src){
    memset(dist,0x3f,sizeof dist);
    dist[src] = 0;
    queue<int>q;
    q.push(src);
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int i = 0;i<b;i++){
            int v = (u + vals[i]) % 10000;
            if(dist[u] + 1 < dist[v]){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}


signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    
    int cs = 1;
    while(cin >> cur >> need >> b,(cur || need || b)){
        for(int i = 0;i<b;i++)
            cin >> vals[i];

        bfs(cur);
        cout << "Case " << cs++ << ": ";
        if(dist[need] > 1e5 + 5)
            cout << "Permanently Locked" << endl;
        else
            cout << dist[need] << endl;
    }

}



