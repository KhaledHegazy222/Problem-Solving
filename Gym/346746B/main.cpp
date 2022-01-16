#include <bits/stdc++.h>

#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long
using namespace std;

int main(void){

    fast;
    
    int t;
    cin >> t;
    while(t--){
        ll m;
        int n;
        cin >> n >> m;
        int arr[n];
        for(int i = 0;i<n;i++)
            cin >> arr[i];
        sort(arr, arr + n);
        int sol = 0;
        for(int i = 0;i<n;i++){
            if(arr[i] <= m){
                m -= arr[i];
                sol++;
            }
            else{
                break;
            }
        }
        cout << sol << endl;
    }

    

}