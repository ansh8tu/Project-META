#ifndef DELETEPATIENTRECORD_H
#define DELETEPATIENTRECORD_H

void deleteRecordFromTemporaryFile(int pId){
    char ch = 'a';
    int i=0;
    int flag = 0;
    char storePId[4];

    FILE* tempLog;
    FILE* tempLog1;
    FILE* dummyFile;

    tempLog = fopen("TemporaryRecord.txt","r");
    tempLog1 = fopen("TemporaryRecord.txt","r");
    dummyFile = fopen("DummyFile.txt", "a+");

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

    //if patient-id is not found in records 
    if(flag == 0){
        printf("\n");
        printf("Sorry P-ID: %d, doesn't exist!", pId);
        printf("\n");
    }
    else{
        printf("\n");
        printf("P-Id: %d has been successfully discharged from the hospital!", pId);
        printf("\n");
    }

    while ((ch=fgetc(tempLog1))!=EOF){
        if (temp != line){
            putc(ch, dummyFile);
        }
        if (ch == '\n'){
                temp++;
        }
    }

    fclose(tempLog);
    fclose(tempLog1);
    fclose(dummyFile);
    remove("TemporaryRecord.txt");
    rename("DummyFile.txt", "TemporaryRecord.txt");
}

#endif