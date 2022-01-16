#include <bits/stdc++.h>
#define endl '\n'
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

string bigIntsAdd(string a,string b){
    string finalsum; 
    int carry=0;  
    int i = a.size()-1,j=b.size()-1; 
    while((i>=0) and (j>=0)){     
        int x = (a[i]-'0') + (b[j]-'0') + carry; 
        finalsum.push_back((x%10) + '0');
        carry = x/10;     
        i--;              
        j--;
    }
    while(i>=0){          
        int x = (a[i]-'0') + carry;
        finalsum.push_back((x%10) + '0');
        carry = x/10;  
        i--;
    }
    while(j>=0){      
        int x = (b[j]-'0') + carry;
        finalsum.push_back((x%10) + '0');
        carry = x/10; 
        j--;
    }
    while(carry){   
        finalsum.push_back((carry%10) + '0'); 
        carry=carry/10;       
    }
    reverse(all(finalsum));
    return finalsum;
}

int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
    string res[1001];
    res[0] = "1";
    res[1] = "2";
    res[2] = "5";
    res[3] = "13";
    for(int i = 4;i<=1000;i++){
        res[i] = bigIntsAdd(res[i - 1],res[i - 1]);
        res[i] = bigIntsAdd(res[i],res[i - 2]);
        res[i] = bigIntsAdd(res[i],res[i - 3]);
    }
    int n;
    while(cin >> n){
        cout << res[n] << endl;
    }


}