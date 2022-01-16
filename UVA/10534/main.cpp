#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;



vector<int> LIS(vector<int> &arr){
    int n = arr.size();
    vector<int>lst,res(n);
    for(int i = 0;i<n;i++){
        auto it = lower_bound(all(lst),arr[i]);
        if(it == lst.end()){
            lst.push_back(arr[i]);
        }
        else{
            *it = arr[i];
        }
        res[i] = lst.size(); 
    }
    return res;
}




signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    int n;
    while(cin >> n){
        vector<int>arr(n);
        for(int i = 0;i<n;i++)
            cin >> arr[i];
        vector<int>arr_rev = arr;
        reverse(all(arr_rev));
    
        auto res = LIS(arr);
        auto res_rev = LIS(arr_rev);
        int sol = 0;
        for(int i = 0;i<n;i++){
            if(res[i] == res_rev[n - i - 1])
                sol = max(sol,res[i] + res_rev[n - i  - 1] - 1);
        }
        cout << sol << endl;
    }

}