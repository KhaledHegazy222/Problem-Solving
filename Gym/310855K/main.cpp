
#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;


string mult(string num1, string num2) 
{ 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
    return "0"; 
  
    vector<int> result(len1 + len2, 0); 
  
    int i_n1 = 0;  
    int i_n2 = 0;  
      
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
  
        i_n2 = 0;  
          
        for (int j=len2-1; j>=0; j--) 
        { 
            int n2 = num2[j] - '0'; 
  
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
  
            carry = sum/10; 
  
            result[i_n1 + i_n2] = sum % 10; 
  
            i_n2++; 
        } 
  
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
  
        i_n1++; 
    } 
  
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
  
    if (i == -1) 
    return "0"; 
  
    string s = ""; 
      
    while (i >= 0) 
        s += std::to_string(result[i--]); 
  
    return s; 
} 

int main(void){
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("out.txt","w",stdout);
        freopen("in.txt","r",stdin);
    #endif
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        cout << mult(a,b) << endl;
    }
    
}