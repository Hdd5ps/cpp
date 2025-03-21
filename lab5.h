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

   default: // exams
      return 0.30;
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

   default:
      cout << "Exams" << endl;
      break;
   }
}

// prompts the user for an average of a certain type of grades, as
// denoted by the second argument.
// stores the average of a type of grade in the first argument.
// the array should be organized in the same way you see the different
// values of Grades listed above.
void gradePrompt(double grades[], Grades g)
{
   double grade;
   double total = 0.0;
   int count = 0;
   printGradeWeight(g);

   cout << "Enter a grade (or -1 to stop): ";
   cin >> grade;

   while (grade != -1) // sentinel value to stop input
   {
      total += grade; // accumulate the total of the grades
      count++;        // increment the count of grades entered
      cout << "Enter a grade (or -1 to stop): ";
      cin >> grade;
   }

   if (count > 0)
   {
      grades[g] = total / count; // Store the average grade for the specified type
   }
   else
   {
      grades[g] = 0.0; // Default to 0 if no grades were entered
   }
   cout << endl
        << endl;
}

// takes in
void printGradeAverages(const double array[], const int size)
{
   for (int i = 0; i < size; i++)
   {
      printGradeWeight((Grades)i);
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
double pointsEarned(const double grades[], const int size, double &totalWeight)
{
   double totalPoints = 0.0;
   totalWeight = 0.0;
   for (int i = 0; i < size; i++) // iterate through the array
   {
      double weight = getGradeWeight((Grades)i); // get the weight for the current grade type

      totalPoints += (grades[i] * weight); // calculate the total points earned for this grade type
      totalWeight += weight;
   }
   return totalPoints;
}

// calculates the current course grade.
// arguments are total number of points and the sum of weights
double currentGrade(double totalPoints, double totalWeight)
{
   return totalPoints / totalWeight; // calculate the current grade
   // by dividing total points by total weight
}

// calculates the final exam score needed
// arguments: desired grade, total number of points, and the total grade
// weight earned thus far.
double finalExamScore(double desiredGrade, double totalPoints, double totalWeight)
{
   desiredGrade -= totalPoints;               // subtract the total points from the desired grade
   return (desiredGrade / (1 - totalWeight)); // calculate the final exam score needed
   // by dividing the desired grade by the remaining weight
}

// prints out whether the grade is attainable (<=100)
void isScoreAttainable(double current_grade)
{
   if (current_grade > 100)
   {
      cout << "The score cannot be attained. " << endl
           << endl;
   }
   else
   {
      cout << "The score is achievable. " << endl
           << endl;
   }
}

// prints out whether the grade has already been earned pre-final exam
void isScoreAssured(double current_grade)
{
   if (current_grade <= 0)
   {
      cout << "The grade has already been earned. " << endl
           << endl;
   }
}

#endif