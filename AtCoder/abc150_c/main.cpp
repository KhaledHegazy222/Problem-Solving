
#include <bits/stdc++.h>

typedef unsigned long long ull;
typedef long long ll;

#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;

int cmp(vector<int>&v1,vector<int>&v2){
    for(int i=0;i<v1.size();i++){
        if(v1[i] != v2[i]){
            return 0;
        }
    }
    return 1;
}


int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif

    int n;
    cin >> n;
    vector<int>v1(n);
    vector<int>v4(n);
    vector<int>v2(n);
    vector<int>v3(n);
    for(int i = 0;i<n;i++){
        v1[i] = i+1;
        v2[i] = i+1;
    }
    for(int i = 0;i<n;i++){
        cin >> v3[i];
    }
    for(int i = 0;i<n;i++){
        cin >> v4[i];
    }
    int pos1 = 0;
    int pos2 = 0;
    while(!cmp(v1,v3)){
        next_permutation(all(v1));
        pos1++;
    }
    while(!cmp(v2,v4)){
        next_permutation(all(v2));
        pos2++;
    }
    cout << abs(pos1-pos2) << endl;
    
}

