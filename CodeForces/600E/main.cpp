
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

const int N = 1e5 + 5,M = 2 * N;

int head[N],nxt[M],to[M],ne,n,m;
int color[N],sz[N];
int st[N],en[N],dfsOrder[N],curTime;
ll ans[N];
void init(){
    ne = 0;
    memset(head,-1,(n + 1) * sizeof head[0]);
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


void dfs(int u,int par){
    sz[u] = 1;
    dfsOrder[curTime] = u;
    st[u] = curTime++;
    for(int e = head[u];~e;e = nxt[e]){
        int v = to[e];
        if(v == par) continue;
        dfs(v,u);
        sz[u] += sz[v];
    }
    en[u] = curTime - 1;
}


struct data{
    map<int,int>frq;
    int mx;
    ll sum;
    data(){
        sum = mx = 0;
        frq.clear();
    }
    void add(int c){
        int f = ++frq[c];
        if(f > mx)
            mx = f,sum = 0;
        if(f == mx)
            sum += c;
    }
};


void extend(data & tmp,int i){
    
    for(int j = st[i];j <= en[i];j++){
        tmp.add(color[dfsOrder[j]]);
    }
}




data smallToLarge(int u,int par){

    data te;
    int big = -1;
    for(int e = head[u];~e;e = nxt[e]){
        int v = to[e];
        if(v == par) continue;
        if(sz[v] * 2 > sz[u])
            big = v;
        else
            smallToLarge(v,u);
    }
    if(~big)
        te = smallToLarge(big,u);
    te.add(color[u]);
    for(int e = head[u];~e;e = nxt[e]){
        int v = to[e];
        if(v == par || v == big) continue;
        extend(te,v);
    }
    ans[u] = te.sum;
    return te;
}





int main(void){
    fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	
    #endif

    cin >> n;
    init();
    for(int i = 0;i<n;i++){
        cin >> color[i];
    }
    for(int i = 0;i<n - 1;i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        addBiEdge(a,b);
    }
    dfs(0,-1);
    smallToLarge(0,-1);
    for(int i = 0;i<n;i++){
        cout << ans[i] << " \n"[i + 1 == n];
    }



}