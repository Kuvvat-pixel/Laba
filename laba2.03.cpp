#include <iostream>
using namespace std;
int main(){
double b1,n,q,S;
cout<<"Введите первый член прогрессии (b1)";
cin>>b1;
cout<<"Введите ваш номер в журнале(n):";
cin>>n;
q = 1.0/(n + 1);
if (q >= 1){
    cout<<"Прогрессия не является убывающей."<<endl;
}else{
    S = b1 / (1 - q);
    cout<<"Сумма убывающей геометрической прогрессии:"<<S<<endl;
}
return 0;
}
                                   