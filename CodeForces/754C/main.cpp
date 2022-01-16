#include <bits/stdc++.h>
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll n,m;

vector<string>names;
map<string,ll>mp;
vector<string>msg;
const ll N = 100 + 5,M = 100 + 5;
ll dp[N][M];
vector<map<ll,ll>>vmp;

ll exist(string &line,string &name){
	for(ll i = 1;i + name.size() <= line.size();i++){
		string tmp = line.substr(i,name.size());
		if(!isalpha(line[i - 1]) && !isdigit(line[i - 1]) && (i + name.size() >= line.size() || (!isdigit(line[i + name.size()]) && !isalpha(line[i + name.size()])) ) && tmp == name )
			return 1;
	}
	return 0;
}

ll solve(ll idx,ll last){
	if(idx == m)
		return 1;

	ll &ret = dp[idx][last + 1];
	if(~ret)
		return ret;
	
	ret = 0;
	if(msg[idx][0] == '?'){
		for(ll i = 0;i < n;i++){
			if(i == last || vmp[idx][i])
				continue;
			ret |= solve(idx + 1,i);
		}
	}
	else{	
		ll pos = msg[idx].find(':');
		string name = msg[idx].substr(0,pos);
		string rem = msg[idx].substr(pos);
		if(mp[name] == last || exist(rem,name))
			return ret = 0;
		return ret = solve(idx + 1,mp[name]);
	}	
	return ret;
}


void build(ll idx,ll last){
	if(idx == m)
		return;
	if(msg[idx][0] == '?'){

		for(ll i = 0;i < n;i++){
			if(i == last || exist(msg[idx],names[i]))
				continue;
			if(solve(idx + 1,i)){
				cout << names[i] << msg[idx].substr(1) << endl;
				build(idx + 1,i);
				return;
			}
			
		}
	}
	else{
		ll pos = msg[idx].find(':');
		string name = msg[idx].substr(0,pos);
		cout << msg[idx] << endl;
		build(idx + 1,mp[name]);
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


	ll t;
	cin >> t;
	while(t--){

		memset(dp,-1,sizeof dp);
		cin >> n;
		names.resize(n);
		mp.clear();
		for(ll i = 0;i < n;i++){
			cin >> names[i];
			mp[names[i]] = i;
		}
		cin >> m;
		msg.resize(m);
		vmp.clear();
		vmp.resize(m);
		cin.ignore();
		for(ll i = 0;i < m;i++){
			getline(cin,msg[i]);
		}
		for(ll i = 0;i < m;i++){
			for(ll j = 0;j < n;j++){
				if(exist(msg[i],names[j]))
					vmp[i][j]++;
			}
		}

		if(solve(0,-1)){
			build(0,-1);
		}
		else{
			cout << "Impossible\n";
		}


	}

}


