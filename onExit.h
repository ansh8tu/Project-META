#ifndef ONEXIT_H
#define ONEXIT_H


void onExit(){
    FILE* writeAutoPId;
    writeAutoPId = fopen("autoPIdStatus.txt", "w");
    fprintf(writeAutoPId, "%d", autoPId);
    fclose(writeAutoPId);

}

#endif