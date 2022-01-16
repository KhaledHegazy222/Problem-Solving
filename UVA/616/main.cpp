#include <bits/stdc++.h>

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

    int n;
    while(cin >> n && n >= 0){
        int found = 0;
        int xx = -1;
        for(ll i = 2;i * i <=n || i < 100;i++){
            int rem = n;
            int valid = 1;
            for(int j = 0;j<i;j++){
                if(rem % i != 1){
                    valid = 0;
                    break;
                }
                rem--;
                rem -= rem / i;
            }
            if(rem % i != 0)
                valid = 0;

            if(valid){
                found = 1;
                xx = i;
            }
        }
        if(!found)
            cout << n << " coconuts, no solution\n";
        else    
            cout << n << " coconuts, " << xx << " people and 1 monkey\n";
    }

}