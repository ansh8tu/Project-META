#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include "addPatientDetails.h"
#include "permanentCountOfPatients.h"
#include "temporaryCountOfPatients.h"
#include "deletePatientRecord.h"
#include "displayPatientDetails.h"
#include "updatePatientDetails.h"
#include "onExit.h"
#include "activeCountOfCovidCases.h"

//global variable to assign pId's to the new patients
extern int autoPId;

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
    int displayDetailsPId;
    int updateDetailsPId;
    int passwordAuthForReceptionist, passwordAuthForDataAnalyst;
    char passwordForReceptionist[20], passwordForDataAnalyst[20];
    char passwordCheckForReceptionist[14] = "ab", passwordCheckForDataAnalyst[13] = "ab";
    char psForR, psForDA;
    int numberOfAttemptsForReceptionist = 0, numberOfAttemptsForDataAnalyst = 0;

    do{
        
        printf("\n\t\t====================================");
        printf("\n\t\t||  Login as Receptionist  >>  1  ||");
        printf("\n\t\t||  Login as Data Analyst  >>  2  ||");
        printf("\n\t\t||  Exit                   >>  3  ||");
        printf("\n\t\t====================================");

        printf("\n\n\nEnter your choice: ");
        scanf("%d", &userChoice);

        switch(userChoice){
            case 1: 
                do{
                    do{
                       printf("\n\nEnter Password : ");
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
                        printf("\n\n\t\tHello, Receptionist!\n");
                        printf("\n\t\t========================================");
                        printf("\n\t\t||  Add Patient Entry         >>   1  ||");
                        printf("\n\t\t||  Discharge Patient         >>   2  ||");
                        printf("\n\t\t||  Display Patient Details   >>   3  ||");
                        printf("\n\t\t||  Update Patient Details    >>   4  ||");
                        printf("\n\t\t||  Return to Main Screen     >>   5  ||");
                        printf("\n\t\t========================================");

                        printf("\n\n\nEnter your choice : ");

                        scanf("%d", &patientChoice);
                        printf("\n");

                        switch(patientChoice){
                            case 1:
                                addPatientDetails();
                            break;
                            case 2:
                                printf("\nEnter the P-ID of Patient that you want to discharge : ");
                                scanf("%d", &dischargePId);
                                deleteRecordFromTemporaryFile(dischargePId);
                            break;
                            case 3:
                                printf("\nEnter the P-ID of Patient that you want to display details for : ");
                                scanf("%d", &displayDetailsPId);
                                displayRecordForPatient(displayDetailsPId,0);
                            break;
                            case 4:
                                printf("\nEnter the P-ID of Patient that you want to update details for : ");
                                scanf("%d", &updateDetailsPId);
                                updateRecordForPatient(updateDetailsPId);
                            break;
                            case 5:
                                onExit();
                            break;
                        }
                    }
                    else{
                        numberOfAttemptsForReceptionist = 0;
                        break;
                    }
                }while(patientChoice != 5 );
            break;

            case 2:
                do{
                    do{
                        printf("\n\nEnter Password : ");
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
                        printf("\n\n\t\tHello, Data Analyst!\n");
                        printf("\n\t\t=================================================================");
                        printf("\n\t\t||  Permanent Count of Patients                        >>   1  ||");
                        printf("\n\t\t||  Temporary Count of Patients                        >>   2  ||");
                        printf("\n\t\t||  Search Patient details in hospital records         >>   3  ||");
                        printf("\n\t\t||  Search Patient details in active patient records   >>   4  ||");
                        printf("\n\t\t||  Active count of covid cases                        >>   5  ||");
                        printf("\n\t\t||  Return to Main Screen                              >>   6  ||");
                        printf("\n\t\t=================================================================");

                        printf("\n\nEnter your choice : ");
                        scanf("%d", &dataAnalystChoice);
                        printf("\n");
                        int searchPId;

                        switch(dataAnalystChoice){
                            case 1:
                                displayNumberOfRecords();
                            break;
                            case 2:
                                displayTemporaryNumberOfRecords();
                            break;
                            case 3:
                                printf("\nEnter the P-ID of Patient that you want to search the details for in hospital record : ");
                                scanf("%d", &searchPId);
                                displayRecordForPatient(searchPId,0);
                            break;
                            case 4:
                                printf("\nEnter the P-ID of Patient that you want to search the details for in temporary record : ");
                                scanf("%d", &searchPId);
                                displayRecordForPatient(searchPId,1);
                                break;
                            case 5:
                                activeCountOfCovidPatients();
                            break;
                            case 6:
                            break;
                        }
                    }
                    else{
                        numberOfAttemptsForDataAnalyst = 0;
                        break;
                    }
                }while(dataAnalystChoice != 6);
            break;

            case 3:
                printf("\nThank you for your visit!\n\n");
            break;
        }

    }while(userChoice!=3);
        
}
