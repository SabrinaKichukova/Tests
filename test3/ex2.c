#include<stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include<errno.h>


int main(int argc, char** argv){

    int opt;

    while ((opt = getopt(argc, argv, "-BT:-TB")) != -1)
        switch (opt){
    
            case '--BT':
            FILE* fp = fopen(argv[1],"r");
            if(NULL == fp){
            perror("Error: \n");
            return EXIT_FAILURE
            }

            FILE* fp1 = fopen(argv[2],"w");
            if(NULL == fp1){
            perror("Error: \n");
            return EXIT_FAILURE
            }

            int ch;
            while(fread(ch, sizeof(int),1,fp) != 0){
            fputs(ch,fp1);
            }
            fclose(fp);
            fclose(fp1);
            break;

            case '-TB':
            FILE* fp = fopen(argv[1],"r");
            if(NULL == fp){
            perror("Error: \n");
            return EXIT_FAILURE
            }
            
            FILE* fp1 = fopen(argv[2],"w");
            if(NULL == fp1){
            perror("Error: \n");
            return EXIT_FAILURE
            }
            short ch;
            while((ch = fgetc(fp) != EOF){
            fwrite(ch,sizeof(int),1,fp1);
            }
            fclose(fp);
            fclose(fp1);
            break;

            case '?':

                fprintf(stderr," No such option!\n");

                break;  

            case ':':

                fprintf(stderr,"Missing argument!\n");

                break;  
        }

    
    return EXIT_SUCCESS;
}