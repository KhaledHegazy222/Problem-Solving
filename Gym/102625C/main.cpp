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
    int n,m;
    cin >> n >> m;
    priority_queue<int>pq;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        pq.push(-x);
    }
    vector<pair<int,int>>vp;
    while(m--){
        int x,c;
        cin >> x >> c;
        vp.push_back({x,c});
    }
    sort(all(vp));
    reverse(all(vp));
    for(auto it : vp){
        int x = it.first;
        int c = it.second;
        while(x-- && -pq.top() < c){
            pq.pop();
            pq.push(-c);
        }
    }
    ll sum = 0;
    while(pq.size()){
        sum += -pq.top();
        pq.pop();
    }
    cout << sum << endl;


} 