#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Patients{
    int pId;
    char pName[30];
    int pAge;
    bool pCovidStatus;

} Patient;

//global variable to assign pId's to the new patients
int autoPId;

void addPatientDetails(){

    FILE* readAutoPId;
    readAutoPId = fopen("autoPIdStatus.txt", "r");
    fscanf(readAutoPId, "%d", &autoPId);
    fclose(readAutoPId);
    printf("%d", autoPId);

    int numberOfPatients;
    printf("Enter the total number of patients: "); //do update the printf statement in original project
    scanf("%d", &numberOfPatients);

    Patient* pat;
    pat = (Patient*)calloc(numberOfPatients, sizeof(Patient));

    FILE* patientLog;
    FILE* tempLog;

    patientLog = fopen("HospitalRecord.txt", "w+");
    tempLog = fopen("TemporaryRecord.txt", "w+");

    int previousEntry = autoPId - 1000; 
    int i;
    for(i=previousEntry; i<numberOfPatients + previousEntry; i++){

        //assigning the patient ID
        pat[i].pId = autoPId;
        autoPId++;

        printf("\nEnter the patient's name: ");
        scanf("%s", pat[i].pName);

        printf("\nEnter the patient's age: ");
        scanf("%d", &pat[i].pAge);

        printf("\nEnter the patient's covid status(1-Positive 0-Negative): ");
        scanf("%d", &pat[i].pCovidStatus);

        fwrite(&pat[i], sizeof(Patient), 1, patientLog);
        fwrite(&pat[i], sizeof(Patient), 1, tempLog);

    }

    fclose(patientLog);
    fclose(tempLog);

}


void onExit(){
    FILE* writeAutoPId;
    writeAutoPId = fopen("autoPIdStatus.txt", "w+");
    fprintf(writeAutoPId, "%d", autoPId);
    fclose(writeAutoPId);

}

void numberOfActivePatients();
void displayPatientDetails();

int main(){
    int userChoice;
    do{
        printf("\n1. Add Patient Entry");
        printf("\n2. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &userChoice);

        switch(userChoice){
            case 1:
                addPatientDetails();
            break;
            case 2:
                onExit();
        }

    }while(userChoice != 2);
}