/*
*
* Tag: SBT
* Time: Insertion: O(lgn); Deletion: O(lgn); GetKthElement: O(lgn)
* Space: O(n)
*/
#include <list>
#include <cmath>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int M=100005;
struct Node
{
	long long v;           //数据域
	int size;
	struct Node *l,*r;
}*root,tree[M];
int tot;             //总结点数
int n,m;
unordered_map<long long, int> dic;

void init()          //初始化SBT树
{
	tot=0;
   n = 0;
	root=NULL;
   for(int i = 0; i < M; ++ i)
       tree[i].l = tree[i].r = NULL;
}

int ls(Node *p)
{
	return p->l?p->l->size:0;
}

int rs(Node *p)
{
	return p->r?p->r->size:0;
}

void rotate_left(Node* &p)            //子树左旋
{
	Node *q=p->r;
	p->r=q->l;
	q->l=p;
	q->size=p->size;
	p->size=ls(p)+rs(p)+1;
	p=q;
}

void rotate_right(Node* &p)            //子树右旋
{
	Node *q=p->l;
	p->l=q->r;
	q->r=p;
	q->size=p->size;
	p->size=ls(p)+rs(p)+1;
	p=q;
}

void maintain(Node* &p,bool flag)                        //维持树的平衡函数
{
	if(flag)
	{
		if(p->r && p->r->r && p->r->r->size>ls(p)) rotate_left(p);
		else if(p->r && p->r->l && p->r->l->size>ls(p))
		{
			rotate_right(p->r);
			rotate_left(p);
		}
	}
	else
	{
		if(p->l && p->l->l && p->l->l->size>rs(p)) rotate_right(p);
		else if(p->l && p->l->r && p->l->r->size>rs(p))
		{
			rotate_left(p->l);
			rotate_right(p);
		}
	}
}

void insert(long long x,Node* &p)                   //插入结点函数
{
	if(!p)
	{
		p=&tree[tot++];
		p->l=NULL;
		p->r=NULL;
		p->size=1;
		p->v=x;
	}
	else
	{
		p->size++;
		if(p->v>x) insert(x,p->l);
		else insert(x,p->r);
		maintain(p,x>=p->v);
	}
}

long long getkth(long long k,Node* p)                         //寻找第k小的结点
{
	if(k<=0 || k>p->size) return 0;
	int lc=ls(p);
	if(k==lc+1) return p->v;
	else if(k<=lc) return getkth(k,p->l);
	else return getkth(k-1-lc,p->r);
}

void delet(long long x,Node* &p)                       //删除结点函数
{
   if(!p) return ;
	p->size--;
	if(x<p->v) delet(x,p->l);
	else if(x>p->v) delet(x,p->r);
	else
	{
		if(!p->l && !p->r) p=NULL;
		else if(!p->l) p=p->r;
		else if(!p->r) p=p->l;
		else
		{
			Node *q;
			q=p->r;
			while(q->l) q=q->l;
			p->v=q->v;
			delet(q->v,p->r);
		}
	}
}

int main(){
    init();
    n = 0;
    int T;
    scanf("%d",&T);
    while(T --){
        char op[10];
        long long val;
        scanf("%s%lld",op,&val);
//        printf("%s %lld\n",op,val);
        long long ans = 0;
        if(op[0] == 'r'){
            if(n == 0)
                puts("Wrong!");
            else{
                if(dic.find(val) == dic.end() || dic[val] == 0){
                    puts("Wrong!");
                    continue;
                }
                delet(val, root);
                -- dic[val];
                -- n;
                if(!n)
                    puts("Wrong!");
                else if(n%2)
                    printf("%lld\n",getkth((n + 1)/2, root));
                else{
                    ans = getkth(n/2, root) + getkth(n/2 + 1, root);
                    if(ans%2)
                        printf("%.1lf\n",(double)ans/2.0);
                    else
                        printf("%lld\n",ans/2);
                }
            }
        }else{
            insert(val, root);
            ++ n;
            if(dic.find(val) == dic.end())
                dic[val] = 1;
            else
                ++ dic[val];
            if(n%2){
                printf("%lld\n",getkth((n + 1)/2, root));
            }else{
                ans = getkth(n/2, root) + getkth(n/2 + 1, root);
                if(ans%2)
                    printf("%.1lf\n",(double)ans/2.0);
                else
                    printf("%lld\n",ans/2);
            }
        }
    }
    return 0;
}
