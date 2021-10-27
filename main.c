#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

                }while(patientChoice != 3);
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
                            displayNumberOfRecords();
                        break;
                        case 2:
                            displayTemporaryNumberOfRecords();
                        break;
                        case 3:
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
