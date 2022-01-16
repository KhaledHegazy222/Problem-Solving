
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define oo ((ll) 1e9)
#define _oo ((ll) -1e9)
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
#define mod ((ll)1e7)
 
 
using namespace std;
 
int count(vector<int>&v,int color,int index){
    int cnt = 0;
    while(index < v.size() && v[index++] == color){
        cnt++;
    }
    return cnt;
}
 
int rm(vector<int>v,int index){
    int removed = 0;
    int color = v[index];
    while(index != v.size() && v[index] == color){
        v.erase(v.begin() + index);
        removed++;
    }
    bool change = true;
    while(change){
        change = false;
        for(int i = 0;i<v.size();i++){
            if(count(v,v[i],i)> 2){
                change = true;
                color = v[i];
                index = i;
                while(index != v.size() && v[index] == color){
                    v.erase(v.begin() + index);
                    removed++;
                }
            }
        }
    }
    return removed;
}
 
 
int bk(vector<int>&v,int color){
    int ret = 0;
    for(int i = 0;i<v.size();i++){
        int x;
        if(v[i] == color && (x = count(v,color,i)) != 1){
            ret = max(ret,rm(v,i));
        }
    }
    return ret;
}
 
 
int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
        // loop:
    #endif
 
    int n,k,x;
    cin >> n >> k >> x;
    vector<int>balls(n);
    for(int i =0;i<n;i++){
        cin >> balls[i];
    }
 
    cout << bk(balls,x) << endl;
 
 
 
 
 
    #ifdef offline_vs_code
        //goto loop;
    #endif 
 
 
 
 
 
 
 
 
 
}