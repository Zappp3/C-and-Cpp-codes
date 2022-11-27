#include<iostream>
using namespace std;
int main(){
    int d=0,xaxis=0,yaxis=0;
    char direction='F';
    for(int i=0;i<10;i++){
        if(direction=='F'){
            d=d+5;
            xaxis=xaxis+d;
            direction='U';
            cout<<i+1<<"("<<xaxis<<","<<yaxis<<")"<<endl;
        }
        else if(direction=='U'){
            d=d+5;
            yaxis=yaxis+d;
            direction='L';
            cout<<i+1<<"("<<xaxis<<","<<yaxis<<")"<<endl;
        }
        else if(direction=='L'){
            d=d+5;
            xaxis=xaxis-d;
            direction='D';
            cout<<i+1<<"("<<xaxis<<","<<yaxis<<")"<<endl;
        }
        else if(direction=='D'){
            d=d+5;
            xaxis=xaxis-d;
            direction='F';
            cout<<i+1<<"("<<xaxis<<","<<yaxis<<")"<<endl;
        }


    }
    return 0;
}