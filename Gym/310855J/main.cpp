

#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;

string add(string str1, string str2) { 
 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    string str = ""; 
  
    int n1 = str1.length(), n2 = str2.length(); 
  
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        carry = sum/10; 
    } 
  
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    if (carry) 
        str.push_back(carry+'0'); 
  
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
  

bool isSmaller(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
 
    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
 
    return false;
}

string sub (string str1,string str2){
    bool minus = false;
    if (isSmaller(str1, str2)){
        minus = true;
        swap(str1, str2);
 
    }
    string str = "";
 
    int n1 = str1.length(), n2 = str2.length();
 
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    for (int i = 0; i < n2; i++) {
 
        int sub_ = ((str1[i] - '0') - (str2[i] - '0') - carry);
 
        if (sub_ < 0) {
            sub_ = sub_ + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub_ + '0');
    }
 
    for (int i = n2; i < n1; i++) {
        int sub_ = ((str1[i] - '0') - carry);
 
        if (sub_ < 0) {
            sub_ = sub_ + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub_ + '0');
    }
 
    reverse(str.begin(), str.end());
    if(minus){
        str = "-" + str;
    }
    return str;
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
        int p;
        cin >> p;
        string s1;
        string s2;
        cin >> s1 >> s2;
        if(p == 1){
            cout << add(s1,s2) << endl;
        }
        else{

            string res = sub(s1,s2) ;
            int b = 0;
            if(res[0] == '-'){
                b++;
                cout << "-";
            }
            int i;
            bool print = false;
            for(i = b;i<res.size() && res[i] == '0';i++);
            for(;i<res.size();i++){
                cout << res[i];
                print = true;
            }
            if(!print){
                cout << 0;
            }
            cout << endl;
        }
    }
    
}