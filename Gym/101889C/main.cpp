#include <bits/stdc++.h>
#ifndef Khaled
    #define endl '\n'
#endif
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

signed main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    int k,n;
    cin >> k >> n;
    int frq[k] = {0};
    for(int i = 0;i<n;i++){
        int c;
        cin >> c;
        --c;
        frq[c]++;
    }
    int valid = 1;
    
    for(int i = 0;i<k;i++)
        frq[i] = frq[i] - (n / k);
    
    int a = count(frq,frq + k,0);
    int b = count(frq,frq + k,-1);
    int c = count(frq,frq + k,1);

    if(a + b + c != k || a == n || b > 1 || c > 1)
        valid = 0;

    string op1,op2;
    if(valid){
        if(c){
            for(int i = 0;i<k;i++)
                if(frq[i] == 1)
                    cout << "-" << i + 1 << " ";
        }
        if(b){
            for(int i = 0;i<k;i++)
                if(frq[i] == -1)
                    cout << "+" << i + 1 << endl;
        }
        return 0;
    }

    valid = 1;
    
    for(int i = 0;i<k;i++)
        frq[i] = frq[i] + (n / k);

    n = (n + k - 1);
    
    for(int i = 0;i<k;i++)
        frq[i] = frq[i] - (n / k);
    
    a = count(frq,frq + k,0);
    b = count(frq,frq + k,-1);
    c = count(frq,frq + k,1);

    if(a + b + c != k || a == k || b > 1 || c > 1)
        valid = 0;

    if(valid){
        if(c){
            for(int i = 0;i<k;i++)
                if(frq[i] == 1)
                    cout << "-" << i + 1 << " ";
        }
        if(b){
            for(int i = 0;i<k;i++)
                if(frq[i] == -1)
                    cout << "+" << i + 1 << endl;
        }
        return 0;
    }
        

    
    if(!valid)
        cout << "*" << endl;
    


}