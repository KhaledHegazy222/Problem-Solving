#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <list>
#include <iterator>
#include <deque>
#include <array>


using namespace std;


#define fast cin.tie(0);cin.sync_with_stdio(0);
#define ll long long

vector<vector<ll>> fillvec(ll n, ll m, ll x){
	vector<vector<ll>> v;
	vector<ll> in;
	for (size_t i = 0; i < n; i++){
		in.clear();
		for (size_t j = 0; j < m; j++){
			in.push_back(x);
		}
		v.push_back(in);
	}
	return v;
}
void printvec(vector<vector<ll>> v){
	for (size_t i = 0; i < v.size(); i++){
		for (size_t j = 0; j < v[0].size(); j++){

			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
bool powof2(ll n){
	ll two = 2;
	while (two < 2000000000){
		if (n == two){
			return true;
		}
		two *= 2;
	}
	return false;
}
bool perfect(ll n){
	double a = sqrt(n);
	if (a == floor(a))
		return true;
	return false;
}

ll mod = 1e9 + 7;
ll n;
vector<ll> v;
vector<vector<pair<ll, ll>>> val;

pair<ll, ll> solve(ll i = 0, bool c = true)
{
	if (i == n)
		return { 0, c };
	if (val[i][c].first == 0)
	{
		if (c)
		{
			ll c1 = solve(i + 1).second;
			ll one = solve(i + 1).first % mod;
			ll c2 = solve(i + 1, false).second;
			ll two = solve(i + 1, false).first % mod;
			
			val[i][c] = { (one + two + (c1 + c2) * v[i]) % mod, (c1 + c2) % mod };
		}
		else
		{
			ll three = solve(i + 1).first;
			ll c3 = solve(i + 1).second;
			val[i][c] = { three - c3 * v[i], c3 };
		}
	}
	
	return val[i][c];
}


int main(){
	fast;
	
	cin >> n;
	v.resize(n);
	val.resize(n, vector<pair<ll, ll>>(2));
	for (size_t i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cout << (solve().first + mod) % mod << "\n";
	
	

	return 0;
}