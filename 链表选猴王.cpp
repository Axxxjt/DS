#include <iostream.h>
#include <malloc.h>
typedef struct LNode{
	int num;
	struct LNode *next;
} LNode,*LinkList;
void printLinkRing(LinkList h){
//此函数从h结点开始打印无头结点的的单链循环表全部元素
	LinkList q;
	q=h;
	if(!q) return;
    cout<<q->num<<' ';
	while(q->next!=h){
		q=q->next;
	    cout<<q->num<<' ';
	}
    cout<<endl;
}
LinkList monkeyKing(int n,int k,int m){
	LinkList p,q,r,h;
	int i;
	h=r=(LinkList)malloc(sizeof(LNode));
	h->num=1;
	h->next=NULL;
	for(i=2;i<=n;i++){
       p=(LinkList)malloc(sizeof(LNode));
	   p->num=i;
	   r->next=p;
	   r=p;
	}
	r->next=h;
	p=h;q=r;
	for(i=1;i<k;i++){
		q=p;p=p->next;
	}
//	q=p;
	printLinkRing(p);
	while(n>1){
		i=1;
		while(i<m){
			q=p;p=p->next;i++;
		}
		r=p;p=p->next;q->next=p;free(r);
		n--;
		printLinkRing(p);
	}
	return p;
}
int main(){
	int n,k,m;
	LinkList p;
	cin>>n>>k>>m;
	p=monkeyKing(n,k,m);
	cout<<p->num<<endl;
	return 0;
}