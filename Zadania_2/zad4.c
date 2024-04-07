#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[25];
    float grade;
};

//function that sorts tab of students
void sortStudent(struct Student *student, int size)
{
    struct Student temporary;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (student[j].grade < student[j + 1].grade) {
                temporary = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temporary;
            } } }
}

int main()
{
    //initiating board of students
    const int numS = 20;
    struct Student students[numS];

    //filling the board with example data
    for(int i=0; i<numS; i++)
    {
        snprintf(students[i].name,sizeof(students[i].name), "Student%d",i+1);
        students[i].grade = (float)2.0 + (float)(rand() % 8); // grades 2-10 for better range in sorting
    }

    //execution of sorting function
    sortStudent(students, numS);

    //printout program results
    printf("Sorted list of students:\n");
    for(int i =0; i<numS;i++)
    {
        printf("Student: %s, final grade: %.2f.\n",students[i].name,students[i].grade);
    }

    return 0;
}