/*
	Created By : Khaled Hegazy
*/


#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define fast cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
#define ll long long 

using namespace std;

extern struct node * EMPTY;





typedef int vtype;
enum Dir{LF,RT};

mt19937 eng{std::random_device{}()};
//mt19937 eng(0);
uniform_int_distribution<int> uid(0,1e9);


struct node{
	vtype v;
	int pr,sz,frq;
	node * ch[2];
	node * par;
	
	node(){
		sz = frq = 0;
		par = ch[LF] = ch[RT] = this;	
		pr = INT_MIN;
	}

	node(vtype val){
		v = val;
		sz = frq = 1;
		par = ch[LF] = ch[RT] = EMPTY;
		pr = uid(eng); 
	}

};


node *EMPTY = new node(); 



void pushUp(node *cur){
	cur->sz = cur->frq + cur->ch[LF]->sz + cur->ch[RT]->sz;
}



void link(node *pr,node *child,Dir d){
	if(pr != EMPTY){
		pr->ch[d] = child;
		pushUp(pr);
	}
	if(child != EMPTY){
		child->par = pr;
	}
}


Dir getDir(node *pr,node *child){
	return (Dir) (pr->ch[RT] == child);
}

void rotate(node *&p,Dir d){
	node *pp = p->par;
	node *q = p->ch[!d];
	link(p,q->ch[d],(Dir)!d);
	link(q,p,d);
	link(pp,q,getDir(pp,p));
	p = q;
}

void balance(node *&root){
	if(root->pr < root->ch[LF]->pr){
		rotate(root,RT);
	}
	if(root->pr < root->ch[RT]->pr){
		rotate(root,LF);
	}
}



void insert(node *&root,vtype val){
	if(root == EMPTY){
		root = new node(val);

	} 
	else if(root->v == val) root->frq++;
	else if(root->v > val) insert(root->ch[LF],val);
	else if(root->v < val) insert(root->ch[RT],val);

	pushUp(root);
	balance(root);
}





node * rem_node(node *cur){
	
	auto tmp = cur;
	for(int i = 0;i<2;i++){
		if(cur->ch[i] == EMPTY){
			link(cur->par,cur->ch[!i],getDir(cur->par,cur));
			cur = cur->ch[!i];
			delete tmp;
			return cur;
		}
	}
	if(cur->ch[LF]-> pr > cur->ch[RT]->pr){
		rotate(cur,RT);
		cur->ch[RT] = rem_node(cur->ch[RT]);
	}
	else{
		rotate(cur,LF);
		cur->ch[LF] = rem_node(cur->ch[LF]);
	}

	return cur;

}

// void rem_node(node *&cur){
	
// 	auto tmp = cur;
// 	for(int i = 0;i<2;i++){
// 		if(cur->ch[i] == EMPTY){
// 			rotate(cur,(Dir)i);
// 			link(cur,EMPTY,(Dir)i);
// 			delete tmp;
// 			return;
// 		}
// 	}
// 	if(cur->ch[LF]-> pr > cur->ch[RT]->pr){
// 		rotate(cur,RT);
// 	}
// 	else{
// 		rotate(cur,LF);
// 	}
// 	rem_node(tmp);

// }



void del(node *&root,vtype val){
	if(root == EMPTY) return;
	if(root->v == val){
		if(!--root->frq){
			root = rem_node(root);
		}
	}
	else if(val < root->v){
		del(root->ch[LF],val);
	}
	else {
		del(root->ch[RT],val);
	}


	pushUp(root);

}


void print(node* root,int dp = 0){
	if(root == EMPTY ) return;

	print(root->ch[LF],dp + 1);
	//printf("%s(%d,%d)\n",string(3*dp , ' ').c_str(),root->v,root->sz);
	printf("%s%d\n",string(3*dp , ' ').c_str(),root->v);
	print(root->ch[RT],dp + 1);
}


vtype getByIdx(node *root,int idx){
	if(root == EMPTY) return INT_MIN;


	if(idx < root->ch[LF]->sz) return getByIdx(root->ch[LF],idx);
	int tmp = root->ch[LF]->sz + root->frq;
	if(tmp > idx) return root->v;

	return getByIdx(root->ch[RT],idx - tmp);
}

int lower_bound(node *root,int x){
	if(root == EMPTY) return 0;
	if(root->v == x) return root->ch[LF]->sz;
	if(root->v > x) return lower_bound(root->ch[LF],x);
	return root->frq + root->ch[LF]->sz + lower_bound(root->ch[RT],x);
}






int main(void){

	fast;

	#ifdef Khaled
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	node *root = EMPTY;

	int q;
	cin >> q;
	while(q--){
		char op;
		int x;
		cin >> op >> x;
		switch (op)
		{
		case 'I':{

			int tmp = lower_bound(root,x);
			if(getByIdx(root,tmp) != x)
				insert(root,x);
			break;
		}
		case 'D':
		{

			int tmp = lower_bound(root,x);
			if(getByIdx(root,tmp) == x)
				del(root,x);
			break;
		}
		case 'C':
				cout << lower_bound(root,x) << endl;
			break;
		case 'K':
			if(root->sz < x){
				cout << "invalid\n";
			}
			else{
				cout << getByIdx(root,--x) << endl;
			}
			break;
		
		}


	}






}



