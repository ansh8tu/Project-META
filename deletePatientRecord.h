#ifndef DELETEPATIENTRECORD_H
#define DELETEPATIENTRECORD_H

void deleteRecordFromTemporaryFile(int pId){
    char ch = 'a';
    int i=0;
    char storePId[4];

    FILE* tempLog;
    tempLog = fopen("TemporaryRecord.txt","r");

    while((ch=fgetc(tempLog))!=EOF) {
        if(i<4){
            storePId[i] = ch;
        }

        i++;

        if(ch=='\n'){
            i=0;
            int j;
            sscanf(storePId, "%d", &j);
            printf("\npid = %d",j);
        }

    }

}

#endif