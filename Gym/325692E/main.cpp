
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
const int N = 20;
int n,x;
vector<int>nums(N);
vector<int>ops(N);

int eval(){

	int res = nums[0];
	for(int i = 0;i<n - 1;i++){
		res += -1 * ops[i] * nums[i + 1] + (1 - ops[i]) * nums[i + 1];
	}
	return res;
}


bool comb(int pos){
	if(pos == n - 1){
		return eval() == x;
	}

	ops[pos] = 0;
	int ch1 = comb(pos + 1);
	ops[pos] = 1;
	int ch2 = comb(pos + 1);

	return ch1 || ch2;

}

int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	
	cin >> n >> x;
	for(int i = 0;i<n;i++){
		cin >> nums[i];
	}

	cout << (comb(0) ? "YES\n" : "NO\n") << endl;

}