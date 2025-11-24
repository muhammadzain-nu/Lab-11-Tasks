#include <stdio.h>
#define max 100

struct SALARY {
    float pay;
    float bonus;
    float deductions;
};

struct employee {
    int id;
    char name[20];
    struct SALARY salary;
};

float netsalary(struct employee emp) {
    return (emp.salary.pay + emp.salary.bonus) - emp.salary.deductions;
}

void displayEmployee(struct employee emp) {
    printf("\n----------------------------------------\n");
    printf("Employee ID      : %d\n", emp.id);
    printf("Employee Name    : %s\n", emp.name);
    printf("Basic Pay        : %.2f\n", emp.salary.pay);
    printf("Bonuses          : %.2f\n", emp.salary.bonus);
    printf("Deductions       : %.2f\n", emp.salary.deductions);
    printf("Net Salary       : %.2f\n", netsalary(emp));
    printf("----------------------------------------\n");
}

int main() {
    int choice = 0;
    int n, i = 0;
    struct employee emp[max];

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &emp[i].id);

        printf("Name: ");
        scanf("%s", emp[i].name);

        printf("Basic Pay: ");
        scanf("%f", &emp[i].salary.pay);

        printf("Bonuses: ");
        scanf("%f", &emp[i].salary.bonus);

        printf("Deductions: ");
        scanf("%f", &emp[i].salary.deductions);
    }

    do {
        printf("\n===== MENU =====\n");
        printf("1. Calculate net salary of all employees\n");
        printf("2. Display salary details\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n--- Net Salaries ---\n");
            for (i = 0; i < n; i++) {
                printf("Employee %s (ID %d): Net Salary = %.2f\n",
                    emp[i].name, emp[i].id, netsalary(emp[i]));
            }
            break;

        case 2:
            for (i = 0; i < n; i++) {
                displayEmployee(emp[i]);
            }
            break;

        case 3:
            printf("\nExiting program...\n");
            break;

        default:
            printf("Invalid choice, try again.\n");
        }
    } while (choice != 3);

    return 0;
}

