#include<iostream>
#include<fstream>
#include <stack>
#include <queue>
using namespace std;
int g[10][10], d[10],n;
/*void khoiTao() {
	for(int i = 1; i<=n; i++) d[i]=0;
}*/
/*struct stack {
	int a[101];
	int top;
};/*
void Create(stack &s) {
	s.top = 0;
}
void Empty(stack s) {
	return s.top = 0;
}
void Push(int x, stack &s) {
	s.top++;
	s.a[s.top]=x;
}
void Pop(stack &s) {
	s.top--;

}
void Top(stack s) {
	return s.a[s.top];
}*/
void khoiTao() {
	for(int i=1; i<=n; i++) d[i] = 0;
	}
void docFile(char ten[]) {
	ifstream in;
	in.open(ten);
	in>>n;
	for(int i = 1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			int x;
			in>>x;
			g[i][j]=x;
		}
}
void xuatMT() {
	for(int i = 1; i<=n; i++) {
		for(int j=1; j<=n; j++)
			cout<<g[i][j]<<" ";
		cout<<endl;
	}
}
/*void F(int a){
	d[a]=1; cout<<a<<" ";
	for(int u =n; u>=1;u--)
	//for(int u=1;u<=n;u++)
		if(g[a][u]!=0)
			if(d[u]==0)
				F[u];
}*/
void nn_Stack(int a){
	stack<int> s;
	s.push(a);
	while(!s.empty()){
		int u = s.top(); s.pop();
		if(d[u]==0){
			cout<<u<<" "; d[u]=1;
			for(int v=n; v>=1;v--)
				if(g[u][v]!=0)
					if(d[v]==0)
						s.push(v);
		}
	}
}
void nn_Stack1(int b){
	stack<int> s;
	s.push(b);
	while(!s.empty()){
		int u = s.top(); s.pop();
		if(d[u]==0){
			cout<<u<<" "; d[u]=1;
			for(int v=1; v<=n;v++)
				if(g[u][v]!=0)
					if(d[v]==0)
						s.push(v);
		}
	}
}
void chieuRong(int a){
	queue <int> q;
	q.push(a); d[a]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		cout<<u<<" ";
		for(int v=1; v<=n; v++)
			if(g[u][v]!=0)
				if(d[v]==0){
					d[v]=1;
					q.push(v);
				}
	}
}
void chieuRong1(int a){
	queue <int> q;
	q.push(a); d[a]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		cout<<u<<" ";
		for(int v=n; v>=1; v--)
			if(g[u][v]!=0)
				if(d[v]==0){
					d[v]=1;
					q.push(v);
				}
	}
}
int main(){
	int n = 8,c,d;
	docFile("/home/andy/Desktop/homework/MTH254N_T10_DOVUDUNG/stack.txt");
	xuatMT();
	int a;
	cout<<"nhap dinh bat dau: ";
	cin>>a;
	nn_Stack(a);
	khoiTao();
	int b;
	cout<<"\nnhap dinh bat dau: ";
	cin>>b;
	nn_Stack1(b);
	khoiTao();
	cout<< "\nnhap dinh "; cin>>c;
	chieuRong(c);
	khoiTao();
	cout<<"\nnhapdinh "; cin>>d;
	chieuRong1(d);
	
}
