/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
const int N = 1e5 + 5;

int comp[N],arr[N],freq[N];
int qi[N],qs[N],qe[N],qAns[N];

int n,q,blk,st,en,ans;




void add(int val){
	if(freq[val] == comp[val]){
		ans --;
	}
	else if(freq[val] + 1 == comp[val]){
		ans ++;
	}
	freq[val]++;
	
}
void del(int val){
	if(freq[val] == comp[val]){
		ans --;
	}
	else if(freq[val] - 1 == comp[val]){
		ans ++;
	}
	
	freq[val]--;
}



void update(int qid){
	while(st < qs[qi[qid]]) del(arr[st++]);
	while(st > qs[qi[qid]]) add(arr[--st]);
	while(en > qe[qi[qid]]) del(arr[--en]);
	while(en <= qe[qi[qid]]) add(arr[en++]);
}



void compress(void){
	sort(comp,comp + n);
	int sz = unique(comp,comp + n) - comp;
	for(int i = 0;i<n;i++){
		arr[i] = lower_bound(comp,comp+sz,arr[i]) - comp;
	}
}



int main(void){

	fast;

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif



	cin >> n >> q;
	for(int i = 0;i<n;++i){
		cin >> arr[i];
		comp[i] = arr[i];
	}
	compress();


	for(int i = 0;i < q;i++){
		qi[i] = i;
		cin >> qs[i] >> qe[i];
		qs[i]--,qe[i]--;
	}

	blk = sqrt(n);

	sort(qi,qi+q,[](int a,int b){
		return make_pair(qs[a] / blk,qe[a]) < make_pair(qs[b] / blk,qe[b]);
	});

	for(int i = 0;i<q;i++){
		update(i);
		qAns[qi[i]] = ans;
	}
	

	for(int i = 0;i<q;i++){
		cout << qAns[i] << endl;
	}



}