#ifndef ACTIVECOUNTOFCOVIDCASES_H
#define ACTIVECOUNTOFCOVIDCASES_H

extern int autoPId; 

int activeCountOfCovidPatients(){
    int CovidPatientCount = 0;
    char ch = 'a';
    FILE* tempLog;
    tempLog = fopen("TemporaryRecord.txt","r");
    char storeLine[100];

    int it =0;
    int varForSpaces = 1;
    char *ptr;
    
    while((ch=fgetc(tempLog))!=EOF) {
        
        storeLine[it] = ch;
        it++;
        if(ch=='\n'){
            varForSpaces=1;
            for(int i=0; i<=it; i++){
            if(storeLine[i] == ' '){
                varForSpaces++;
            }else if(varForSpaces == 6){
                varForSpaces++;
                if(storeLine[i]=='1')
                {
                    CovidPatientCount++;        
                }
            }else{}
            }
            it=0;
                        
        }
            
    }

    printf("\nThe number of active covid patients currently in Hospital are : %d \n", CovidPatientCount);
    fclose(tempLog);
    
    return CovidPatientCount;
}

#endif