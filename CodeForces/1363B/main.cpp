
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
 
 
using namespace std;

int count0(string &s,int begin,int end){
    int cnt= 0;
    for(int i = begin;i<end;i++){
        if(s[i] == '1'){
            cnt++;
        }
    }
    return cnt;
}
int count1(string &s,int begin,int end){
    int cnt= 0;
    for(int i = begin;i<end;i++){
        if(s[i] == '0'){
            cnt++;
        }
    }
    return cnt;
}

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
        string s;
        cin >> s;
        int m = 1e6;

        for(int i = 0;i<s.length();i++){
            m = min(m,min(count0(s,0,i)+ count1(s,i+1,s.length() ) ,  count1(s,0,i)+ count0(s,i+1,s.length() )  )   )   ;
        }
        cout << m << endl;
    }



}
