#include <bits/stdc++.h>

#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long
using namespace std;

int main(void){

    fast;
    int q;
    cin >> q;
    priority_queue<int,vector<int>,greater<int>>pq;
    queue<int>qu;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            qu.push(x);
        }
        else if(type == 2){
            if(pq.size()){
                cout << pq.top() << endl;
                pq.pop();
            }
            else{
                cout << qu.front() << endl;
                qu.pop();
            }
        }
        else{
            while(qu.size()){
                pq.push(qu.front());
                qu.pop();
            }
        }
    }

}