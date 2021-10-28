#ifndef ADDPATIENTDETAILS_H
#define ADDPATIENTDETAILS_H

typedef struct Patients{
    int pId;
    char pFirstName[30];
    char pLastName[30];
    int pAge;
    char pDiesase[30];
    int pCovidStatus;

} Patient;

int displayTemporaryNumberOfRecords();

int autoPId; 

void addPatientDetails(){
    
    int tempVar = displayTemporaryNumberOfRecords();

    int numberOfPatients;
    printf("Enter the number of patients to add: "); //do update the printf statement in original project
    scanf("%d", &numberOfPatients);
    fflush(stdin);
    
    int capacityOfHospital = 8;

    if(tempVar + numberOfPatients >= capacityOfHospital){
        printf("Hospital is Overcrowded, Sorry for the inconvinience!");
        printf("\n");
        printf("Max Patients allowed to enter: %d", (capacityOfHospital - tempVar));
        return;
    }
  

    Patient* pat = (Patient*)calloc(numberOfPatients, sizeof(Patient));

    FILE* patientLog;
    FILE* tempLog;

    patientLog = fopen("HospitalRecord.txt", "a");
    tempLog = fopen("TemporaryRecord.txt", "a");

    int previousEntry = autoPId - 1000; 
    int i;
    for(i=previousEntry; i<numberOfPatients + previousEntry; i++){

        //assigning the patient ID
        pat[i - previousEntry].pId = autoPId;
        autoPId++;

        printf("\nEnter the patient's first name: ");
        scanf("%s", pat[i - previousEntry].pFirstName);

        fflush(stdin);
        printf("\nEnter the patient's last name: ");
        scanf("%s", pat[i - previousEntry].pLastName);

        fflush(stdin);
        printf("\nEnter the patient's age: ");
        scanf("%d", &pat[i - previousEntry].pAge);

        fflush(stdin);
        printf("\nEnter the patient's disease: ");
        scanf("%s", pat[i - previousEntry].pDiesase);

        fflush(stdin);
        printf("\nEnter the patient's covid status(1-Positive 0-Negative): ");
        scanf("%d", &pat[i - previousEntry].pCovidStatus);
        
        fflush(stdin);

        /*
        fwrite(&pat[i], sizeof(Patient), 1, patientLog);
        fwrite(&pat[i], sizeof(Patient), 1, tempLog);
        */

        fprintf(patientLog, "%d %s %s %d %s %d %s", pat[i - previousEntry].pId, pat[i - previousEntry].pFirstName, pat[i - previousEntry].pLastName, pat[i - previousEntry].pAge, pat[i - previousEntry].pDiesase, pat[i - previousEntry].pCovidStatus, "\n");
        fprintf(tempLog, "%d %s %s %d %s %d %s", pat[i - previousEntry].pId, pat[i - previousEntry].pFirstName, pat[i - previousEntry].pLastName, pat[i - previousEntry].pAge, pat[i - previousEntry].pDiesase, pat[i - previousEntry].pCovidStatus, "\n");

        printf("\nHello %s %s, your Patient-ID is: %d \n", pat[i - previousEntry].pFirstName, pat[i - previousEntry].pLastName, pat[i - previousEntry].pId);

        /*
        if((strcmp(pat[i].pDiesase, "Headache") == 0)  || (strcmp(pat[i].pDiesase, "headache") == 0)){
            printf("\nPlease refer to %s specialist in Ward 101\n", pat[i].pDiesase);
        }
        */

       
        
    }

    FILE* writeAutoPId;
    writeAutoPId = fopen("autoPIdStatus.txt", "w");
    fprintf(writeAutoPId, "%d", autoPId);
    fclose(writeAutoPId);

    fclose(patientLog);
    fclose(tempLog);

}

#endif