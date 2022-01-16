
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(),ios::sync_with_stdio(0)
using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;

ll merge(int v[],int begin1,int end1,int begin2,int end2){
    int s1 = end1-begin1+1;
    int s2 = end2-begin2+1;
    int a[s2];
    int b[s2];
    for(int x = begin1,y = 0; x<= end1;x++,y++){
        a[y] = v[x];
    }
    for(int x = begin2,y = 0; x<= end2;x++,y++){
        b[y] = v[x];
    }
    int i = 0;
    int j = 0;
    ll cnt = 0;
    int idx = begin1;
    while(i < s1  && j < s2){
        if(a[i] < b[j])
            v[idx] = a[i++];
        else{
            v[idx] = b[j++];
            cnt += 0ll + s1 - i;
        }
        idx++;
    }
    while(i<s1){
        v[idx++] = a[i++];
    }
    while(j<s2){
        v[idx++] = b[j++];
    }
    return cnt;
}


ll merge_sort(int v[],int begin,int end){
    if(begin >= end) return 0;
    int mid = (begin+end)/2;
    ll ret = merge_sort(v,begin,mid);
    ret += merge_sort(v,mid+1,end);
    return ret + merge(v,begin,mid,mid+1,end);
}



int main(void){
    fast;
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    


    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        cout << merge_sort(arr,0,n-1) << '\n';
        for(int i = 0;i<n;i++){
            //cout << arr[i] << ' ';
        }
        //cout << '\n';
    }

}   