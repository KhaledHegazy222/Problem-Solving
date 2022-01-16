
#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;
const int N = 21;
int n,w;
int weight[N],value[N];
int knapsack(int pos,int remain){

	if(pos == n)
		return 0;

	int ch1 = knapsack(pos + 1,remain);
	int ch2 = 0;
	if(remain >= weight[pos])
		ch2 = value[pos] + knapsack(pos + 1,remain - weight[pos]);	


	return max(ch1,ch2);

}


int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	

	cin >> n >> w;
	for(int i = 0;i<n;i++){
		cin >> weight[i] >> value[i];
	}
	cout << knapsack(0,w) << endl;
	


}