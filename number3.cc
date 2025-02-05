/*
Read from numbers.txt
If the number is even, print the number to evens.txt ( 1 per line)
If the number is odd, print the number to odds.txt ( 1 per line)
*/
#include<iostream> //cin, cout, endl
#include<fstream> //file I/O
using namespace std;

int main(){

    //declaring ifstream, ofstream variables:

    ifstream numbersFile; //file to read
    ofstream oddsFile, evensFile; // file to write

    // variables to read from the file
    int fileInput;

    // stating which files go with which variable

    numbersFile.open("numbers.txt"); //this file must exist
    oddsFile.open("odds.txt");
    evensFile.open("evens.txt");

    // read until failure
    // sentinel-controlled loop (eof means end of file)
    numbersFile>>fileInput; // potentially the file could be blank....
    
    while(!numbersFile.eof()){// while we're not at the end of the input
        if (fileInput % 2 == 0){
            evensFile<<fileInput<<endl;
        }
        else{
            oddsFile<<fileInput<<endl;
        }

        //update statement:
        numbersFile>>fileInput; // update by reading from the file.
    }

    numbersFile.close();
    evensFile.close();
    oddsFile.close();

    cout<<"Program completed."<<endl;
    return 0;

}