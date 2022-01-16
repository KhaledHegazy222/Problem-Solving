#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int p;

int power(int b,int po){
    int ret = 1;
    while(po){
        if(po & 1)
            ret = (ret * b) % p;
        b = (b * b) % p;
        po >>= 1;
    }
    return ret;
}


int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    cin >> p;
    int cnt = 0;
    for(int i = 1;i<p;i++){
        int val = 1;
        for(int j = 1;j < p - 1;j++){
            int x = power(i,j) - 1;
            if(x % p == 0){
                val = 0;
                break;
            }
        }
        if(val && (power(i,p - 1) - 1) % p == 0)
            cnt++;
        
    }
    cout << cnt << endl;

}
