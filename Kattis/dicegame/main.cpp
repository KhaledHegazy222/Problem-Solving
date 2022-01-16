
#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define fast cin.tie(),ios::sync_with_stdio(0)
using namespace std;


typedef unsigned long long ull;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;



int main(void){
    fast;
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 


    double s1=0,s2=0;
    int a1,b1,a2,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    double sum = 0;
    for(int i = a1;i<=a2;i++){
        sum += i;
    }
    s1 += sum / (a2-a1+1);
    sum = 0;
    for(int i = b1;i<=b2;i++){
        sum += i;
    }
    s1 += sum / (b2-b1+1);
    sum = 0;
    cin >> a1 >> a2 >> b1 >> b2;
    for(int i = a1;i<=a2;i++){
        sum += i;
    }
    s2 += sum / (a2-a1+1);
    sum = 0;
    for(int i = b1;i<=b2;i++){
        sum += i;
    }
    s2 += sum / (b2-b1+1);
    if(abs(s1-s2) < 1e-6) cout << "Tie\n";
    else if(s1 > s2) cout << "Gunnar\n";
    else cout << "Emma\n";

    

}   