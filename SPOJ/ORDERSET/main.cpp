/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>


#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

using namespace std;

const int N = 1 << 18;





struct BIT{
	int tree[N];

	BIT(){
		memset(tree,0,sizeof tree);
	}

	void add(int pos,int val){
		for(pos++;pos <= N;pos += pos & -pos) tree[pos-1] += val;
	}
	int get(int pos){
		int ret = 0;
		for(pos++;pos;pos -= pos & -pos) ret += tree[pos-1];
		return ret;
	}

	int find(int val){
		int st = 0,en = N-1;
		while(st < en){
			int mid = st + (en - st) / 2;
			if(tree[mid] < val){
				st = mid + 1;
				val -= tree[mid];
			}
			else{
				en = mid;
			}
		}
		return st;
	}


};


struct multiSet{
	BIT bit;
	multiSet(){
		bit.add(0,-1);
	}

	void insert(int val){
		bit.add(val,1);
	}
	void erase(int val){
		bit.add(val,-1);
	}
	int size(){
		return bit.get(N-1) + 1;
	}

	int count(int val){
		return bit.get(val) - bit.get(val-1) ;
	}
	int at(int pos){
		return bit.find(pos);
	}


	int count_lower(int val){
		return bit.get(val-1) + 1;
	}

}Set;





int main(void){
	fast;


	#ifdef Khaled 
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	map<int,int>ref;
	map<int,int>dref;
	int q;
	cin >> q;
	vector<pair<char,int>>cmd(q);
	for(int i = 0;i<q;i++){
		cin >> cmd[i].first >> cmd[i].second;
		ref[cmd[i].second]++;
	}
	int f = 1;
	for(auto it = ref.begin();it != ref.end();it++){
		dref.insert({f,it->first});
		it->second = f++;	
	}
	


	for(auto it : cmd){
		char type = it.first;
		int val = ref[it.second];
		if(type == 'I'){
			if(!Set.count(val))
				Set.insert(val);
		}
		else if(type == 'D'){
			if(Set.count(val))
				Set.erase(val);
		}
		else if(type == 'C'){
			cout << Set.count_lower(val) << endl;
		}
		else {
			val = it.second;
			if(Set.size() < val)
				cout << "invalid\n";
			else
				 cout << dref[Set.at(val-1)] << endl;
		}

	}




	
}