#include <stdio.h>
#include <string.h>
#include "rajan.h"
// #include "form.h"



int auth()
{
    char ID[10];
    char Password[20];
    char userid[10];   // Change to char array for user input (matches the format of ID)
    char userpass[20]; // Change to char array for user input (matches the format of Password)

    // Open file to read login details
    FILE *fptr = fopen("AdminLogin.txt", "r");

    // Check if file opened successfully
    if (fptr == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Read ID and Password from the file
    fgets(ID, sizeof(ID), fptr);
    fgets(Password, sizeof(Password), fptr);

    // Close the file
    fclose(fptr);

    // Extract values after ':'
    char *adminId = strchr(ID, ':');
    char *adminPass = strchr(Password, ':');

    // If colon found, move pointer to the value after it
    if (adminId != NULL)
    {
        adminId++;                              // Skip the colon
        adminId[strcspn(adminId, "\n")] = '\0'; // Remove trailing newline
    }

    if (adminPass != NULL)
    {
        adminPass++;                                // Skip the colon
        adminPass[strcspn(adminPass, "\n")] = '\0'; // Remove trailing newline
    }

    // Print extracted ID and Password
    printf("\nID is: %s and Password is: %s\n", adminId, adminPass);

    // Get user input for ID and password
    printf("Enter your ID: ");
    scanf("%s", userid); // Use %s to read a string for ID
    printf("\nEnter your password: ");
    scanf("%s", userpass); // Use %s to read a string for Password

    // Compare user input with the values from the file
    if (strcmp(adminId, userid) == 0 && strcmp(adminPass, userpass) == 0)
    {
        printf("=================\n");
        printf("Login success\n");
        Adminmenu();
        int choice;
        printf("\nEnter your choice: ");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            int choice;
            printf("1. Hotel Saff\n");
            printf("2. Customer\n");
            printf("\nEnter your choice: ");
            scanf(" %d", &choice);
            if (choice == 1)
            {
             
                printf("=================\n");
                printf("Welcome to staff regestration\n");
                 
               
                
                printf("\n=================");
            }
            else if (choice == 2)
            {
                printf("=================\n");
                printf("Welcome to Customer regestration");
                printf("\n=================");
            }
        }

        printf("=================\n");
    }
    else
    {
        printf("=================\n");
        printf("Login failed\n");
        printf("=================\n");
    }

    return 0;
}

int main()
{
    // Write initial data to file
    FILE *fptr = fopen("AdminLogin.txt", "w");
    if (fptr == NULL)
    {
        printf("Error creating file.\n");
        return 1;
    }

    fputs("ID:1\nPassword:1", fptr); // Initial login details in the file
    fclose(fptr);

    // Display menu and take user input
    Welcome_menu();

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Process user choice
    switch (choice)
    {
    case 1:
        auth(); // Authenticate
        break;
    default:
        printf("Invalid choice.\n");
        break;
    }

    return 0;
}
