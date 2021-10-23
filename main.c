#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "addPatientDetails.h"
#include "onExit.h"

//global variable to assign pId's to the new patients
int autoPId;

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