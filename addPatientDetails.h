#ifndef ADDPATIENTDETAILS_H
#define ADDPATIENTDETAILS_H

typedef struct Patients{
    int pId;
    char pName[30];
    int pAge;
    int pCovidStatus;

} Patient;

//void numberOfActivePatients();
//void displayPatientDetails();

extern int autoPId; 

void addPatientDetails(){

    FILE* readAutoPId;
    readAutoPId = fopen("autoPIdStatus.txt", "r");
    fscanf(readAutoPId, "%d", &autoPId);
    printf("%d", autoPId);
    fclose(readAutoPId);

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

    FILE* writeAutoPId;
    writeAutoPId = fopen("autoPIdStatus.txt", "w");
    fprintf(writeAutoPId, "%d", autoPId);
    fclose(writeAutoPId);

    fclose(patientLog);
    fclose(tempLog);

}

#endif