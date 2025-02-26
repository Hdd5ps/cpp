#include<iostream>
using namespace std;

//parameter passing
 //pass-by-reference; tip-off: &
 //value1 and value2 get the addresses for decimal1 and decimal2
 //access to change what's in value1 and value2
 
void swap(double& value1, double& value2){
   double temp;
   cout<<"value1: "<< value1<<" value2: "<<value2<<endl;
   temp = value1;
   value1 = value2;
   value2 = temp;
   cout<<"value1: "<< value1<<" value2: "<<value2<<endl<<endl;

   return;
}

double swapAndMax(double& value1, double& value2){
   double temp, result;
   temp = value1;
   value1 = value2;
   value2 = temp;
   if(value1 > value2){
      result = value1;
   }
   else{
      result = value2;
   }

   return result;
}

int main(){
   double decimal1 = 9.5, decimal2 = -1.5;
   double result = swapAndMax(decimal1, decimal2);
   cout<<"decimal1: "<<decimal1<<" decimal2: "<<decimal2<<endl;
   cout<<"larger value: "<<result<<endl;
   return 0;
}

