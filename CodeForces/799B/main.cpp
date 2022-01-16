/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define PI (acos(-1))


using namespace std;

typedef unsigned long long ull;
typedef long long ll;




int main(void){
	fast;
	#ifdef Khaled
		freopen("out.txt","w",stdout);
		freopen("in.txt","r",stdin);
	#endif
	#ifndef Khaled
		//freopen(".in","r",stdin);
	#endif
	set<int>one,two,three;
	int n;
    cin >> n;
    vector<pair<pair<int,int>,int>>v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i].first.first;
    }
 
    for(int i = 0;i<n;i++){
        cin >> v[i].first.second;
    }
 
    for(int i = 0;i<n;i++){
        cin >> v[i].second;
    }
 
	for(auto it : v){
		if(it.first.second == 1 || it.second == 1){
			one.insert(it.first.first);
		}
		if(it.first.second == 2 || it.second == 2){
			two.insert(it.first.first);
		}
		if(it.first.second == 3 || it.second == 3){
			three.insert(it.first.first);
		}
	}
 
	unordered_map<int,int>sold;
	
    int m;
    cin >> m;
    while(m--){
        int x;
        cin >> x;
		if(x == 1){
			one_:
			if(one.empty()){
				cout << -1 << ' ';
				continue;
			}
			int y = *(one.begin());
			if( sold[y]++ == 0){
				cout << y << ' ';
			}
			else{
				one.erase(one.begin());
				goto one_;
			}
		}
		else if(x == 2){

			two_:
			if(two.empty()){
				cout << -1 << ' ';
				continue;
			}
			int y = *(two.begin());
			if( sold[y]++ == 0){
				cout << y << ' ';
			}
			else{
				two.erase(two.begin());
				goto two_;
			}
		}
		else{
			three_:
			if(three.empty()){
				cout << -1 << ' ';
				continue;
			}
			int y = *(three.begin());
			if( sold[y]++ == 0){
				cout << y << ' ';
			}
			else{
				three.erase(three.begin());
				goto three_;
			}
		}
    }
    cout << endl;
 
 

	
}	


