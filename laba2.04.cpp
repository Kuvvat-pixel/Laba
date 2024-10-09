#include <iostream>
using namespace std;
int main(){
    int x,y;
    double A,B,C,K;
    cout<<"Введите значение x и y:";
    cin>>x>>y;
    cout<<"Введите значение A,B,C,K:";
    if(x < y){
    x = 0;
    } else if (y < x){
    y = 0;
    }else{
    x = 0;
    y = 0;
}
if(A > B && A > C) {
    A -= K;
} else if (B > A && B > C){
B -=K;
}else{
    C -= K;    
}
cout<<"Результат"<<endl;
cout<<"x"<<endl;
cout<<"y"<<endl;
cout<<"A"<<endl;
cout<<"B"<<endl;
cout<<"C"<<endl;
cout<<"K"<<endl;
return 0;
}