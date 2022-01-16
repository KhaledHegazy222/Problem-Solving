
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;
const int N = 2e5 + 1;
int arr[N], n;
int valid(int k){
    int lst = 0; 
    for(int i = 0;i<n;i++){
        if(arr[i] - lst > k ) return 0;
        else if(arr[i] - lst == k) k--;   
        lst = arr[i];
    }
    return 1;
}




int main(void){

    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);    
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    int t;
    cin >> t;
    for(int cs = 1;cs<=t;cs++){       
        cin >> n;
        for(int i = 0;i<n;i++)  
            cin >> arr[i];


        int l = 0;
        int r = 1e9;
        while(l!=r){
            int mid = l + (r-l)/2;
            if(valid(mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << "Case " << cs << ": " << l << "\n";

    }

}
