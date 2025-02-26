#include<iostream>
using namespace std;

//parameter passing
//pass-by-value
//whatever gets passed in for value1 and value2 - a copy of each
//value is passed in
//tip-off:  there are no ampersands (&) in the arguments
void swap(double value1, double value2){
   double temp;
   cout<<"value1: "<< value1<<" value2: "<<value2<<endl;
   temp = value1;
   value1 = value2;
   value2 = temp;
   cout<<"value1: "<< value1<<" value2: "<<value2<<endl<<endl;

   return;
}

int main(){
   double decimal1 = 9.5, decimal2 = -1.5;
   swap(decimal1, decimal2);
   cout<<"decimal1: "<<decimal1<<" decimal2: "<<decimal2<<endl;

   return 0;
}

