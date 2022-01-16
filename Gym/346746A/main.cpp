#include <bits/stdc++.h>

#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long
using namespace std;

int main(void){

    fast;
    freopen("min.in","r",stdin);

    int n,k;
    cin >> n >> k;
    multimap<int,int>rest;
    for(int i = 0;i<k;i++){
        int idx,val;
        cin >> idx >> val;
        rest.insert({val,idx - 1});
    }
    int prices[n];
    fill(prices,prices + n,1e9);















    while(rest.size()){
        int v = rest.begin()->first;
        int idx = rest.begin()->second;

        rest.erase(rest.begin());


        for(int i = idx,j = 0;i<n;i++,j++){
            if(prices[i] < v + j)
                break;
            prices[i] = v + j;

        }


        for(int i = idx,j = 0;i>=0;i--,j++){
            if(prices[i] < v + j)
                break;
            prices[i] = v + j;
        }
    }
    for(int i = 0;i<n;i++){
        cout << prices[i] << " ";
    }
    cout << endl;

}