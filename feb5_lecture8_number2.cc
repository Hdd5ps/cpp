/*
Create a program that prints out the numbers 1-100, one per line,
in a file called numbers.txt.
*/

#include<iostream> //any possible cin, cout
#include<fstream> //file I/O
using namespace std;

int main(){

/*
how to write to a file:
1.  declare an ofstream variable
2.  open the file with the ofstream variable
2.1.  if the file doesn't exist, it'll be created
2.2.  if the file does exist, it'll be overwritten
3.  output to the file
4.  closing the file
*/

   ofstream numberOutput; //ofstream variable - step 1
   numberOutput.open("numbers.txt"); //step 2 - what file?
   //write 1-100 to the file:
   for(int value = 1; value <= 100; value++){
   
   //remember user output:  cout<<value<<endl;
      numberOutput<<value<<" "; //output to the file (step 3)
      if(value%5 == 0){
         numberOutput<<endl;
      }
   
   }
   
   numberOutput.close(); //step 4 - prevent data corruption
   
   cout<<"Program completed."<<endl;



   return 0;
}