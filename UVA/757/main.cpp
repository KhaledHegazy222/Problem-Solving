#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll N = 25 + 2,H = 16 * 60 / 5 + 2;

ll F[N],D[N],dist[N],n,h;

ll eval(ll idx,ll x){
	ll res = 0;
	for(ll i = 0;i < x;i++)	
		res += max(0ll,F[idx] - D[idx] * i);
	return res;
}
vector<ll>sol;


ll dp[N][H];



ll solve(ll idx,ll time){
	if(idx == n)
		return 0;
	ll &ret = dp[idx][time];
	if(~ret)
		return ret;	
	ll ch1 = 0;
	if(time >= dist[idx])
		ch1 = solve(idx + 1,time - dist[idx]);
	ll ch2 = 0;
	for(ll i = 1;i + dist[idx] <= time;i++)
		ch2 = max(ch2,eval(idx,i) + solve(idx + 1,time - i - dist[idx]));

	return ret = max(ch1,ch2);
}

void build(ll idx,ll time){
	if(idx == n)
		return;
	ll ans = solve(idx,time);
	ll ch1 = 0;
	if(time >= dist[idx])
		ch1 = solve(idx + 1,time - dist[idx]);
	
	for(ll i = time - dist[idx];i > 0;i--){
		ll ch2 = eval(idx,i) + solve(idx + 1,time - i - dist[idx]);
		if(ans == ch2){
			sol.push_back(i * 5);
			build(idx + 1,time - i - dist[idx]);
			return;
		}
	}
	if(ch1 == ans){
		sol.push_back(0);
		build(idx + 1,max(0ll,time- dist[idx]));
	}
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
	ll flag = 0;
	while(cin >> n,n){	
		memset(dp,-1,sizeof dp);
		cin >> h;
		for(ll i = 0;i < n;i++)
			cin >> F[i];
		for(ll i = 0;i < n;i++)
			cin >> D[i];
		dist[0] = 0;
		for(ll i = 1;i < n;i++)
			cin >> dist[i];
		

		if(flag)
			cout << endl;
		flag = 1;


		build(0,h * 60 / 5);

		// if(sol.size() != n){
		// 	cout << n << endl << h << endl;
		// 	for(ll i = 0;i < n;i++)
		// 		cout << F[i] << " \n"[i + 1 == n];
		// 	for(ll i = 0;i < n;i++)
		// 		cout << D[i] << " \n"[i + 1 == n];
		// 	for(ll i = 1;i < n;i++)
		// 		cout << dist[i] << " \n"[i + 1 == n];
		// 	return 0;

		// }

		for(ll i = 0;i < sol.size();i++){
			if(i){
				cout << ", ";
			}	
			cout << sol[i];
		}
		cout << endl;
		cout << "Number of fish expected: " << solve(0,h * 60 / 5) << endl;
	
		sol.clear();
		
		
	}
}


