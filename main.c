#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "addPatientDetails.h"

//global variable to assign pId's to the new patients
int autoPId;

void onExit(){
    FILE* writeAutoPId;
    writeAutoPId = fopen("autoPIdStatus.txt", "w");
    fprintf(writeAutoPId, "%d", autoPId);
    fclose(writeAutoPId);

}


int main(){
    int userChoice;
    do{
        printf("\n1. Add Patient Entry");
        printf("\n2. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &userChoice);

        switch(userChoice){
            case 1:
                addPatientDetails();
            break;
            case 2:
                onExit();
        }

    }while(userChoice != 2);
}