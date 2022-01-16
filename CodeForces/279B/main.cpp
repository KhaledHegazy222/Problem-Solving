#include<iostream>
#include<bits/stdc++.h>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
using namespace std;
#define fast cin.tie(0);cin.sync_with_stdio(0);
#define ll long long
#define llu unsigned long long
#define PB push_back
#define sumall n(n+1)/2
#define sumatop n(a+p)/2
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
map <ll, ll> mp;
map <ll, ll>::iterator it;
ll a[100010];
int main()
{
fast;
ll n,t,sum=0,mx=0,j=-1;
while(cin>>n>>t)
{
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(sum+a[i]<=t)
            sum+=a[i];
        else
        {
            sum+=a[i];
            while(sum>t)
            {
                j++;
                sum-=a[j];
            }
        }
        mx=max(mx,i-j);
    }
    cout<<mx<<endl;
}
return 0;
}