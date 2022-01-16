/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const int N = 10001;
ll c[N],m[N];
void init(){
	memset(c,0,sizeof(c));
	memset(m,0,sizeof(m));
}



ll get(int pos){
	int x = pos;
	pos++;
	ll ret = 0;
	while(pos){
		ret += m[pos-1] * x + c[pos-1];
		pos -= pos & -pos; 
	}
	return ret;
}

void add(int pos,int mval,int cval){
	pos++;
	while(pos <= N){
		m[pos-1] += mval;
		c[pos-1] += cval;
		pos += pos & -pos;
	}
}



void add_range(int st,int en,int val){
	add(st,val,-1 *((st-1) * val));
	add(en+1,-val,en * val);
}



int main(void){
	fast;
	#ifdef Khaled
		freopen("out.txt","w",stdout);
		freopen("in.txt","r",stdin);
	#endif
	#ifndef Khaled
		//freopen(".in","r",stdin);
	#endif





	int t;
	cin >> t;
	while(t--){
		init();
		int n,u;
		cin >> n >> u;
		while(u--){
			int l,r,val;
			cin >> l >> r >> val;
			add_range(l,r,val);

			
		}
		int q;
		cin >> q;
		while(q--){
			int idx;
			cin >> idx;
			cout << get(idx) - get(idx-1)  << endl;
		}
	}

	// init();

	// add_range(0,10,3);
	
}
