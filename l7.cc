#include<iostream>
#include "lab7.h"
using namespace std;
/*
This week's lab calls for the use of a struct called CourseGrade, which
has been defined for you in the lecture7.h file.
*/

   
int main(){
  //utilizing an instance of the struct
   CourseGrade student;
   //sum of weights - needed to total up all the weights as
   //grades are read in
   //total points earned += average of each grade type * weight
   double sumOfWeights = 0, totalPointsEarned = 0;
   //result captures the result of the calculation on what's needed
   //on the final exam for an A-, B-, etc.
   double result;
   //sets all of student's averages to 0.
   //the grade weights are also set here.
   initializeGrades(student);
   //get back the assignment average...
   student.assignmentAverage = gradePrompt(ASSIGNMENTS);
   //lab average...
   student.labAverage = gradePrompt(LABS);
   //quiz average...
   student.quizAverage = gradePrompt(QUIZZES);
   //exam average...
   student.examAverage = gradePrompt(EXAMS);
   //used to figure out how many points have been earned.
   //multiply each average by its respective average
   totalPointsEarned = pointsEarned(student, sumOfWeights);
   //used to get the current standing in a course.
   result = currentGrade(totalPointsEarned, sumOfWeights);
   //print out course grade
   cout<<"Current Course Grade: "<<result<<endl<<endl;
   //as with previous labs, start off at 89.5, decrement by 10
   //each time
   for(double cutoff = 89.5; cutoff >= 59.5; cutoff-=10){
      //result here gets back what the student's final exam score
      //should be, given the grade cutoff, total points earned, and
      //sum of weights
      result = finalExamScore(cutoff, totalPointsEarned, sumOfWeights);
      //print the result
      cout<<"Final exam score for "<<cutoff<<": "<<result<<endl;
      //let the student know if the final exam grade is possible (<= 100)
      if(!isAttainable(result)){//means no
         cout<<"This score is not attainable."<<endl;
      }
      //let the student know if the final exam grade has already been
      //achieved before taking the final exam.
      if(isAssured(result)){
         cout<<"You have already earned this grade without the final exam."<<endl;
      }
      cout<<endl;
   }
   
  //l7.cc finished 
   
}
