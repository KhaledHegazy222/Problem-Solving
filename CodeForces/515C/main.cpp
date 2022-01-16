
 
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define oo ((ll) 1e9)
#define _oo ((ll) -1e9)
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
#define mod ((ll)1e7)
 
 
using namespace std;
 
int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifdef offline_vs_code
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
        // loop:
    #endif
 
 
 
 
    int prime[10] = {0,0,1,1,0,1,0,1,0,0};
    vector<int>v;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        char x;
        cin >> x;
        int digit = x - '0';
        
        if(prime[digit]){
           v.push_back(digit); 
        }
        else if(digit >= 4){
            while(!prime[digit]){
                if(digit == 9){
                    v.push_back(3);
                    v.push_back(3);
                    v.push_back(2);
                    digit--;
                }
                else if(digit == 8){
                    v.push_back(2);
                    v.push_back(2);
                    v.push_back(2);
                }
                else if(digit == 6){
                    v.push_back(3);
                }
                else if(digit == 4){
                    v.push_back(2);
                    v.push_back(2);
                }
                digit--;
            }
            v.push_back(digit);
        }
 
    }
    sort(all(v),greater<int>());
    for(auto it:v){
        cout << it;
    }
    cout << endl;
 
 
    #ifdef offline_vs_code
        //goto loop;
    #endif 
 
 
}