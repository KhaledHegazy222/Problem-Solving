

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;



using namespace std;
int arr[21];

int n;
int lis(int idx,int lst){
    if(idx == n+1){
        return 0;
    }
    int ch1 = lis(idx+1,lst);
    int ch2 = 0;
    if(arr[idx] > arr[lst]) {
        ch2 = 1 + lis(idx+1,idx);
    }
    return max(ch1,ch2);
}


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    
    arr[0] = INT_MIN;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
    }
    cout << lis(1,0) << endl;
}