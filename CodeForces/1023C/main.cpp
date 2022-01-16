
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

using namespace std;


int  main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif


    int n ,m;
    cin >> n >> m;
    int x = 0;
    int y = 0;
    for(int i = 0;i<n;i++){
        char c;
        cin >> c;
        cout << c;
        if(c == '('){
            x++;
        }
        else{
            y++;
        }
        if(2*x ==m ){
            break;
        }
    }
    while(y++<x){
        cout << ')';
    }
    cout << endl;


}