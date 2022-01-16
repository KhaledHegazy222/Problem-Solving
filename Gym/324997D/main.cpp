#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

vector<int> merge_sort(vector<int>v){
	if(v.size() == 1) return v;
	
	int n = v.size();
	int mid = n / 2;
	vector<int>l(v.begin(),v.begin() + mid);
	vector<int>r(v.begin() + mid,v.end());


	l = merge_sort(l);
	r = merge_sort(r);
	
	merge(all(l),all(r),v.begin());
	return v;
}

void merge_sort(int arr[],int st,int en){
	if(st == en) return;
	int mid = st + (en - st) / 2;
	merge_sort(arr,st,mid);
	merge_sort(arr,mid+1,en);
	int l[mid - st + 1];
	int r[en - mid];
	for(int i = st,j = 0;i<=mid;j++,i++){
		l[j] = arr[i];
	}
	for(int i = mid + 1,j = 0;i<=en;j++,i++){
		r[j] = arr[i];
	}

	merge(l,l + mid - st + 1,r,r + en - mid,arr + st);
	


}




int main(void){	
	fast;
	#ifdef Khaled
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif	
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	merge_sort(arr,0,n - 1);
	
	for(int i = 0;i<n;i++){
		cout << arr[i] << " \n"[i + 1==n];
	}



}