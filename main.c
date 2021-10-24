#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "addPatientDetails.h"
//#include "permanentCountOfPatients.h"
//#include "temporaryCountOfPatients.h"
#include "clearTempRecords.h"
#include "onExit.h"

//global variable to assign pId's to the new patients
int autoPId;

int main(){

    int userChoice;
    int patientChoice;
    int dataAnalystChoice;

    do{
        printf("\n1. Login as Patient");
        printf("\n2. Login as Data Analyst");
        printf("\n3. Exit");

        printf("\n\n=> Enter your choice: ");
        scanf("%d", &userChoice);
        printf("\n");

        switch(userChoice){
            case 1: 
                do{
                    printf("\n1. Add Patient Entry");
                    printf("\n2. Return to Main Screen");

                    printf("\n\n=>Enter your choice: ");
                    scanf("%d", &patientChoice);
                    printf("\n");

                    switch(patientChoice){
                        case 1:
                            addPatientDetails();
                        break;
                        case 2:
                            onExit();
                        break;
                    }

                }while(patientChoice != 2);
            break;

            case 2:
                do{
                    printf("\n1. Display Permanent Count of Patients");
                    printf("\n2. Display Temporary Count of Patients");
                    printf("\n3. Return to Main Screen");

                    printf("\n\n=>Enter your choice: ");
                    scanf("%d", &dataAnalystChoice);
                    printf("\n");

                    switch(dataAnalystChoice){
                        case 1:
                            //displayNumberOfRecords();
                        break;
                        case 2:
                            //displayTemporaryNumberOfRecords();
                        break;
                        case 3:
                        break;
                    }

                }while(dataAnalystChoice != 3);
            break;

            case 3:
                printf("\nThank you for your visit!\n\n");
                clearTemporaryRecords();
            break;
        }

    }while(userChoice!=3);
        
}