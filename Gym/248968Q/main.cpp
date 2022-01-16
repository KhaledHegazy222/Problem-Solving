

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
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif

    int n,m;
    cin >> n >> m;
    int sum = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            sum ++;
        }
    }
    for(int i = 0;i<m;i++){
        for(int j = i+1;j<m;j++){
            sum ++;
        }
    }

    cout << sum << endl;
}


