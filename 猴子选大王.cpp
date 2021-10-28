#include<iostream.h>
#include<malloc.h>
void printArray1(int *a,int n,int p){
//从第r个元素开始环状打印a数组的n个元素
	int i;
	for(i=p;i<n+p;i++)
		cout<<' '<<a[i%n];
	cout<<endl;
}
int monkeyKing(int n,int k,int m){
	int *a;
	int r,p,i;
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		a[i]=i+1;
	printArray1(a,n,0);
	r=1; p=0;
	while(r<k){
       r++;
       p=(p+1)%n;
	}
	printArray1(a,n,p);
	while(n>1){
        r=1;
        while(r<m){
             r++; p=(p+1)%n;
         }
         for(i=p;i<n-1;i++)
              a[i]=a[i+1];
         n--;
		printArray1(a,n,p);
    }
  return a[0];
}
int main(){
	int n,k,m,king;
	cin>>n>>k>>m;
	king=monkeyKing(n,k,m);
	cout<<king<<endl;
	return 0;
}