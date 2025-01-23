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

    //needed grades
    double needed_gradeA, needed_gradeB, needed_gradeC, needed_gradeD;

    cout<<"Enter the assignment score: "; //get input from user
    cin >> assignment;

    cout<<"Enter the lab score: ";   //get input from user
    cin>>labs;

    cout<<"Enter the quizzes score: ";   //get input from user
    cin>>quizzes;

    cout<<"Enter the exam score: ";  //get input from user
    cin>>exams;

    //calculation

    current_grade =  (assignment * assignment_weight + labs * labs_weight + quizzes * quizzes_weight + exams *exams_weight);//Find the current grade



    if (current_grade<0){                                         
    cout<<"Current grade cannot be less than zero"<<endl; //ation: Check if the grade is less than 0 (cant have a negative total grade
    }

    else if (current_grade>80){                          //validation: Total current grade cannot be above 80
    cout<<"Current grade cannot be more than 80"<<endl;
    }

    else{
        cout<<"current grade: "<<current_grade<<endl;       //Display the current grade
        needed_gradeA=( ( A - current_grade)/final_weight) ; //calculate the needed score on the final exam to achieve an A

        if (needed_gradeA > 100){                            //check if the grade is achievable
            cout<<"A not possible"<<endl;
        }

        else if (needed_gradeA < 0){
            cout<<"A not possible"<<endl; 
        }

        else{
        cout<<"needed grade for getting A: "<<needed_gradeA<<endl;
        }

        
        
        needed_gradeB=((B-current_grade)/final_weight) ;  //calculate the needed score on the final exam to achieve an B

        if (needed_gradeB > 100){                        //check if the grade is achievable
            cout<<"not possible"<<endl;
        }

        else if (needed_gradeB < 0){
            cout<<"not possible"<<endl;
        }

        else{
        cout<<"needed grade for getting B: "<<needed_gradeB<<endl;
        }

        
        
        
        needed_gradeC=( ( C - current_grade)/final_weight) ; //calculate the needed score on the final exam to achieve an C

        if (needed_gradeC > 100){                              //check if the grade is achievable
            cout<<"not possible"<<endl;
        }

        else if (needed_gradeC < 0){
            cout<<"not possible"<<endl;
        }

        else{
        cout<<"Needed grade for getting C: "<<needed_gradeC<<endl;
        }

        
        
        needed_gradeD=( ( D - current_grade)/final_weight) ; //calculate the needed score on the final exam to achieve an D

        if (needed_gradeD > 100){                               //check if the grade is achievable
            cout<<"not possible"<<endl;
        }

        else if (needed_gradeD < 0){ 
            cout<<"not possible"<<endl;
        }

        else{
        cout<<"Needed grade for getting D: "<<needed_gradeD<<endl;
        }

        return 0;
}
}