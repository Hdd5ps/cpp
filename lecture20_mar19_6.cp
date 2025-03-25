#include<iostream>
using namespace std;

//just because we're dealing with a multi-dimensional array doesn't mean the rules change
//when it comes to pass-by-value v. pass-by-reference
//function definition of print for a 2D array:
void print(const int array[][3], int rows){
//you must define each dimension except the first when writing a function to operate on arrays
   for(int i = 0; i<rows; i++){
      for(int j = 0; j<rows; j++){
      //when no value is stored in the array, such as for the first row:
         
         //if not enough characters (as with the first row), the compiler says it's a null value (nothing)
         
         cout<<array[i][j]<<" ";
         
         
         
      }
      cout<<endl;
      
   }
}

//the best way to ensure all integer cells are set to zero?

void init(int array[][3], int rows){
//reminder: const left off because we do want to change the contents of the array
   for(int i = 0; i<rows; i++){ //fortunately in this instance, # rows matches the # of columns
      for(int j = 0; j<rows; j++){
         array[i][j] = 0;
      }
   }

}



int main(){
   const int ROWS=3, COLS=3;
   //declaring too few values is still okay in C++
   //declaring too many values still leads to a compilation error
   //char charArray[ROWS][COLS] = {{'1', '2'}, {'0', '0', '0'}, {'j', 'k', 'l'}};
   //int intArray[ROWS][COLS] = {0}; - now everything is considered null.
   //int intArray[ROWS][COLS] = {{0}}; - still considered null
   //You can declare the values as a single list in {}, if you would prefer, like the above
   //statement.  The 2D array would fill itself in, automatically, row-by-row.
//need two loops
//-outer loop - control the row #
//-inner loop - control the col #
   int intArray[ROWS][COLS];
   init(intArray, ROWS);
   print(intArray, ROWS);      
   

}