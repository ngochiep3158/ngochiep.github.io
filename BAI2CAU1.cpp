#include <iostream>
using namespace std;
//void nhap mang
//void xuat mang 
void nhapmang(int* a,int& n){
	cout<<"nhap so phan tu n: ";
	cin>>n;
	a = new int[n];
	cout<<"nhap mang:\n";
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]=";
		cin>>*(a+i); 
	} 
 }
void xuatmang(int* a,int n){
	cout<<"mang:\n":
	for(int i=0;i<n;i++){
		cout<<*(a+i)<<//
	}
}
int main (){
	int n;
	int* a;
	nhapmang(a, n);
	//xuatmang(a, n);
	delete[]a; 
	 
	return 0;
}

