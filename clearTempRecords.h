#ifndef CLEARTEMPRECORDS_H
#define CLEARTEMPRECORDS_H

void clearTemporaryRecords(){
    FILE* tempFile;
    tempFile = fopen("TemporaryRecord.txt", "w");
    fclose(tempFile);
}

#endif