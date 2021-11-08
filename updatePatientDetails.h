#ifndef UPDATEPATIENTDETAILS_H
#define UPDATEPATIENTDETAILS_H

void updateRecordForPatient(int pId){

    //checking in temporary records
    char ch = 'a';
    int i=0;
    int flag = 0;
    char storePId[4];

    FILE* tempLog;
    tempLog = fopen("TemporaryRecord.txt","r");

    int j = 0;
    int line = 0;
    int temp = 0;

    while((ch=fgetc(tempLog))!=EOF) {
        if(i<4){
            storePId[i] = ch;
        }

        i++;
        if(ch=='\n'){
            i=0;
            sscanf(storePId, "%d", &j);
            if(j == pId){
                flag = 1;
                break;
            }
            line++;
        }
    }

    //if patient-id is not found in records 
    if(flag == 0){
        printf("\n");
        printf("Sorry P-ID: %d, doesn't exist in Active Patient Record!", pId);
        printf("\n");
    }

    fclose(tempLog);
    

    //checking in permanent records
    char ch2 = 'a';
    int i2=0;
    int flag2 = 0;
    char storePId2[4];

    FILE* tempLog2;
    tempLog2 = fopen("HospitalRecord.txt","r");

    int j2 = 0;
    int line2 = 0;
    int temp2 = 0;

    while((ch2=fgetc(tempLog2))!=EOF) {
        if(i2<4){
            storePId2[i2] = ch2;
        }

        i2++;
        if(ch2=='\n'){
            i2=0;
            sscanf(storePId2, "%d", &j2);
            if(j2 == pId){
                flag2 = 1;
                break;
            }
            line2++;
        }
    }

    //if patient-id is not found in records 
    if(flag2 == 0){
        printf("\n");
        printf("Sorry P-ID: %d, doesn't exist in Hospital Record!", pId);
        printf("\n");
    }

    fclose(tempLog2);

    if (flag==0 && flag2==0){
        return;
    }
    
    //taking input
    char pFirstNameUpdated[30];
    char pLastNameUpdated[30];
    int pAgeUpdated;
    char pDiesaseUpdated[30];
    int pCovidStatusUpdated;

    printf("\n");
    printf("\n\nEnter the patient's first name : ");
    scanf("%s", pFirstNameUpdated);

    fflush(stdin);
    printf("\nEnter the patient's last name : ");
    scanf("%s", pLastNameUpdated);

    fflush(stdin);
    printf("\nEnter the patient's age : ");
    scanf("%d", &pAgeUpdated);

    fflush(stdin);
    printf("\nEnter the patient's disease/Symptoms : ");
    scanf("%s", pDiesaseUpdated);

    fflush(stdin);
    printf("\nEnter the patient's covid status(1-Positive 0-Negative) : ");
    scanf("%d", &pCovidStatusUpdated);

    printf("\n");

    //for temp
    FILE* tempLog1;
    FILE* dummyFile;
    tempLog1 = fopen("TemporaryRecord.txt","r");
    dummyFile = fopen("DummyFile.txt", "a+");

    //for permanent
    FILE* tempLog12;
    FILE* dummyFile2;
    tempLog12 = fopen("HospitalRecord.txt","r");
    dummyFile2 = fopen("DummyFile2.txt", "a+");


    if (flag!=0){
        printf("\n");
        printf("P-Id: %d details has been successfully updated in Active Patient Record!!", pId);
        printf("\n");
    }
    
    
    int as=1;
    while ((ch=fgetc(tempLog1))!=EOF){
        if (temp != line){
            putc(ch, dummyFile);
        }
        else if(temp == line && as == 1){
            fprintf(dummyFile, "%d %s %s %d %s %d %s", pId, pFirstNameUpdated, pLastNameUpdated, pAgeUpdated, pDiesaseUpdated, pCovidStatusUpdated, "\n");
            as++;
        }
        
        if (ch == '\n'){
                temp++;
        }
    }

    fclose(tempLog1);
    fclose(dummyFile);
    remove("TemporaryRecord.txt");
    rename("DummyFile.txt", "TemporaryRecord.txt");     
    
    fflush(stdin);

    //for hospital record   
    if(flag2!=0){
        printf("\n");
        printf("P-Id: %d details has been successfully updated in Hospital Record!!", pId);
        printf("\n");
    }
    
    int as2=1;
    while ((ch2=fgetc(tempLog12))!=EOF){
        if (temp2 != line2){
            putc(ch2, dummyFile2);
        }
        else if(temp2 == line2 && as2 == 1)
        {
            fprintf(dummyFile2, "%d %s %s %d %s %d %s", pId, pFirstNameUpdated, pLastNameUpdated, pAgeUpdated, pDiesaseUpdated, pCovidStatusUpdated, "\n");
            as2++;
        }
        
        if (ch2 == '\n'){
                temp2++;
        }
    }

    fclose(tempLog12);
    fclose(dummyFile2);
    remove("HospitalRecord.txt");
    rename("DummyFile2.txt", "HospitalRecord.txt");     
    
    fflush(stdin);
}

#endif