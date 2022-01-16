

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;







int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    int n;
    cin >> n;
    int arr[n] = {0};
    int res = 0;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        res ^= arr[i];
    }
    cout << (res != 0) << endl;






}