

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int bs(int arr[],int n,int f){
    int l = 0;
    int r = n-1;
    while(l <= r){
        int mid = l +(r-l)/2;
        if(arr[mid] == f){
            return 1;
        }
        else if(arr[mid] > f){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return 0;
}



int main(void){

    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);    
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    int n,m,a,c,x0;
    cin >> n >> m >> a >> c >> x0;
    int arr[n];
    int sorted[n];
    int lst = x0;
    for(int i = 0;i<n;i++){
        arr[i] = (lst * 1ll * a + c)%m;
        lst = arr[i]; 
    }

    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(bs(arr,n,arr[i])){
            cnt++;
        }
    }
    cout << cnt << endl;



}
