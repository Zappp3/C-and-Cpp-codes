#include <iostream>
#include<string.h>
using namespace std;
template<typename A>
A add (A a, A b){
    return a+b;
}
template<typename A>
class complex{
    A real,img;       
public:
    complex(int r, int i){
        real=r;
        img=i;
    }
    void getcomplex(){
        cout<<"complex no is:"<<real<<"+"<<img<<"i"<<endl;
    }
    complex operator+(complex &a){
        complex c(0,0);
        c.real=real+a.real;
        c.img=img+a.img;
        return c;
    }    
}; 
int main(){
    int i=10;
    int j=20;
    int s=add(i,j);
    cout<<"add (i,j)"<<s<<endl;
    double f1=10.12;
    double f2=20.21;
    double f3=add(f1,f2);
    cout<<"add (f1,f1)"<<f3<<endl;
    complex<int> c1(2,3),c2(6,7),c3(0,0);
    c3=add(c1,c2);
    cout<<"add (c1,c2)";
    c3.getcomplex();
    return 0;
}