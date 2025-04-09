#include <iostream>
using namespace std;

#ifndef LAB7_H
#define LAB7_H

enum Grades
{
    ASSIGNMENTS,
    LABS,
    QUIZZES,
    EXAMS
};

struct CourseGrade
{
    // four types of grades:
    double assignmentAverage;
    double labAverage;
    double quizAverage;
    double examAverage;
    // four types of weights:
    double assignmentWeight;
    double labWeight;
    double quizWeight;
    double examWeight;
};

// initializing the averages to 0 and the weights to how they were
// set up with lab5.
// an instance of the class?  Now we're back to pass-by-value v.
// pass-by-reference
// this function sets all of the averages to zero and sets the different
// weights accordingly.
void initializeGrades(CourseGrade &course)
{
    course.assignmentAverage = 0.0;
    course.labAverage = 0.0;
    course.quizAverage = 0.0;
    course.examAverage = 0.0;

    course.assignmentWeight = 0.2;
    course.labWeight = 0.3;
    course.quizWeight = 0.1;
    course.examWeight = 0.4;
}

// print out grade type, given an argument of enumeration type Grades
void printGradeType(Grades g)
{
    switch (g)
    {
    case ASSIGNMENTS:
        cout << "Assignments\n";
        break;
    case LABS:
        cout << "Labs\n";
        break;
    case QUIZZES:
        cout << "Quizzes\n";
        break;
    case EXAMS:
        cout << "Exams\n";
        break;
    }
}
// returns the average of a certain grade type, denoted by the argument
// that has been passed in
double gradePrompt(Grades gradeType)
{
    double userInput;
    printGradeType(gradeType);
    double numberOfGrades = 0, total = 0;

    cout << "Enter a grade (or -1 to end): ";
    cin >> userInput;
    while (userInput != -1)
    {

        total += userInput;

        numberOfGrades++;
        cout << "Enter a grade (or -1 to end): ";
        cin >> userInput;
    }
    cout << endl;
    double totalAverage = total / numberOfGrades;

    return totalAverage;
}

// prints the different grade type averages (assignment, lab, quiz, exam)
void printAverages(CourseGrade course)
{
    cout << "Assignments Average: " << course.assignmentAverage << endl;
    cout << "Lab Average: " << course.labAverage << endl;
    cout << "Quiz Average: " << course.quizAverage << endl;
    cout << "Exam Average: " << course.examAverage << endl;
}
// calculates the current points earned
// for each of the averages, multiply by their weights
// sum results together
// keep track of the total value of weights; it is what's returned
// via reference
double pointsEarned(CourseGrade student, double &sumOfWeights)
{
    // sum of weights is passed by reference
    // total points earned is the sum of the averages * their weights
    double totalPointsEarned = 0;
    // assignment average * assignment weight
    totalPointsEarned += student.assignmentAverage * student.assignmentWeight;
    // lab average * lab weight
    totalPointsEarned += student.labAverage * student.labWeight;
    // quiz average * quiz weight
    totalPointsEarned += student.quizAverage * student.quizWeight;
    // exam average * exam weight
    totalPointsEarned += student.examAverage * student.examWeight;

    // sum of weights is the sum of all the weights
    sumOfWeights = student.assignmentWeight + student.labWeight +
                   student.quizWeight + student.examWeight;

    return totalPointsEarned;
}

// returns current grade based on weight, points earned
double currentGrade(double totalPointsEarned, double sumOfWeights)
{
    // current grade is the total points earned divided by the sum of weights
    // multiplied by 100 to get a percentage
    double grade = totalPointsEarned / sumOfWeights;
    return grade * 100;
}

// figure out what would need to be made on the final to earn grade sought after
// 1 argument is the target grade, 1 argument is total points earned
// 1 argument is the sum of weights.
// returns the final exam grade needed
double finalExamScore(double cutoff, double totalPointsEarned, double sumOfWeights)
{
    // final exam score is the cutoff grade minus the total points earned
    // divided by the sum of weights
    double finalExamScore = (cutoff - totalPointsEarned) / sumOfWeights;
    // multiply by 100 to get a percentage
    return finalExamScore * 100;
}

// is the grade possible to earn?
// the bool return type denotes either yes or no (or the bool equivalent)
bool isAttainable(double needFinalScore)
{
    return needFinalScore >= 0.0 && needFinalScore <= 100.0;
}
// has the final exam grade already been earned?  yes/no via bool equivalent
// figure out if the grade sought after has already been attained.
bool isAssured(double neededFinalScore)
{
    return neededFinalScore <= 0.0;
}
#endif