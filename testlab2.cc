/*
lab 2;
Kamal raj timilsena
Piyachote Naphapayarksiri
Fal Elgizouli
you'll be given an average from the user for each of the first four areas.
-what the current average is ?
- what if analysis
    -what's it take to get an A? (89.5)
    -what's it take to get an B? (79.5)
    -what's it take to get an C? (69.5)
    -what's it take to get an D? (59.5)

  Program to determine required final grade to get some desired grade.
   Breakdown:
      Homework   20%
      Labs       20%
      Quizzes    10%
      Tests      30%
      Final Exam 20%
   
   step 1: get the data from the user. get the homework average, lab average,
           quiz average, and test average. finally, get the desired course grade.
   
   step 2: calculate the contribution to the grade for each type of work (homework,
   lab, quiz, test) and then determine the required grade on the final exam
   
   step 3: print the summary table with the components and their contribution to the
   grade (as required). format contribution with 1 decimal place. use the '%' on the
   averages
   
   step 4: output the desired grade and the required grade for the final exam with
*/
#include<iostream>
using namespace std;

int main(){
    // initiliaze variables
    double assignment, labs, quizzes, exams, current_grade, final_exam;

    //weight
    double assignment_weight = .2, labs_weight = .15, quizzes_weight = .15, exams_weight = .3, final_weight = .2;

    //grade
    double A = 89.5, B = 79.5, C = 69.5, D= 59.5;

    //needed grade
  double needed_gradeA, needed_gradeB, needed_gradeC, needed_gradeD;



    cout<<"Enter the assignment score: ";
    cin >> assignment;

    cout<<"Enter the lab score: ";
    cin>>labs;

    cout<<"Enter the quizzes score: ";
    cin>>quizzes;

    cout<<"Enter the exam score: ";
    cin>>exams;

    //calculation




    return 0;
}
