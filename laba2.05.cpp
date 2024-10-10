#include <iostream>
using namespace std;
 int main(){
    double x,y;
    cout<<"Введите значение x и y";
    cin>>x>>y;
    double max = (x > y)? x : y;
      /*double max;
      if (x > y) {
      max = x;
       }else{
        max = y;
      }*/
    cout<<"Максимальное значение:"<<max<<endl;
    return 0;
 }