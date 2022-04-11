#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

int cmpfunc (const void *, const void *);
pthread_mutex_t mux;

void* func(void* arg)
{   
    pthread_mutex_lock(&mux);
    size_t len = sizeof(arg)/sizeof(arg[1]);
    qsort(arg,len,sizeof(arg),cmpfunc);
    pthread_mutex_unlock(&mux);

    return arg;
}

int main(int argc, char const *argv[])
{   
    pthread_mutex_init(&mux, NULL);
    uint N;
    uint M;
    printf("Please enter N and M:");
    scanf("%d %d", &N, &M);
    int arr[N][M];
    for (int i = 0; i < N; i++)
    {
        for(int j = 0;j < M; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    char* fname;
    printf("Please enter file name:");
    scanf("%s",fname);
        
    pthread_t th[N];

            for (int i = 0; i < N; i++) {
        
                pthread_create(&th[i], NULL, &func, arr[i]);
                pthread_join(th[i], NULL);
                pthread_attr_destroy(th[i]);
            }
            for (int i = 0; i < N; i++) {

                void* retval;
                pthread_join(th[i], &retval);
                FILE* fp = fopen(fname, "w");
                    if (NULL == fp){
                    perror("error");
                    return EXIT_FAILURE;
                    }
                    for(int j = 0; j < sizeof(retval); j++){
                    fprintf(fname, "%d\n",(int)retval[j]);
                    }
                    fclose(fname);

                pthread_attr_destroy(th[i]);
            }
         
             exit(EXIT_SUCCESS);
    return 0;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}