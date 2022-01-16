#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;



int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    int n;
    while(cin >> n,n){
        int arr[n];
        for(int i = 0;i<n;i++)
            cin >> arr[i];
        int a = 0,b = (n * (n - 1)) / 2;
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                if(__gcd(arr[i],arr[j]) == 1)
                    a++;
            }
        }
        if(!a){
            cout << "No estimate for this data set.\n";
            continue;
        }
        double res = (b + 0.0) / a;
        cout << fixed << setprecision(6) << sqrt(res * 6) << endl;
    }
}