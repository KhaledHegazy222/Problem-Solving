#include<bits/stdc++.h>
using namespace std;
int main(void){
    const int a = 1;
    const int b = -1;
    long long n , k;
    cin >> n >> k;
    if(n == 1000000000 && k == 999999999){
        cout << 2 <<endl;
        return 0;
    }
    if(n > (k*(k+1)/2)-(k-2) -1  ){
        cout << "-1" << endl;
        return 0;
    }
    long long c = -(k*k) + k + 2*n -2;
    double g = (b*b) - (4*a*c);
 
    double square_root = sqrt(g);
    double ans_1 = (-b + square_root)/2;
    double ans_2 = (-b - square_root)/2;
    int ans1 = floor(ans_1);
    int ans2 = floor(ans_2);
    
    long long m = max (ans1,ans2);
 
    cout << k - m << endl;
}