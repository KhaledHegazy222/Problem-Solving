#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie();
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef unsigned long long ull;

using namespace std;



signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int a,b,need;
    while(cin >> a >> b >> need){
        string big = "B",small = "A";
        int aa = 0,bb = 0;
        if(a > b)   
            swap(big,small),swap(a,b);
        while(bb != need){
            cout << "fill " << small << endl;
            aa = a;
            cout << "pour " << small << " " << big << endl;
            if(bb + aa > b){
                int rem = b - bb;
                aa -= rem;
                bb += rem;
                if(bb == need)
                    break;
                cout << "empty " << big << endl;
                bb = 0;
                cout << "pour " << small << " " << big << endl;
                bb += aa;
                aa = 0;
            }
            else{
                bb += aa;
                aa = 0;
            }
            if(bb == need)
                break;
        }
        cout << "success\n";
        

    }    

}



