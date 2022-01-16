// #include <bits/stdc++.h>
// #ifndef Khaled
//     #define endl '\n'
// #endif
// #define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
// #define all(a) a.begin(),a.end()

// typedef long long ll;
// typedef unsigned long long ull;

// using namespace std;


// const int N = 5e3 + 5,M = 2*N;


// int head[N],to[M],nxt[M],n,m,ne;

// void init(){
//     ne = 0;
//     memset(head,-1,(n + 1) * sizeof head[0]);
// }

// void addEdge(int u,int v){
//     nxt[ne] = head[u];
//     to[ne] = v;
//     head[u] = ne++;
// }
// void addBiEdge(int u,int v){
//     addEdge(u,v);
//     addEdge(v,u);
// }


// int dist[N];

// void bfs(int src){
//     fill(dist,dist + n,1e9);
//     dist[src] = 0;
//     queue<int>q;
//     q.push(src);
//     while(q.size()){
//         int u = q.front();
//         q.pop();
//         for(int e = head[u];~e;e = nxt[e]){
//             int v = to[e];
//             if(dist[u] + 1 < dist[v]){
//                 dist[v] = dist[u] + 1;
//                 q.push(v);
//             }
//         }
//     }
// }



// signed main(void){

//     #ifdef Khaled
//         freopen("in.txt","r",stdin);
//         //freopen("out.txt","w",stdout);
//     #endif
//     fast;
//     while(cin >> n){
//         init();
//         for(int i = 0;i<n;i++){
//             int x;
//             cin >> x;
//             while(x--){
//                 int v;
//                 cin >> v;
//                 addEdge(i,--v);
//             }
//         }
//         map<int,int>best,worst;
//         bfs(0);
//         int mx = *max_element(dist,dist + n);
//         int u;
//         for(int i = 0;i<n;i++){
//             if(dist[i] == mx)
//                 u = i;
//         }
//         queue<int>q;
//         q.push(u);
//         bfs(u);
//         mx = *max_element(dist,dist + n);   
//         sort(dist,dist + n);
//         int mn = ;
//         while(q.size()){
//             int u = q.front();
//             q.pop();
//             bfs(u);
//             for(int i = 0;i<n;i++){
//                 if(dist[i] == mx && worst.find(i) == worst.end()){
//                     //q.push(i);
//                     worst[i]++;
//                 }
//             }
//         }
//         for(auto elem : worst){
//             if(best.find(elem.first) != best.end())
//                 best.erase(elem.first);
//         }
//         cout << "Best Roots  :";
//         for(auto it : best)
//             cout << " " << it.first + 1;
//         cout << endl;
//         cout << "Worst Roots :";
//         for(auto it : worst)
//             cout << " " << it.first + 1;
//         cout << endl;
//     }

// }

#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


const int N = 5e3 + 5,M = 2*N;


int head[N],to[M],nxt[M],n,m,ne;
int dp[N][N];

void init(){
    ne = 0;
    memset(head,-1,(n + 1) * sizeof head[0]);
    memset(dp,-1,sizeof dp);
}

void addEdge(int u,int v){
    nxt[ne] = head[u];
    to[ne] = v;
    head[u] = ne++;
}
void addBiEdge(int u,int v){
    addEdge(u,v);
    addEdge(v,u);
}


int dist[N];

int dfs(int u,int par){
    int &ret = dp[u][par];
    if(~ret)   
        return ret;
    ret = 0;
    for(int e = head[u];~e;e = nxt[e]){
        int v = to[e];
        if(v == par)
            continue;
        ret = max(ret,1 + dfs(v,u));
    }
    return ret;
}



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    while(cin >> n){
        init();
        for(int i = 0;i<n;i++){
            int x;
            cin >> x;
            while(x--){
                int v;
                cin >> v;
                addEdge(i,--v);
            }
        }
        int mx = -1;
        int mn = n + 1;
        vector<int>best,worst;
        for(int i = 0;i<n;i++){
            int h = dfs(i,i);
            mx = max(mx,h);
            mn = min(mn,h);
        }
        for(int i = 0;i<n;i++){
            int h = dfs(i,i);
            if(mx == h){
                worst.push_back(i);
            }
            if(mn == h)
                best.push_back(i);
        }
        cout << "Best Roots  :";
        for(auto it : best)
            cout << " " << it + 1;
        cout << endl;
        cout << "Worst Roots :";
        for(auto it : worst)
            cout << " " << it + 1;
        cout << endl;
    }

}




