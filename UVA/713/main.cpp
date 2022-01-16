#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


string bigIntsAdd(string &a,string &b){
    string finalsum = ""; 
    int carry=0;  
    int i = a.size()-1,j=b.size()-1; 
    while((i>=0) and (j>=0)){     
        int x = (a[i]-'0') + (b[j]-'0') + carry; 
        finalsum.push_back((x%10)+ '0');
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
    return finalsum;
}


string bigIntsMultiply(string &num1, string &num2){


    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i=len1-1; i>=0; i--){
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;
        for (int j=len2-1; j>=0; j--){
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

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;

    string a,b;
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        reverse(all(a));
        reverse(all(b));
        string res =  bigIntsAdd(a,b);
        int i = 0;
        while(i < res.size() && res[i] == '0')
            i++;
        if(i == res.size())
            cout << 0 << endl;
        else
            cout << res.substr(i) << endl;
    }




}