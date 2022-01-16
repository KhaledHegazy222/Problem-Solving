


#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;
const int N = 2e5 + 1;








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
    int arr[n];
    int g;
    int mx = 0;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
        mx = max(mx,arr[i]);
        if(!i)
            g = arr[i];
        else
            g = __gcd(arr[i],g);
    }

    int cnt = mx / g;
    for(int i = 0;i<n;i++){
        if(arr[i] % g == 0) cnt--;
    }
    if(cnt % 2){
        cout << "Alice\n";
    }
    else{
        cout << "Bob\n";
    }

}
