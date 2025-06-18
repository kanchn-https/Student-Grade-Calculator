#include <stdio.h>
#include "filehandler.c"

int main() {
    int choice;
    do {
        printf("\n----------STUDENT GRADE CALCULATOR----------\n");
        printf("1. Add New Record\n");
        printf("2. Update Record\n");
        printf("3. View All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecord();
                break;
            case 2: updateRecord();
                break;
            case 3: viewRecords();
                break;
            case 4: printf("Exiting program.\n");
                break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
} 