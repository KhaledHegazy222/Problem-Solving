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
    string a,b;
    cin >> a >> b;
    queue<char>ev,od;
    deque<char>v1,v2;
    for(int i = 0;i<a.size();i++){
        if((a[i] - 'a') % 2){
            od.push(a[i]);
            v1.push_back(a[i]);
        }
        else{
            ev.push(a[i]);
            v2.push_back(a[i]);            
        }
    }
    int valid = 1;
    
    for(int i = 0;i<a.size();i++){
        int x = (b[i] - 'a') % 2;
        char cc = b[i];
        char f = v1.front();
        char f2 = v2.front();
        if((b[i] - 'a') % 2 && v1.size() && v1.front() == b[i]){
            v1.pop_front();
        }
        else if(((b[i] - 'a') % 2) == 0 && v2.size() && v2.front() == b[i])
            v2.pop_front();
        else{
            valid = 0;
            break;
        }
            
    }
    cout << (valid ? "Yes\n" : "No\n" );



}