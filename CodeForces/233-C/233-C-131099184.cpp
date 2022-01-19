#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <queue> 
#include <set>
#include <stack>
#define INF 1000000000
#define PI 3.14159265
#define rep(i,a) for (int i = 0; i < a; i++)
#define rep1(i,a) for(int i=1; i<=a ; i++)
#define fo(i,n,m) for(int i=n; i<=m ; i++)
typedef long long ll;
using namespace std;

/*---------------------------------------------------------------------*/
ll MOD= 1e9 +7;

int setBit(int num, int idx, int value=1){return (value) ? (num|(1<<idx)) : (num&~(1<<idx));}
int getBit(int num, int idx){ return ((num>>idx) & 1)==1;}
int cntBits(int num){int ret=0; while(num){if(num%2) ret++; num/=2;} return ret;}


int is_prime[1000001];
void Sieve(){
	for(int i=0;i<=1000000;i++){
		is_prime[i]=1;
	}
	is_prime[0]=0;
	is_prime[1]=0;
	for(int i=2;i*i<=1000000;i++){
		if(is_prime[i]){
			for(int j=i*i;j<=1000000;j+=i){
				is_prime[j]=0;
			}
		}
	}
}

vector<int> get_bin(int n){
    vector<int> ret;
    while(n>0){
        if(n%2==0) ret.push_back(0);
        else ret.push_back(1);
        n/=2;
    }
    return ret;
}
unordered_map<long long, long long> factorise(long long n){
	unordered_map<long long , long long > map;
	if(n%2==0){
		while(n%2==0){
			if(map.find(2)!=map.end()) map[2]++;
			else map[2]=1;
			n=n/2;
		}
	}
	for(long long i=3;i*i<=n;i+=2){
		if(n%i==0){
			while(n%i==0){
				if(map.find(i)!=map.end()) map[i]++;
				else map[i]=1;
				n=n/i;
			}
		}
	}
	if(n>1) map[n]=1;
	return map;
}
unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
/*-------------------------------------------------------------*/

int main(){
    // a is 97 '0' is 48 'A' is 65 
    int t;
    t=1;
    //cin>> t;
    while(t--){
		int k;
		cin>> k;
		int vert = 3;
		while(true){
			int cycs = ((vert)*(vert-1)*(vert-2))/6;
			if(cycs>k){
				vert--;
				break;
			}
			else vert++;
		}
		int x = ((vert)*(vert-1)*(vert-2))/6;
		//cout<< x << endl;
		if(x==k){
			cout<< vert << endl;
			rep(i,vert){
				rep(j,vert){
					if(i==j) cout<< 0;
					else cout<< 1;
				}
				cout<< "\n";
			}
		}
		else{
			int ans[101][101];
			memset(ans,0,sizeof(ans));
			rep1(i,vert){
				rep1(j,vert){
					if(i==j) continue;
					else ans[i][j]=1;
				}
			}
			int lft = k-x;
			while(lft>0){
				vert++;
				rep(i,vert-1){
					if((i)<=lft){
						lft-= i;
						ans[i+1][vert]=1,ans[vert][i+1]=1;
					}
					else break;
				}
			}
			cout<< vert << endl;
			rep1(i,vert){
				rep1(j,vert){
					cout<< ans[i][j];
				}
				cout<< "\n";
			}
		}


    }
    return 0;
}