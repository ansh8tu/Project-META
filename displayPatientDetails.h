#ifndef DISPLAYPATIENTDEILS_H
#define DISPLAYPATIENTDEILS_H

void displayRecordForPatient(int pId){
    char ch = 'a';
    int i=0;
    int flag = 0;
    char storePId[4];
    char storeLine[100];

    FILE* tempLog;
    FILE* tempLog1;
    tempLog = fopen("HospitalRecord.txt","r");
    tempLog1 = fopen("HospitalRecord.txt","r");

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
            int j;
            sscanf(storePId, "%d", &j);
            if(j == pId){
                flag = 1;
                break;
            }
            line++;
        }
    }

    int it =0;
    while ((ch=fgetc(tempLog1))!=EOF){
        if (temp == line){
            storeLine[it] = ch;
            it++;
        }
        if (ch == '\n'){
            temp++;
        }
    }

    //if patient-id is not found in records
    int varForSpaces = 1;
    if(flag == 0){
        printf("\n");
        printf("Sorry P-ID: %d, doesn't exist!", pId);
        printf("\n");
    }
    else{
        printf("\n\t--------------------------------------------");
        printf("\n\n\t\tP-ID: ");
        for(int i=0; i<=it; i++){
            if(storeLine[i] == ' ' && varForSpaces == 1){
                varForSpaces++;
                printf("\n\t\tFirst Name: ");
            }else if(storeLine[i] == ' ' && varForSpaces == 2){
                varForSpaces++;
                printf("\n\t\tLast Name: ");
            }else if(storeLine[i] == ' ' && varForSpaces == 3){
                varForSpaces++;
                printf("\n\t\tAge: ");
            }else if(storeLine[i] == ' ' && varForSpaces == 4){
                varForSpaces++;
                printf("\n\t\tDisease: ");
            }else if(storeLine[i] == ' ' && varForSpaces == 5){
                varForSpaces++;
                printf("\n\t\tCovid-Status: ");
            }else{
                printf("%c", storeLine[i]);
            }
        }
        printf("\n\t--------------------------------------------");
        printf("\n\nP-Id: %d details has been successfully displayed!", pId);
        printf("\n");
    }

    fclose(tempLog);
    fclose(tempLog1);
}

#endif