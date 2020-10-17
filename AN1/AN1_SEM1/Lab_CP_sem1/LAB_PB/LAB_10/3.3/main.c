#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int MAX_STUDENT_NAME_LENGTH = 200;
static int MAX_STUDENT_ADDRESS_LENGTH = 200;

/*3.3.Write a modular program which reads student related data for a group, namely: name, date of birth, residence address, and prints them in lexicographic order.
*/

typedef struct {
    int year;
    int month;
    int day;
} date;

typedef struct {
    char * name;
    date dateOfBirth;
    char * address;
} student;

void initializeStudent(student * s) {
    s->name = (char*) malloc(sizeof(char)*MAX_STUDENT_NAME_LENGTH);
    s->address = (char*) malloc(sizeof(char)*MAX_STUDENT_ADDRESS_LENGTH);
}
date readDateOfBirth(int studentNumber) {
    date dateOfBirth;
    printf("Year of birth for student %d\nyear=", studentNumber);
    scanf("%d",&dateOfBirth.year);
    printf("Month of birth for student %d\nmonth=", studentNumber);
    scanf("%d",&dateOfBirth.month);
    printf("Day of the month for student %d\nday=", studentNumber);
    scanf("%d",&dateOfBirth.day);
    return dateOfBirth;
}
student * readStudents(int n)
{
    student * students = (student*)malloc(sizeof(student)*n);
    getchar();
    for(int i=0; i<n; i++)
    {
        initializeStudent(&students[i]);

        printf("Reading student %d\n", i+1);
        printf("Student[%d] name=\n",i+1);
        getchar();
        gets(students[i].name);
        puts(students[i].name);
        students[i].dateOfBirth = readDateOfBirth(i+1);
        getchar();
        gets(students[i].adress);
        puts(student[i].adress);
    }
    return students;
}

student* studentsLexicograpic(int n,student *s){
    int i,j;
    student emp;
    for(i=0;i<n-1;i++) {
        for (j = i + 1; j <n; j++) {
            if (strcmp(s[i].name, s[j].name) > 0) {
                emp=s[i];
                s[i]=s[j];
                s[j]=emp;
            }
        }
    }
    return s;
}
void printStuds(int n, student *s){
    for(int i=0;i<n;i++) {
        printf("Numele studentului este :\n");
        puts(s[i].name);
        printf("Data de nastere a studentului este: day: %d;month: %d,year: %d\n",s[i].dateOfBirth.day,s[i].dateOfBirth.month,s[i].dateOfBirth.year);
        printf("Adresa studentului este:\n");
        puts(s[i].address);
    }
}
int main() {
    int n;
    printf("The number of students of the group is:\n");
    scanf("%d",&n);
    student *stud=readStudents(n);
    student *studsLex=studentsLexicograpic(n,stud);
    printf("Studentii in ordine lexicografica:\n");
    printStuds(n,studsLex);
    return 0;
}
