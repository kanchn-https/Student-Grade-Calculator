#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    int roll;
    float tma, tph, thu, tcs, tee;
    int total;
    float percentage;
    char grade;
} Student;

Student calculateGrade(Student s);
void displayDetail(Student s);

Student calculateGrade(Student s) {
    s.total = s.tma + s.tph + s.thu + s.tcs + s.tee;
    s.percentage = s.total / 5.0;
    
    if (s.percentage >= 90) s.grade = 'A';
    else if (s.percentage >= 80) s.grade = 'B';
    else if (s.percentage >= 70) s.grade = 'C';
    else if (s.percentage >= 60) s.grade = 'D';
    else s.grade = 'F';
    
    return s;
}

void displayDetail(Student s) {
    printf("\n--------------STUDENT REPORT-------------\n");
    printf("Student ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Roll No: %d\n", s.roll);
    printf("Marks:\n");
    printf("Math: %.2f\n", s.tma);
    printf("Physics: %.2f\n", s.tph);
    printf("English: %.2f\n", s.thu);
    printf("C Programming: %.2f\n", s.tcs);
    printf("Electrical: %.2f\n", s.tee);
    printf("Total: %d\n", s.total);
    printf("Percentage: %.2f%%\n", s.percentage);
    printf("Grade: %c\n", s.grade);
    printf("----------------------------------------\n");
} 