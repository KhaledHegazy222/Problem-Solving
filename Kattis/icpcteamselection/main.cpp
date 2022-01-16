
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;


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
    while(t--){
        int n;
        cin >> n;
        int arr[3 * n];
        for(int i = 0;i<3*n;i++){
            cin >> arr[i];
        }
        sort(arr,arr + 3*n);
        int sum = 0;
        int taken = 0;
        for(int i = 3*n - 1;taken !=n;taken++){
            sum += arr[i-1];
            i-=2;
        }
        cout << sum << endl;
    }



}