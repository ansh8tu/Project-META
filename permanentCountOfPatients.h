#ifndef PERMANENTCOUNTOFPATIENTS_H
#define PERMANENTCOUNTOFPATIENTS_H

extern int autoPId; 

void displayNumberOfRecords(){
    int totalRecords = autoPId;
    int numberOfTotalPatients = totalRecords - 1000;
    printf("\nTotal number of patients in Hospital Records: %d\n", numberOfTotalPatients);
}

#endif