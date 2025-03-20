/*
Tyler
Max
Kamal
*/
//.cc file given for lab 5

#include<iostream>
#include "lab5.h" //you'll need to come up with this...skeletal one given
using namespace std;

   
int main(){
   const int SIZE = 4; //a course's grade is made up of 4 components
   double gradeComponents[SIZE]; //declare an array of those four components
   double totalPointsEarned, totalWeight; 
   //totalPointsEarned and totalWeight will be needed later to determine current average
   double finalExam;
   
   //go through and get the grades for each type:
   for(int i = 0; i<SIZE; i++){
      gradePrompt(gradeComponents, (Grades)i);
   }
   
   //print out the averages for each of the four types of grades
   printGradeAverages(gradeComponents, SIZE);
   //figure out total points earned so far (sans the final)
   totalPointsEarned = pointsEarned(gradeComponents, SIZE, totalWeight);
   //print current course grade
   cout<<"Current course grade: "<<currentGrade(totalPointsEarned, totalWeight);
   cout<<endl<<endl;
   //let's say the prof is generous and 89.5 is an A, 79.5 is a B, etc.
   for(double cutoff = 89.5; cutoff>=59.5; cutoff-=10){
   //find out what the score would need to be
      finalExam = finalExamScore(cutoff, totalPointsEarned, totalWeight);
      cout<<"For a course average of "<<cutoff<<", the final exam score will";
      cout<<" need to be: "<<finalExam<<endl;
      //is it attainable?
      isScoreAttainable(finalExam);
      //has it already been attained?
      isScoreAssured(finalExam);
   
   }
   

}
