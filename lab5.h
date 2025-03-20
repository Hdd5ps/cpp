#include <iostream>
using namespace std;

#ifndef LAB5_H
#define LAB5_H

enum Grades
{
   ASSIGNMENTS,
   LABS,
   QUIZZES,
   EXAMS
};

// returns the corresponding weight with each grade type.
double getGradeWeight(Grades g)
{
   switch (g)
   {

   case ASSIGNMENTS:
      return 0.2;
      break;

   case LABS:
      return 0.15;
      break;

   case QUIZZES:
      return 0.15;
      break;

   case EXAMS:
      return 0.30;
      break;

   default:
      return 0.20;
      break;
   }
}

// prints out the string equivalent of the Grades variable.
void printGradeWeight(Grades g)
{
   switch (g)
   {
   case ASSIGNMENTS:
      cout << "Assignments" << endl;
      break;

   case LABS:
      cout << "Labs" << endl;
      break;

   case QUIZZES:
      cout << "Quizzes" << endl;
      break;

   case EXAMS:
      cout << "Exams" << endl;
      break;

   default:
      cout << "Final Exam" << endl;
      break;
   }
}

// prompts the user for an average of a certain type of grades, as
// denoted by the second argument.
// stores the average of a type of grade in the first argument.
// the array should be organized in the same way you see the different
// values of Grades listed above.
void gradePrompt(double array[], Grades g)
{
   double Total = 0;
   int count = 0;

   printGradeWeight((Grades)g);
   while (array[g] != -1)
   {
      cout << "Enter a grade (or -1 to stop): ";
      cin >> array[g];
      if (array[g] != -1)
      {
         count++;
         Total += array[g];
      }
   }
   cout << endl;

   array[g] = Total / count;
}

// takes in
void printGradeAverages(const double array[], const int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << " Average: ";
      cout << array[i] << endl;
   }
}

// averagegrade
// prints out total points earned.
// needs to call getGradeWeight function to get the grade weight for each type
// sum these together.
// also keep a sum of the weights, which is returned via reference parameter
// we're not going to modify the array, just read from it, so that's why
// the array passed in here is declared as a const
// the second argument is the size of the array
double pointsEarned(const double gradeComponent[], const int SIZE, double &totalWeight)
{
   totalWeight = 0;
   double weight = 0;
   double pointsEarned = 0;
   for (int i = 0; i < SIZE; i++)
   {
      // gradePrompt(gradeComponent[i], Grades (gradeComponent[i]));
      weight = getGradeWeight(Grades(i));
      totalWeight += weight;
      pointsEarned = gradeComponent[i] * totalWeight;
      return pointsEarned;
   }
}

// calculates the current course grade.
// arguments are total number of points and the sum of weights
double currentGrade(double pointsEarned, double totalWeight)
{
   double averageGrade = pointsEarned * totalWeight;
   return averageGrade;
}

// calculates the final exam score needed
// arguments: desired grade, total number of points, and the total grade
// weight earned thus far.
double finalExamScore(double desiredGrade, double totalPoints, double totalGradeWeight)
{
   desiredGrade -= totalPoints;
   return (desiredGrade/(1-totalGradeWeight));
}

// prints out whether the grade is attainable (<=100)
void isScoreAttainable(double current_grade){
   if (current_grade > 100){
      cout<<"The score cannot be attained"<<endl;
   } else {
      cout<<"The score is achievable"<<endl;
   }
}

// prints out whether the grade has already been earned pre-final exam
void isScoreAssured(double current_grade){
if (current_grade < 0){
   cout<<"The score has already been attained"<<endl; //ation: Check if the grade is less than 0 (cant have a negative total grade
}
}
#endif