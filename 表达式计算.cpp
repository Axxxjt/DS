#include <stdio.h>
#include <malloc.h>
char *OP="+-*/()#";
typedef struct DSNode{
	double data;
	struct DSNode *next;
} DSNode;
typedef struct CSNode{
	char data;
	struct CSNode *next;
} CSNode;
int In(char c,char *a){
	int i;
	for(i=0;a[i]!='\0';i++)
		if(c==a[i]) break ;
	return a[i]!='\0';
}
void initStack(DSNode * &s){
	s=(DSNode *)malloc(sizeof(DSNode));
	s->next=NULL;
}
void initStack(CSNode * &s){
	s=(CSNode *)malloc(sizeof(CSNode));
	s->next=NULL;
}

int StackEmpty(DSNode *s){
	return s->next==NULL;
}
int StackEmpty(CSNode *s){
	return s->next==NULL;
}
void push(DSNode *s,double x){
	DSNode *q;
	q=(DSNode *)malloc(sizeof(DSNode));
	q->data=x;
	q->next=s->next;
	s->next=q;
}

void push(CSNode *s,char ch){
	CSNode *q;
	q=(CSNode *)malloc(sizeof(CSNode));
	q->data=ch;
	q->next=s->next;
	s->next=q;
}
double pop(DSNode *s){
	DSNode *q;
	double x;
	q=s->next;
	s->next=q->next;
	x=q->data;free(q);
	return x;
}
char pop(CSNode *s){
	CSNode *q;
	char ch;
	q=s->next;
	s->next=q->next;
	ch=q->data;free(q);
	return ch;
}
double top(DSNode *s){
	DSNode *q;
	double x;
	q=s->next;
	x=q->data;
	return x;
}
char top(CSNode *s){
	CSNode *q;
	char ch;
	q=s->next;
	ch=q->data;
	return ch;
}
char Precede(char ch1,char ch2){
	char c;
	if(ch1=='+'||ch1=='-')
		if(ch2=='+'||ch2=='-'||ch2==')'||ch2=='#')
			c='>';
		else 
			c='<';
	if(ch1=='*'||ch1=='/')
		if(ch2=='(')
			c='<';
		else
			c='>';
	if(ch1=='(')
		if(ch2!=')'&&ch2!='#')
			c='<';
		else if(ch2=')')
			c='=';
	if(ch1==')'&&ch2!='(') 
		c='>';
	if(ch1=='#')
		if(ch2=='#')
			c='=';
		else  if(ch2!=')')
			c='<';
	return c;
}
double operate(double a,char op,double b){
	switch(op){
	case '+':return a+b;
	case '-':return a-b;
	case '*':return a*b;
	case '/':return a/b;
	}
}
double EvaExp(char *s){
	int i;  char c,theta;
	double a,b;
	CSNode *OPTR;
	DSNode *OPND;
	initStack(OPTR);
	initStack(OPND);
	push(OPTR,'#');
	c=s[0];	i=1;
	while(c!='#'||top(OPTR)!='#'){
		if(!In(c,OP)){
			push(OPND,c-'0');c=s[i++];
		}
		else
			switch(Precede(top(OPTR),c)){
				case '<':
					push(OPTR,c);c=s[i++];break;
				case '=':
					pop(OPTR);c=s[i++];break;
				case '>':
					theta=pop(OPTR);
					b=pop(OPND);a=pop(OPND);
					push(OPND,operate(a,theta,b));
					break;
			}
	}
	return pop(OPND);
}
void main(){
	char s[100]="3*(1+2*(2+1))-9#";
	//gets(s);
	double x;
	x=EvaExp(s);
	printf("%f\n",x);
}