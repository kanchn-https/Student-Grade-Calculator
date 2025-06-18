#include <stdio.h>
#include <string.h>

#include "student.c"

void addRecord();
void updateRecord();
void viewRecords();

void addRecord() {
    Student s;
    printf("\n----- Add New Student Record -----\n");
    
    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    
    printf("Enter Name: ");
    getchar();
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = 0;
    
    printf("Enter Roll No: ");
    scanf("%d", &s.roll);
    
    printf("Enter marks for 5 subjects:\n");
    printf("Math: ");
    scanf("%f", &s.tma);
    printf("Physics: ");
    scanf("%f", &s.tph);
    printf("English: ");
    scanf("%f", &s.thu);
    printf("C Programming: ");
    scanf("%f", &s.tcs);
    printf("Electrical: ");
    scanf("%f", &s.tee);
    
    s = calculateGrade(s);
    
    FILE *fp = fopen("Records.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%d %s %d %.2f %.2f %.2f %.2f %.2f %d %.2f %c\n",
                s.id, s.name, s.roll, s.tma, s.tph, s.thu, s.tcs, s.tee,
                s.total, s.percentage, s.grade);
        fclose(fp);
        printf("\nRecord added successfully!\n");
        displayDetail(s);
    } else {
        printf("Error opening file!\n");
    }
}

void updateRecord() {
    int searchRoll;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &searchRoll);
    
    FILE *fp = fopen("Records.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    
    if (fp == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    Student s;
    int found = 0;
    char line[256];
    
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%d %[^0-9] %d %f %f %f %f %f %d %f %c",
               &s.id, s.name, &s.roll, &s.tma, &s.tph, &s.thu,
               &s.tcs, &s.tee, &s.total, &s.percentage, &s.grade);
        
        if (s.roll == searchRoll) {
            found = 1;
            printf("\nCurrent Record:\n");
            displayDetail(s);
            
            printf("\nEnter new details:\n");
            printf("Enter new name: ");
            getchar();
            fgets(s.name, 50, stdin);
            s.name[strcspn(s.name, "\n")] = 0;
            
            printf("Enter new marks:\n");
            printf("Math: ");
            scanf("%f", &s.tma);
            printf("Physics: ");
            scanf("%f", &s.tph);
            printf("English: ");
            scanf("%f", &s.thu);
            printf("C Programming: ");
            scanf("%f", &s.tcs);
            printf("Electrical: ");
            scanf("%f", &s.tee);
            
            s = calculateGrade(s);
            printf("\nUpdated Record:\n");
            displayDetail(s);
        }
        
        fprintf(temp, "%d %s %d %.2f %.2f %.2f %.2f %.2f %d %.2f %c\n",
                s.id, s.name, s.roll, s.tma, s.tph, s.thu, s.tcs, s.tee,
                s.total, s.percentage, s.grade);
    }
    
    fclose(fp);
    fclose(temp);
    
    if (found) {
        remove("Records.txt");
        rename("temp.txt", "Records.txt");
        printf("Record updated successfully!\n");
    } else {
        remove("temp.txt");
        printf("Roll number %d not found!\n", searchRoll);
    }
}

void viewRecords() {
    FILE *fp = fopen("Records.txt", "r");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }
    
    printf("\n----- All Student Records -----\n");
    Student s;
    char line[256];
    int count = 0;
    
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%d %[^0-9] %d %f %f %f %f %f %d %f %c",
               &s.id, s.name, &s.roll, &s.tma, &s.tph, &s.thu,
               &s.tcs, &s.tee, &s.total, &s.percentage, &s.grade);
        
        displayDetail(s);
        count++;
    }
    
    fclose(fp);
    printf("\nTotal records: %d\n", count);
} 