/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

const int N = 1e6 + 5;

int n,q,st,en,Bsz,arr[N],qi[N],qs[N],qe[N],freq[N];

ll ans,qAns[N];



void add(int val){

	ans -= 1ll * freq[val] * freq[val] * val;
	freq[val]++;
	ans += 1ll * freq[val] * freq[val] * val;

}

void del(int val){

	ans -= 1ll * freq[val] * freq[val] * val;
	freq[val]--;
	ans += 1ll * freq[val] * freq[val] * val;

}

void update(int idx){
	while(st < qs[idx]) del(arr[st++]);
	while(st > qs[idx]) add(arr[--st]);
	while(en <= qe[idx]) add(arr[en++]);
	while(en - 1 > qe[idx]) del(arr[--en]); 
}




int main(void){

	fast;

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	cin >> n >> q;
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}

	for(int i = 0;i<q;i++){
		qi[i] = i;
		cin >> qs[i] >> qe[i];
		qs[i]--,qe[i]--;
	}


	Bsz = sqrt(n);
	sort(qi,qi+q,[](int a,int b){
		return make_pair(qs[a] / Bsz,qe[a]) < make_pair(qs[b] / Bsz,qe[b]);
	});

	for(int i = 0;i<q;i++){
		update(qi[i]);
		qAns[qi[i]] = ans;
	}

	for(int i = 0;i<q;i++){
		cout << qAns[i] << endl;
	}





}