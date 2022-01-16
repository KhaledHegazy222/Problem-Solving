

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define pi (3.14159265)

typedef unsigned long long ull;
typedef long long ll;

using namespace std;




int main(void){

    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);    
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif 
    int n;
    int print = 0;
    while(1){
        cin >> n;
        if(!n) return 0;
        vector<pair<int,int>>first(n);
        vector<int>second(n);
        if(print) cout << "\n";
        print = 1;
        for(int i = 0;i<n;i++){
            cin >> first[i].first;
            first[i].second = i;
        }
        for(int i = 0;i<n;i++){
            cin >> second[i];
        }
        int res[n];
        sort(all(first));
        sort(all(second));
        for(int i = 0;i<n;i++){
            res[first[i].second] = second[i];
        }
        for(int i = 0;i<n;i++){
            cout << res[i] << "\n";
        }
        




    }

}
