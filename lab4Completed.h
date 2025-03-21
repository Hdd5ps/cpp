#include<iostream>
using namespace std;

#ifndef LAB4_H
#define LAB4_H
/*

Names:
Kamal Raj Timilsena
Steven Tyndall
Piyachote Naphapayarksiri
Fal Elgizouli


It's getting close to the end of the semester, and you're looking to 
determine grades for one of your classes.  The class in question has the 
following grade components:

Assignments - 20%
Labs - 15%
Quizzes - 15%
Exams - 30%
Final Exam - 20%

Determine what your current course average is via a series of inputs.  
Each input represents the average of one of the four categories, aside 
from the final exam.

After figuring out your current grade, determine what the final exam 
score needs to be to achieve:

an A (89.5)
a B (79.5)
a C (69.5)
a D (59.5)
*/


//the enumerated type will help in grade calculations
//five grade types, according to the above description
enum gradeComponent{ASSIGNMENTS, LABS, QUIZZES, EXAMS, FINAL_EXAM};

/*
Write the following function definitions.
Comments describe actions that need to be done, or functions that
need to be called.
This does not include any variable declarations that you may
need to make as you write these functions.
*/

void average(double& pointsEarned){
   int count = 0;
   double Total = 0;
   double userInput = 0;
   
   while (userInput != -1) {
       cout<<"Enter a grade (or -1 to stop): ";
       cin>>userInput;
       if(userInput != -1) {
           count++;
           Total += userInput;
       }
   }
      cout<<endl;
       
   if (count == 0) {
       pointsEarned = 0; // Prevent division by zero if no scores are entered
      return;
   }

   pointsEarned = Total / count;
}

/*

Let's assume the use of a sentinel-controlled loop.

We don't know how many values will be input, but we do know
(and need to let the user know) that the sentinel value
to terminate the loop is -1.

This function returns the average of the scores entered via
reference parameter.

You also need to handle the situation that -1 is entered at
the start.  In this case, the average returned would need to be 0.

*/

void getWeight(gradeComponent g, double& weight){
   switch(g){
      case ASSIGNMENTS:
         weight = .2;
         break;
      case LABS:
         weight = .15;
         break;
      case QUIZZES:
         weight = .15;
         break;
      case EXAMS:
         weight = .30;
         break;
      default:
         weight = .20;
         break;
   }
}
/*

get the appropriate weight when the grade component is passed in.

remember the above:
exams are worth 30%
the final exam is worth 20%
labs are worth 15%
quizzes are worth 15%
assignments are worth 20%

the function must return the corresponding weight that comes in
via the argument using a reference parameter

*/

void printComponent(gradeComponent g){

   switch(g){
      case ASSIGNMENTS:
         cout<<"Assignments"<<endl;
         break;

      case LABS:
         cout<<"Labs"<<endl;
         break;

      case QUIZZES:
         cout<<"Quizzes"<<endl;
         break;

      case EXAMS:
         cout<<"Exams"<<endl;
         break;

      default:
         cout<<"Final Exam"<<endl;
         break;
   }
}

/*
given a gradeComponent argument, print out the appropriate label

for exams, print Exams
for final exam, print Final Exam
for assignments, print Assignments
for labs, print Labs
for quizzes, print Quizzes

*/
      


void targetScore(gradeComponent g, double targetFinalGrade, double averageGrade, double& pointsearned)
{
   double weightscore;
   getWeight(g, weightscore);
   
   pointsearned = (targetFinalGrade - averageGrade) / weightscore;
}
/*

The function targetScore has three arguments:
-a gradeComponent
-a double representing the target final grade needed
-a double representing the total points earned

the function calculates as follows:
targetScore = (target final grade - total points) / the weight of the grade component
the above should be returned as a reference parameter.

*/

void printAverage(double score, gradeComponent g){
   double weight;
   getWeight(g, weight);
   double currentAverage = score / (1 - weight);
   cout<<"Current Average: "<< currentAverage <<endl;
   cout<<endl;
}   
/* 

printAverage takes two arguments, a double representing a score,
and a gradeComponent.

prints out current average

the current average is determined by taking score and dividing
by 1 - gradeComponent's weight

*/

void inspectAndPrint(double current_grade){
   if (current_grade < 0){
      cout<<"The score has already been attained"<<endl; //ation: Check if the grade is less than 0 (cant have a negative total grade
   }
   else if (current_grade > 100){
      cout<<"The score cannot be attained"<<endl;
   } else {
      cout<<"The score is achievable"<<endl;
   }
}
/*

looks at the double that's passed in that represents what score
someone would need to make.

if the score is less than zero, the function prints out that the
score has already been attained.

if the score is more than 100, the function prints out that the
score cannot be attained.

*/

//calculates current course average
void calculateCurrentGrade(double &averageGrade){
   double pointsEarned, weight;
   averageGrade = 0;
   //average grade is the sum of each category type multiplied by
   //the weight of the category type
   for(int i = 0; i<(int)FINAL_EXAM; i++){
   //using the enumerated value of FINAL_EXAM as the upper bound.
   //cast the final exam's value as an int to make the loop condition
   //possible
      printComponent((gradeComponent)i);
      //go the other way now; take i and cast it as a gradeComponent
      //to be able to print the enumerated type
      average(pointsEarned);
      //call average, which will prompt for scores and returns
      //the average of those scores
      getWeight((gradeComponent)i, weight);
      averageGrade += pointsEarned * weight;
      //average grade is the sum of each category's average multiplied
      //by each category's weight
   }
   //the average grade earned thus far is returned via reference
   //parameter.
 
}

void printNeededScores(double averageGrade){
   string target = "";
   double targetFinalGrade;
   
   for (int j = 0; j < 4; j++){ // 0, 1 , 2, 3
      switch (j){
         case 0:
         targetFinalGrade = 89.5;
         target = "A";
         break;
         
         case 1:
         targetFinalGrade = 79.5;
         target = "B";
            break;
            
         case 2:
            targetFinalGrade = 69.5;
            target = "C";
            break;
            
         default:
            targetFinalGrade = 59.5;
            target = "D";
            break;
      }

      //needed grades
   
      double TargetScoreNeeded;
      targetScore(FINAL_EXAM, targetFinalGrade, averageGrade, TargetScoreNeeded);

      cout << "Score on Final Exam Needed for an " << target << ": " << TargetScoreNeeded << endl;
   
      inspectAndPrint(TargetScoreNeeded);
   }
}

/*
print scores takes in a double representing points earned so far.

it prints out the scores needed to make an A, B, C, and D.

reminder: A is 89.5, B is 79.5, C is 69.5, and D is 59.5

it calls targetScore to determine the grade needed on the final
to earn the decimal value for each grade. This score is then
printed to the screen for the user.

The score is then sent to the function that checks to see if it
has already been attained or is impossible to attain. 

Note: a loop is probably your best bet, since you'll be doing a 
good bit of repetition

*/

      
#endif
