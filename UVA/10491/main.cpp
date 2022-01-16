#include <cstring>
#include <iostream>
#include <vector>
#include<map>
#include <math.h>
#include <iomanip>
#include <algorithm>
#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main(void){

    #ifdef Khaled
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    fast;
	double cows,cars,show;
	cout << fixed << setprecision(5);
	while(cin >> cows >>cars >> show){
			double res = 0;
			if(abs(cars) < 1e-3 ){
				cout<< 0 << endl;
				continue;
			}
			if(abs(cows) < 1e-3){
				cout<< 1.0 << endl;
				continue;
			}
			
			res += cows * (cars / (max(0.0,cows - 1- show)  +cars));
			res += cars * ((cars - 1) / (cows - show + cars - 1));
			cout <<res / (cows +cars ) << endl;
		
	}

			
			           
}