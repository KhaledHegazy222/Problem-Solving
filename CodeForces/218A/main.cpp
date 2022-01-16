
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
 
 
using namespace std;
  
  
int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    int n,k;
    cin >> n >> k;
    vector<int>points(2*n + 1);
    for(int i = 0;i< 2 * n + 1;i++){
        cin >> points[i];
    }
    for(int i = 1;i< 2 * n  && k;i++){
        if(points[i]-1 > points[i-1] && points[i]-1 > points[i+1]){
            points[i]--;
            k--;
        }
    }
    for(auto it:points){
        cout << it << " ";
    }
    cout << endl;

}


