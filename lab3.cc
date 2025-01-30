/*
lab 3;
Kamal Raj timilsena
Piyachote Naphapayarksiri
Fal Elgizouli


  Program to determine required final grade to get some desired grade.
   Breakdown:
      Homework   20%
      Labs       20%
      Quizzes    10%
      Tests      30%
      Final Exam 20%

    step 1: ask for the number of assignments, quizzes, labs, and exams and their scores and average them
   
   step 2: calculate the contribution to the grade for each type of work (homework,
   lab, quiz, test) and then determine the required grade on the final exam
   
   
   step 3: output the desired grade and the required grade for the final exam
    
*/
#include<iostream>
using namespace std;

int main(){
    // initiliaze variables for grade
    double assignment, labs, quizzes, exams, current_grade, final_exam;

    //weight
    double assignment_weight = .2, labs_weight = .15, quizzes_weight = .15, exams_weight = .3, final_weight = .2; 

    //grade
    double A = 89.5, B = 79.5, C = 69.5, D= 59.5;

    //needed grades
    double needed_gradeA, needed_gradeB, needed_gradeC, needed_gradeD;

    // no. of assignments, quizzes, labs, exams

    int numAssignment, numQuiz, numLab, numExam;

    // scores for assignments, quizzes, labs, exams

    double assignmentScore, quizScore, labScore, examScore;

    // initializing total score for each

    double totalAssignment = 0, totalQuiz = 0, totalLab = 0, totalExam = 0;

    cout<<"How many assignments do you have? "; //ask for num assignments
    cin>>numAssignment;

    for (int i = 0; i < numAssignment; i++ ){ // add all the scores of assignment
        cout<<"Enter the score for assignment "<<i+1<<": ";
        cin>>assignmentScore;
        totalAssignment += assignmentScore;
    }

    assignment = totalAssignment / numAssignment;  //finding the assignment average
    cout<<"Assignment Score: "<<assignment<<endl;
    cout<<endl;

    cout<<"How many quizzes do you have? "; //ask for num quiz
    cin>>numQuiz;

    for (int i = 0; i < numQuiz; i++ ){ // add all the scores of quiz
        cout<<"Enter the score for quiz "<< i+1 <<": ";
        cin>>quizScore;
        totalQuiz += quizScore;
    }
    quizzes = totalQuiz / numQuiz;  //finding the assignment average
    cout<<"Quiz Score: "<<quizzes<<endl;
    cout<<endl;

    cout<<"How many Labs do you have? "; //ask for num labs
    cin>>numLab;

    for (int i = 0; i < numLab; i++ ){ // add all the scores of lab
        cout<<"Enter the score for lab "<< i+1 <<": ";
        cin>>labScore;
        totalLab += labScore;
    }

    labs = totalLab/ numLab;  //finding the assignment average
    cout<<"Lab Score: "<<labs<<endl;
    cout<<endl;

    cout<<"How many exams do you have? "; //ask for num exams
    cin>>numExam;

    for (int i = 0; i < numExam; i++ ){ // add all the scores of exam
        cout<<"Enter the score for exam "<< i+1 <<": ";
        cin>>examScore;
        totalExam += examScore;
    }

    exams = totalExam / numExam;         //find average exam score
    cout<<"Exam Score: "<<exams<<endl;
    cout<<endl;


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
        cout<<endl;
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
            cout<<"B not possible"<<endl;
        }

        else if (needed_gradeB < 0){
            cout<<"B already earned"<<endl;
        }

        else{
        cout<<"needed grade for getting B: "<<needed_gradeB<<endl;
        }

        
        
        
        needed_gradeC=( ( C - current_grade)/final_weight) ; //calculate the needed score on the final exam to achieve an C

        if (needed_gradeC > 100){                              //check if the grade is achievable
            cout<<"C not possible"<<endl;
        }

        else if (needed_gradeC < 0){
            cout<<"C already earned"<<endl;
        }

        else{
        cout<<"Needed grade for getting C: "<<needed_gradeC<<endl;
        }

        
        
        needed_gradeD=( ( D - current_grade)/final_weight) ; //calculate the needed score on the final exam to achieve an D

        if (needed_gradeD > 100){                               //check if the grade is achievable
            cout<<"D not possible"<<endl;
        }

        else if (needed_gradeD < 0){ 
            cout<<"D already earned"<<endl;
        }

        else{
        cout<<"Needed grade for getting D: "<<needed_gradeD<<endl;
        }

        return 0;
}
}