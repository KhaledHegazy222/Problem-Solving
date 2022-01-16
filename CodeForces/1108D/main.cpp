

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

using namespace std;

char valid(char a,char b,char c){
    if('R' != a && 'R' !=c) {
        return 'R';
    }
    if('G' != a && 'G' !=c) {
        return 'G';
    }
    if('B' != a && 'B' !=c) {
        return 'B';
    }
}

int  main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif


    int n;
    cin >> n;
    vector<char>v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }

    int rem = 0;
    for(int i = 1;i<n;i++){
        if(v[i] == v[i-1]){
            if(i < n-1){
                v[i] = valid(v[i-1],v[i],v[i+1]);
            }
            else{
                v[i] = valid(v[i-1],v[i],v[i-1]);
            }
            rem++;
        }

    }


    cout <<rem << endl;
    for(auto it: v){
        cout << it;
    }
    cout << endl;


}