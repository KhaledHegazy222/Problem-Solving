
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

int n,r;
vector<int>current;
vector<int>vis(20);

void perm(int i){
	if(current.size() == r){
		for(auto it : current){
			cout << it << " ";
		}
		cout << endl;
	}

	for(int j = 0;j<n;j++){
		if(!vis[j]){
			vis[j] = 1;
			current.push_back(j + 1);
			perm(j);
			vis[j] = 0;
			current.pop_back();	
		}
		
	}
}



int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	

	cin >> n >> r;
	perm(-1);
}