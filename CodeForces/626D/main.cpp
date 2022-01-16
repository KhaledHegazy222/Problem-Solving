#include <bits/stdc++.h>
#define endl '\n'
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
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++)
        cin >> arr[i];
    int sets = n * (n - 1) / 2;
    double prob[5000 + 1] = {0};
    for(int i = 0;i<n;i++)
        for(int j = i + 1;j < n;j++)
            prob[abs(arr[i] - arr[j])] += 1.0 / sets;
    
    double suf[5000 + 1];
    suf[5000] = prob[5000];
    for(int i = 5000 - 1;i>=0;i--){
        suf[i] = suf[i + 1] + prob[i];
    }
    double ans = 0;
    for(int i = 0;i<=5000;i++){
        for(int j = 0;j<=5000;j++){
            if(i + j < 5000)
                ans += suf[i + j + 1] * prob[i] * prob[j];
        }
    }
    cout << fixed << setprecision(11) << ans << endl;
    

}