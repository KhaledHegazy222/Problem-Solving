

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
   
    ll a,b;
    cin >> a >> b;
    ll z = max(a,b);
    a = min(a,b);
    b = z;
    ll sum1 = (b * (b+1) / 2 ) - (a*(a-1) / 2);
    ll e1 = a;
    ll e2 = b;
    ll o1 = a;
    ll o2 = b;
    if(e1 % 2){
        e1++;
    }
    if(e2 % 2){
        e2--;
    }
    ll sum2 = 0;
    if(e1 <= e2){
        int n = (e2-e1)/2 + 1;
        sum2 = n * (e1 + e2) / 2;
    }



    if(o1 % 2 == 0){
        o1++;
    }
    if(o2 % 2 == 0){
        o2--;
    }
    
    ll sum3 = 0;
    if(o1 <= o2){
        int n = (o2-o1)/2 + 1;
        sum3 = n * (o1 + o2) / 2;
    }
    cout << sum1 << endl;
    cout << (sum2) << endl;
    cout << (sum3) << endl;
}
