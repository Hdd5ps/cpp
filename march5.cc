/*
CSC 1180 - 3/5/25
-Assignment due tonight
-Exam 2 tomorrow


Quiz Feedback?
- I'll look into it
question from previous tests ?

static - memory set aside when program starts
       - persists/ lasts until program ends

.h files & 2 routes ends of writing functions
    - write in a similar fashion as if in a .cc file with main no main in a .h file, make sure that file
      using the .h file is include #include

function templates
    - function(s) that have same no. of arguments, same name, and same logic
    - format:
        template<class T>
        T functionThing<T arg1, T arg2, T arg3>
    }

    in another function:
    char charResult = functionThing(a, b, c);
    int intResult = functionThing(l, m, n);
    double doubleResutl = functionThing(x, y, z);

    compiler creates a version of the function on the fly that will match the function call

    references
        int value = 1; 
        int &valueRef = &value; -> declaring a reference -> must be assigned immediately & referes to the memory address operator

        valueRef = &value2 -> compilation error

        can't change what you're referring to, but you can change its value

        ValueRef = 1 * 3 * 5 * 7

    skip white space when reading from a file
    while(!inFile.eof())=> reach the end of the file
    while(inFile>>x) => go until read fails

    ifstream inFile;
    inFile.open("data.txt");

iomanip

set precision -> no. of decimal places
setw -> how much space btween values you want

decimal:
cout<<fixed; -> sticky setting -> will last until you change it
cout<<setw(10); aren't sticky settings
cout<<setprecision(4); // calling them before you print
cout<<doubleValue<<endl;

cout<<left; // stuff printed from left
3.1415
----------
      4 space

setprecision(12)
setw(9)

fixed - print in decimal form 
scientific (default one) i.e. 1.23x10pow3
*/
