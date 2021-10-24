#ifndef TEMPORARYCOUNTOFPATIENTS_H
#define TEMPORARYCOUNTOFPATIENTS_H

extern int autoPId; 

int displayTemporaryNumberOfRecords(){
    int patientCount = 0;
    char ch = 'a';
    FILE* tempLog;
    tempLog = fopen("TemporaryRecord.txt","r");

    while((ch=fgetc(tempLog))!=EOF) {

        if(ch=='\n'){
            patientCount++;
        }
            
    }

    printf("\nThe number of patients currently in Hospital: %d \n", patientCount);
    
    return patientCount;
}

#endif