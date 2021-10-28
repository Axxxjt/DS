#include <stdio.h>
int GCD(int n,int m){
	//Õ·×ªÏà³ı·¨
	int r;
	if(n<m){
		r=n;n=m;m=r;
	}
	r=1;
	while(r>0){
		r=n%m;
		n=m;
		m=r;
	}
	return n;
}
int GCD1(int n,int m){
	int r;
	if(n<m){
		r=n;n=m;m=r;
	}
	r=m;
	while(n%r!=0||m%r!=0){
		r--;
	}
	return r;
}
int LCM(int n,int m){
	int r;
	if(n<m){
		r=n;n=m;m=r;
	}
	r=n;
	while(r%m!=0||r%n!=0){
		r++;
	}
	return r;
}

void main(){
	int m,n,t;
	scanf("%d%d",&n,&m);
	t=GCD1(n,m);
	printf("%d\n",t);
}