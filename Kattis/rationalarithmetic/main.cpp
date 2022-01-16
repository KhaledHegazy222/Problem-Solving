
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;



const int N = 2e5 + 1;

int main(void){

    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);    
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    
    int t;
    cin >> t;
    while(t--){
        ll x1,y1,x2,y2;        
        char op;

        cin >> x1 >> y1 >> op >> x2 >> y2;
        int m1 = 0;
        int m2 = 0;
        if((x1 < 0 ) ^ (y1 < 0)){
            m1++;
        }
        if((x2 < 0 ) ^ (y2 < 0)){
            m2++;
        }




        x1 = abs(x1);
        y1 = abs(y1);
        x2 = abs(x2);
        y2 = abs(y2);
        
        if(m1){
            x1 = -x1;
        }
        if(m2){
            x2 = -x2;
        }


        switch(op){
            case '+':
                x1 *= y2;
                x2 *= y1;
                x1 += x2;
                y1 *= y2;
            break;
            case '-':
                x1 *= y2;
                x2 *= y1;
                x1 -= x2;
                y1 *= y2;
            break;
            case '*':
                x1 *= x2;
                y1 *= y2;
            break;
            case '/':
                x1 *= y2;
                y1 *= x2;
            break;
        }


        if((x1 < 0 ) ^ (y1 < 0)){
            m1 = 1;
        }
        else{
            m1 = 0;
        }
        x1 = abs(x1);
        y1 = abs(y1);

        ll a = __gcd(x1,y1);
        x1 /= a;
        y1 /= a;

        if(m1){
            cout << "-";
        }

        cout << x1 << " / " << y1 << endl;




    }
}
