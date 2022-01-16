#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100010;
int bestside[N];
int T,n,m,ans,i,j,q[N];
int pre[N],nxt[N];
char a[N];
int w[N],cnt;
int now[N],tmp;
inline bool cmp(int x,int y){return x>y;}
inline int cal(int l,int r){
    int dis=r-l-1;
    if(l==0||r==n+1)return dis;
    return (dis+1)/2;
}
inline int calleft(int mark){
    for(int i=2;i<=m;i++)if(mark!=q[i])return q[i]-1;
}
inline int calright(int mark){
    for(int i=m-1;i;i--)if(mark!=q[i])return n-q[i];
}
inline void gao(int l,int r){
    if(l==0||r==n+1)return;
    w[++cnt]=r-l-1;
}
inline void del(int l,int r){
    if(l==0||r==n+1)return;
    int dis=r-l-1;
    int i;
    for(i=1;i<=tmp;i++)if(now[i]==dis)break;
    if(i>tmp)return;
    for(;i<tmp;i++)now[i]=now[i+1];
    tmp--;
}
inline void add(int l,int r){
    if(l==0||r==n+1)return;
    int dis=r-l-1;
    int i;
    now[++tmp]=dis;
    sort(now+1,now+tmp+1,cmp);
    if(tmp>4)tmp--;
}
inline void work(int x){
    int i=pre[x],j=nxt[x];//i x j
    tmp=cnt;
    for(int _=1;_<=cnt;_++)now[_]=w[_];
    del(i,x);
    del(x,j);
    add(i,j);
    int left=calleft(x),right=calright(x);
    int maxgap=0,secgap=0;
    if(tmp>=1)maxgap=now[1];
    if(tmp>=2)secgap=now[2];
    //case 1 add one in left
    ans=min(ans,max(bestside[left],max(right,(maxgap+1)/2)));
    //case 2 add one in right
    ans=min(ans,max(left,max(bestside[right],(maxgap+1)/2)));
    //case 3 add one in maxgap
    ans=min(ans,max(max(left,right),max((maxgap/2+1)/2,(secgap+1)/2)));
}
int main(){
    
    #ifdef STRESS_TEST
        freopen("test.txt","r",stdin);
        freopen("ac.txt","w",stdout);
    #endif
     
        freopen("stations.in","r",stdin);
    for(i=j=1;i<N;i++){
        while(j<i&&max(j-1,(i-j+1)/2)>max(j,(i-(j+1)+1)/2))j++;
        bestside[i]=max(j-1,(i-j+1)/2);
        //i=3 |___+
    }
     
     
    scanf("%d",&T);
    while(T--){
        scanf("%d%s",&n,a+1);
        ans=n;
        q[m=1]=0;
        for(i=1;i<=n;i++)if(a[i]=='+')q[++m]=i;
        q[++m]=n+1;
         
        if(m==3){
            for(i=1;i<=n;i++)ans=min(ans,max(cal(0,i),cal(i,n+1)));
            printf("%d\n",ans);
            continue;
        }
         
         
        pre[0]=0;
        nxt[n+1]=0;
        for(i=1;i<=m;i++){
            if(i>1)pre[q[i]]=q[i-1];
            if(i<m)nxt[q[i]]=q[i+1];
        }
        cnt=0;
        for(i=1;i<m;i++)gao(q[i],q[i+1]);
        sort(w+1,w+cnt+1,cmp);
        cnt=min(cnt,4);
        for(i=2;i<m;i++)work(q[i]);
        printf("%d\n",ans);
    }
}