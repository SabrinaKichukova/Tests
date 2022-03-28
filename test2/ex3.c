#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


int main()
{
    int a;
    char output[500];
    scanf("%d",a);

    if(a>500){

        fprintf(stderr,"Not correct digit!");
    }
        sprintf(output, "Num = %d", a);

        for(int i = 0; i<500,i++){

            if (i%2){
                if(output[i] == 0){
                strcpy(output[i],'A')
                } else if (output[i] == 1){
                strcpy(output[i],'B')
                } else if (output[i] == 2){
                strcpy(output[i],'C')
                } else if (output[i] == 3){
                strcpy(output[i],'D')
                } else if (output[i] == 4){
                strcpy(output[i],'E')
                } else if (output[i] == 5){
                strcpy(output[i],'F')
                } else if (output[i] == 6){
                strcpy(output[i],'G')
                } else if (output[i] == 7){
                strcpy(output[i],'H')
                } else if (output[i] == 8){
                strcpy(output[i],'I')
                } else if (output[i] == 9){
                strcpy(output[i],'G')
                }
            } else {
                if(output[i] == 0){
                strcpy(output[i],'!')
                } else if (output[i] == 1){
                strcpy(output[i],'#')
                } else if (output[i] == 2){
                strcpy(output[i],'/')
                } else if (output[i] == 3){
                strcpy(output[i],'~')
                } else if (output[i] == 4){
                strcpy(output[i],'=')
                } else if (output[i] == 5){
                strcpy(output[i],'\'')
                } else if (output[i] == 6){
                strcpy(output[i],'\\')
                } else if (output[i] == 7){
                strcpy(output[i],'>')
                } else if (output[i] == 8){
                strcpy(output[i],'/.')
                } else if (output[i] == 9){
                strcpy(output[i],',')
                }
            }
            
        }   
        printf("%s\n",output);
    
    return 0;
}
