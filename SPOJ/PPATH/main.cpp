#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e4 + 5;

vector<int>isPrime(N,1);

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2;i*i<=N;i++)
        if(isPrime[i])
            for(int j = 2 * i;j < N;j+=i)
                isPrime[j] = 0;
}


int dist[N];

void bfs(int src){
    fill(dist,dist + N,1e5);
    dist[src] = 0;
    queue<int>q;
    q.push(src);
    while(q.size()){
        int u = q.front();
        q.pop();
        string s = to_string(u);
        for(int i = 0;i<s.size();i++){
            for(int j = !i;j < 10;j++){
                s = to_string(u);
                if(s[i] - '0' == j)
                    continue;
                s[i] = j + '0';
                int v = stoi(s);
                if(isPrime[v] && dist[v] > dist[u] + 1){
                    q.push(v);
                    dist[v] = dist[u] + 1;
                }
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
    sieve();
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        bfs(a);
        if(dist[b] > 2e4)
            cout << "Impossible\n";
        else
            cout << dist[b] << endl;
    }


}



