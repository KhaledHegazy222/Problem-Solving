
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;



const int N = 2e5 + 5,M = 4e5 + 5;

struct ADJ{

    int head[N],nxt[M],to[M],n,ne;
    void init(int n){
        this->n = n;
        memset(head,-1,(n + 1) * sizeof head[0]);
        ne = 0;
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


}adj,dag;

int dfsTime[N],low[N],curTime;
stack<int>stk;

int vis[N],vid;
int compID[N],ncp;


void dfsTarjan(int u){
    vis[u] = vid;
    compID[u] = -1;
    dfsTime[u] = low[u] = curTime++;
    stk.push(u);
    for(int e = adj.head[u];~e;e = adj.nxt[e]){
        int v = adj.to[e];
        if(vis[v] != vid){  
            dfsTarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(compID[v] == -1){
            low[u] = min(low[u],dfsTime[v]);
        }
    }
    if(low[u] == dfsTime[u]){
        compID[u] = ncp;
        while(stk.top() != u){
            compID[stk.top()] = ncp;
            stk.pop();
        }
        stk.pop();
        ncp++;
    }

}


void T(){
    ncp = curTime = 0;
    vid++;
    for(int u = 0;u < adj.n;u++){
        if(vis[u] != vid)
            dfsTarjan(u);
    }
    dag.init(ncp);
    for(int u = 0;u<adj.n;u++){
        for(int e = adj.head[u];~e;e = adj.nxt[e]){
            int v = adj.to[e];
            if(compID[u] == compID[v]) continue;
            dag.addEdge(u,v);
        }
    }
}



#define Var(x) ((x) << 1)
#define Not(x) ((x) ^ 1)


void addOR(int a,int b){
    adj.addEdge(Not(a),b);
    adj.addEdge(Not(b),a);
}

void addXOR(int a,int b){
    addOR(a,b);
    addOR(Not(a),Not(b));
}

void addXNOR(int a,int b){
    addOR(a,Not(b));
    addOR(Not(a),b);
}


int main(void){
    
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	
    #endif


    int n,m;
    cin >> n >> m;
    adj.init(2 * m);
    int state[n];
    for(int i = 0;i<n;i++){
        cin >> state[i];
    }
    int s1[n] = {0},s2[n] = {0};
    for(int i = 0;i<m;i++){
        int x;
        cin >> x;
        while(x--){
            int y;
            cin >> y;
            y--;
            if(!s1[y])
                s1[y] = i;
            else
                s2[y] = i;
        }
    }
    for(int i = 0;i<n;i++){
        if(state[i])
            addXNOR(Var(s1[i]),Var(s2[i]));
        else
            addXOR(Var(s1[i]),Var(s2[i]));
    }

    T();
    for(int i = 0;i<2 * m;i += 2){
        if(compID[i] == compID[i ^ 1])
            return puts("NO") * 0;
    }

    puts("YES");

}