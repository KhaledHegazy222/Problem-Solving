#include <bits/stdc++.h>

#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long
using namespace std;

int cmp(pair<int,int> &a,pair<int,int> & b){
    return a.second < b.second;
}


int main(void){

    fast;
    int n;
    cin >> n;
    vector<pair<int,int>>orders(n);
    for(int i = 0;i<n;i++)
        cin >> orders[i].first >> orders[i].second;

    sort(orders.begin(),orders.end(),cmp);

    int res = 0;
    int tim = -1;
    for(int i = 0;i<n;i++){
        if(orders[i].first > tim){
            res++;
            tim = orders[i].second;
        }
    }
    cout << res << endl;

}