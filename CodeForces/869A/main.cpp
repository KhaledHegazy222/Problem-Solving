


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



    unordered_set<int>st;

    int n;
    cin >> n;
    int first[n],second[n];
    for(int i = 0;i<n;i++){
        cin >> first[i];
        st.insert(first[i]);
    }
    for(int i = 0;i<n;i++){
        cin >> second[i];
        st.insert(second[i]);
    }

    int total = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            int f = first[i] ^ second[j];
            if(st.find(f) != st.end()){
                total++;
            }
        }
    }
    if(total % 2 == 0){
        cout << "Karen\n";
    }
    else {
        cout << "Koyomi\n";
    }

}