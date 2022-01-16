/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>


#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 
using namespace std;

const int N = 50000 + 5;

int h[N];
int fwrd[N],bwrd[N];





int main(void){

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);


	#endif

	int n,m;
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> h[i];
	}
	stack<pair<int,int>>st;

	for(int i = 0;i<n;i++){
		if(st.empty() || st.top().first >= h[i])	st.push({h[i],i});
		else{
			while(!st.empty() && st.top().first < h[i]){
				fwrd[st.top().second] = i;
				st.pop();
			}
			st.push({h[i],i});
		}
	}
	while(!st.empty()){
		fwrd[st.top().second] = n;
		st.pop();
	}

	for(int i = n-1;i>=0;i--){
		if(st.empty() || st.top().first >= h[i])	st.push({h[i],i});
		else{
			while(!st.empty() && st.top().first < h[i]){
				bwrd[st.top().second] = i;
				st.pop();
			}
			st.push({h[i],i});
		}
	}
	while(!st.empty()){
		bwrd[st.top().second] = -1;
		st.pop();
	}


	int cnt = 0;
	while(m--){
		int a,b;
		cin >> a >> b;
		a--,b--;
		if(fwrd[a] >= b && bwrd[a] <= b) cnt++;
	}
	cout << cnt << endl;


}