#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include "addPatientDetails.h"
#include "permanentCountOfPatients.h"
#include "temporaryCountOfPatients.h"
#include "deletePatientRecord.h"
#include "onExit.h"

//global variable to assign pId's to the new patients
extern int autoPId = 0;

int main(){

    //opening the autoPId file to get the last entry 
    FILE* readAutoPId;
    readAutoPId = fopen("autoPIdStatus.txt", "r");
    fscanf(readAutoPId, "%d", &autoPId);
    fclose(readAutoPId);

    //storing variables for switch-cases
    int userChoice;
    int patientChoice;
    int dataAnalystChoice;
    int dischargePId;
    int passwordAuthForReceptionist, passwordAuthForDataAnalyst;
    char passwordForReceptionist[20], passwordForDataAnalyst[20];
    char passwordCheckForReceptionist[14] = "passwordrecep", passwordCheckForDataAnalyst[13] = "passworddata";
    char psForR, psForDA;
    int numberOfAttemptsForReceptionist = 0, numberOfAttemptsForDataAnalyst = 0;

    do{
        
        printf("\n1. Login as Receptionist");
        printf("\n2. Login as Data Analyst");
        printf("\n3. Exit");

        printf("\n\n=> Enter your choice: ");
        scanf("%d", &userChoice);
        printf("\n");

        switch(userChoice){
            case 1: 
                do{
                    do{
                        printf("\nEnter Password: ");
                        int i=0;
                        while((psForR = _getch()) != 13){
                            passwordForReceptionist[i] = psForR;
                            i++;
                            printf("*");               
                        }
                        passwordForReceptionist[i] = '\0';
                        printf("\n");

                        if(strcmp(passwordForReceptionist, passwordCheckForReceptionist) == 0){
                            passwordAuthForReceptionist = 1;
                            fflush(stdin);
                        }
                        else{
                            printf("\nSorry, Wrong Password! Try Again!");
                            printf("\n");
                            printf("Attempts Left = %d", 2 - numberOfAttemptsForReceptionist);
                            printf("\n");
                            passwordAuthForReceptionist = 0;
                            numberOfAttemptsForReceptionist++;
                            fflush(stdin);
                        }
                    }while(passwordAuthForReceptionist == 0 && numberOfAttemptsForReceptionist < 3);
                    
                    if(passwordAuthForReceptionist ==1){
                        printf("\n\nHello, Receptionist!");
                        printf("\n");
                        printf("\n1. Add Patient Entry");
                        printf("\n2. Discharge Patient");
                        printf("\n3. Return to Main Screen");

                        printf("\n\n=>Enter your choice: ");
                        scanf("%d", &patientChoice);
                        printf("\n");

                        switch(patientChoice){
                            case 1:
                                addPatientDetails();
                            break;
                            case 2:
                                printf("\nEnter the P-ID of Patient that you want to discharge: ");
                                scanf("%d", &dischargePId);
                                deleteRecordFromTemporaryFile(dischargePId);
                            break;
                            case 3:
                                onExit();
                            break;
                        }
                    }
                    else{
                        numberOfAttemptsForReceptionist = 0;
                        break;
                    }
                }while(patientChoice != 3 );
            break;

            case 2:
                do{
                    do{
                        printf("\nEnter Password: ");
                        int i=0;
                        while((psForDA = _getch()) != 13){
                            passwordForDataAnalyst[i] = psForDA;
                            i++;
                            printf("*");               
                        }
                        passwordForDataAnalyst[i] = '\0';
                        printf("\n");

                        if(strcmp(passwordForDataAnalyst, passwordCheckForDataAnalyst) == 0){
                            passwordAuthForDataAnalyst = 1;
                            fflush(stdin);
                        }
                        else{
                            printf("\nSorry, Wrong Password! Try Again!");
                            printf("\n");
                            printf("Attempts Left = %d", 2 - numberOfAttemptsForDataAnalyst);
                            printf("\n");
                            passwordAuthForDataAnalyst = 0;
                            numberOfAttemptsForDataAnalyst++;
                            fflush(stdin);
                        }
                    }while(passwordAuthForDataAnalyst == 0 && numberOfAttemptsForDataAnalyst < 3);

                    if(passwordAuthForDataAnalyst ==1){
                        printf("\n\nHello, Data Analyst!");
                        printf("\n");
                        printf("\n1. Permanent Count of Patients");
                        printf("\n2. Temporary Count of Patients");
                        printf("\n3. Return to Main Screen");

                        printf("\n\n=>Enter your choice: ");
                        scanf("%d", &dataAnalystChoice);
                        printf("\n");

                        switch(dataAnalystChoice){
                            case 1:
                                displayNumberOfRecords();
                            break;
                            case 2:
                                displayTemporaryNumberOfRecords();
                            break;
                            case 3:
                            break;
                        }
                    }
                    else{
                        numberOfAttemptsForDataAnalyst = 0;
                        break;
                    }
                }while(dataAnalystChoice != 3);
            break;

            case 3:
                printf("\nThank you for your visit!\n\n");
            break;
        }

    }while(userChoice!=3);
        
}
