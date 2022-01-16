

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(void){
    
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i = 0;i<n;i++){
        cin >> arr[i];
    }
    for(ll i = 0;i<n;i++){

        for(ll j = i+1;j<n;j++){

            for(ll k = j+1;k<n;k++){

                if((arr[i]^arr[j]^arr[k]) == 0){

                    cout <<"YES\n";
                    return 0;

                }
            }
        }
    }
    cout << "NO\n";
}