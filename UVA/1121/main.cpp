
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(),ios::sync_with_stdio(0)
using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;


int main(void){
    fast;
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    

    int n,s;
    while(cin >> n >> s){
        int arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        int l = 0;
        int r = 0;
        int sum = 0;
        int length = INT_MAX;
        while(l<n){
            while(r<n && sum < s){
                sum += arr[r++];
            } 
            if(sum >= s){
                length = min(length,r-l);
            }
            sum -= arr[l++];
        }
        if(length == INT_MAX) length = 0;
        cout << length << '\n';
    }
}   