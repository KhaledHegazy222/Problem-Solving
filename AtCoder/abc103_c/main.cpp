
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(void){
    int n;
    cin >> n;
    ll arr[n];
    ll res = 0;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        res += arr[i]-1;
    }
    cout << res << endl;
}