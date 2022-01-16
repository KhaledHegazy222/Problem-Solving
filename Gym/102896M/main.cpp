#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
const int N = 1e5 + 5;

int srch(deque<int>&q,int k){
	int l = 0,r = q.size() - 1;
	while(l != r){
		int m = l + (r - l + 1) / 2;
		if(q[m] > k)
			r = m - 1;
		else
			l = m;
	}
	return q[l];
}

int main(void){
	
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
    #endif	
    fast;



	int n;
	cin >> n;
	vector<vector<int>>v(n);
	for(int i = 0;i<n;i++){
		int k;
		cin >> k;
		v[i].resize(k);
		for(int j = 0;j<k;j++){
			cin >> v[i][j];
		}
	}
	int arr[N];
	fill(arr, arr + N,n + 1);

	deque<int>signs;
	int lst = n + 1;
	int changes = 0;
	int day = n;
	for(auto it : v){
		int x = lst;
		for(auto elem : it){
			x = min(x,arr[elem] - 1);
		}
		if(x != lst){
			changes++;
			lst = day;
			signs.push_front(lst);
		}

		int z = INT_MAX;
		for(auto elem : it){
			z = min(z,srch(signs,arr[elem] - 1));
		}
		for(auto elem :it)
			arr[elem] = z;
		day--;
	}
	cout << changes << '\n';

}