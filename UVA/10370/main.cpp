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

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0;i<n;i++)
            cin >> arr[i];
        
        int avg = accumulate(arr,arr + n,0);
        double cnt = 0;
        for(int i = 0;i<n;i++){
            if(arr[i] * n > avg)
                cnt++;
        }
        cout << fixed << setprecision(3) <<  cnt / n * 100 << "%" << endl;
    }

}