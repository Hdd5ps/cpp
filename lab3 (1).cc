#include "lab3.h"


int main(){
   double average = calculateCurrentGrade();
   //average represents total points earned across all grade components,
   //except for the final exam
   //printAverage prints out the total number of points divided by the
   //percentage of the grade already known (everything but the final)
   printAverage(average, FINAL_EXAM);
   //prints what is necessary to make an A, B, C, or D.
   printNeededScores(average);
   return 0;
}