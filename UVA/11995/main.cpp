


#include <bits/stdc++.h>
 
typedef unsigned long long ull;
typedef long long ll;
 
#define all(x) x.begin(),x.end()
#define pi (3.14159265)


using namespace std;

int equal(vector<int>&v1,vector<int>&v2){
    if(v1.size() != v2.size()){
        return 0;
    }
    for(int i = 0;i<v1.size();i++){
        if(v1[i] != v2[i]){
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
    

    int n;
    while(cin >> n){
        stack<int>st;
        queue<int>q;
        priority_queue<int>pq;
        vector<int>st_res,q_res,pq_res,res;
        while(n--){
            int op,val;
            cin >> op >> val;
            if(op == 1){
                st.push(val);
                q.push(val);
                pq.push(val);
            }
            else{
                if(st.empty()){
                    st_res.clear();
                }
                else{
                    st_res.push_back(st.top());
                    st.pop();
                }


                if(q.empty()){
                    q_res.clear();
                }
                else{
                    q_res.push_back(q.front());
                    q.pop();
                }

                if(pq.empty()){
                    pq_res.clear();
                }
                else{
                    pq_res.push_back(pq.top());
                    pq.pop();
                }


                res.push_back(val);
            }
        }


        int stk = equal(res,st_res);
        int qu = equal(res,q_res);
        int pqu = equal(res,pq_res);

        if(stk + qu + pqu == 0){
            cout << "impossible\n";
        }
        else if(stk + qu + pqu  > 1){
            cout << "not sure\n";
        }
        else if(stk){
            cout << "stack\n";
        }
        else if(qu){
            cout << "queue\n";
        }
        else {
            cout << "priority queue\n";
        }
    }

}

