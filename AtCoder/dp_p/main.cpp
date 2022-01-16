#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll N = 1e5 + 5,M = 2 * N;

ll MOD = 1e9 + 7;

ll head[N],to[M],nxt[M],n,ne;

void init(){
	memset(head,-1,(n + 1) * sizeof head[0]);
	ne = 0;
}

void addEdge(ll u,ll v){
	nxt[ne] = head[u];
	to[ne] = v;
	head[u] = ne++;
}

void addBiEdge(ll u,ll v){
	addEdge(u,v);
	addEdge(v,u);
}

ll dp[N][2];



ll solve(ll u,ll par,ll last){
	
	ll &ret = dp[u][last];
	if(~ret)
		return ret;
	ll ch1 = 1;
	ll ch2 = 1;
	ll cnt = 0;
	for(ll e = head[u];~e;e = nxt[e]){
		ll v = to[e];
		if(v == par)
			continue;
		cnt++;
		if(!last){
			ch1 = (1ll * solve(v,u,1) * ch1) % MOD;
		}
		ch2 = (1ll * solve(v,u,0) * ch2) % MOD;

	}
	if(!cnt)
		ret = !last + 1;
	else{
		if(last){
			ret = ch2;
		}
		else{
			ret = ch1 + ch2;
		}
	}
	return ret % MOD;

}



signed main(void){

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	#ifndef Khaled
		#define endl '\n'
		fast;
	#endif

	memset(dp,-1,sizeof dp);
	cin >> n;
	init();
	for(ll i = 0;i < n - 1;i++){
		ll u,v;
		cin >> u >> v;
		u--,v--;
		addBiEdge(u,v);
	}

	cout << solve(0,0,0) << endl;



}


