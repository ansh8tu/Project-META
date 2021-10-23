#ifndef ADDPATIENTDETAILS_H
#define ADDPATIENTDETAILS_H

typedef struct Patients{
    int pId;
    char pName[30];
    int pAge;
    char pDiesase[30];
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

    patientLog = fopen("HospitalRecord.txt", "a");
    tempLog = fopen("TemporaryRecord.txt", "a");

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

        printf("\nEnter the patient's disease: ");
        scanf("%s", pat[i].pDiesase);

        printf("\nEnter the patient's covid status(1-Positive 0-Negative): ");
        scanf("%d", &pat[i].pCovidStatus);

        fwrite(&pat[i], sizeof(Patient), 1, patientLog);
        fwrite(&pat[i], sizeof(Patient), 1, tempLog);

        printf("\nHello %s, your Patient-ID is: %d ", pat[i].pName, pat[i].pId);

        if((strcmp(pat[i].pDiesase, "Headache") == 0)  || (strcmp(pat[i].pDiesase, "headache") == 0)){
            printf("\nPlease refer to %s specialist in Ward 101", pat[i].pDiesase);
        }
        
    }

    FILE* writeAutoPId;
    writeAutoPId = fopen("autoPIdStatus.txt", "w");
    fprintf(writeAutoPId, "%d", autoPId);
    fclose(writeAutoPId);

    fclose(patientLog);
    fclose(tempLog);

}

#endif