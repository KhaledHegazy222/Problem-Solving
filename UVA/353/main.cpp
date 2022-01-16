
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)
#define MAX 100000

using namespace std;


int palindrome(string &s,int begin,int end){

    while(begin < end){
        if(s[begin++] != s[end--]){
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
    string s;
    while(cin >> s){
        map<string,int>pals;
        for(int i = 0;i<s.size();i++){
            for(int j = i;j<s.size();j++){
                if(palindrome(s,i,j)){
                    string go = s.substr(i,j-i+1);
                    pals[go]++;
                }
            }
        }
        cout << "The string \'" << s << "\' contains " << pals.size() << " palindromes.\n";
    }
}

