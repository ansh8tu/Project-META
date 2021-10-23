#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "addPatientDetails.h"
#include "onExit.h"

//global variable to assign pId's to the new patients
int autoPId;

int main(){

    int userChoice;
    int patientChoice;
    do{
        printf("\n1. Login as Patient");
        printf("\n2. Login as Data Analyst");
        printf("\n3. Exit");

        printf("\n\n=> Enter your choice: ");
        scanf("%d", &userChoice);

        switch(userChoice){
            case 1: 
                do{
                    printf("\n1. Add Patient Entry");
                    printf("\n2. Return to Main Screen");

                    printf("\n\n=>Enter your choice: ");
                    scanf("%d", &patientChoice);

                    switch(patientChoice){
                        case 1:
                            addPatientDetails();
                        break;
                        case 2:
                            onExit();
                    }

                }while(patientChoice != 2);
            break;

            case 2:
                printf("Logged IN!");
            break;

            case 3:
                printf("\nThank you for your visit!\n\n");
            break;
        }

    }while(userChoice!=3);
        
}