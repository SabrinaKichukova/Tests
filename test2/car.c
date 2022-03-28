#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define COUNT 10

typedef struct {
    char model[namelen];
    uint8_t  maxspeed;
    double price;
} car;

void printInfo(car);
double randDouble(double, double);
int randInt(int, int);
int compareInt(const void*, const void*);
int compareDInt(const void*, const void*);
int compareDouble(const void* , const void*);
int compareDDouble(const void* , const void*);
int strACompName(const void*, const void*);
int strDCompName(const void*, const void*);
int (*getComparator(int option[7]))(const void*, const void*);




int main(){
    
    srand(time(NULL)); 
    car cars[COUNT];
    int namelen =20;
    for (int i = 0; i < COUNT; i++){    
        cars[i].model[0] = randInt('A', 'Z');
        for (int j = 1; j < namelen; j++){
            cars[i].name[j] = randInt('a', 'z');
        }
        cars[i].model[namelen] = '\0';
        cars[i].maxspeed = randInt(100,300);   
        cars[i].price = randDouble(1000,100000000);   
    }
        
     
        printf("Enter option:\n");
        printf("\n1.Sort by model ascending order:\n");
        printf("\n2.Sort by model descending order:\n");
        printf("\n3.Sort by maxspeed ascending order:\n");
        printf("\n4.Sort by maxspeed descending order:\n");
        printf("\n5.Sort by price ascending order:\n");
        printf("\n6.Sort by price descending order:\n");
        printf("\n7.Information:\n");
        scanf("%d",&option);

        *getComparator[6])(const void*,const void*) = {strACompName,strDCompName,compareInt,compareD,IntcompareDouble,IntcompareDDouble};

            if(option == 1){
               
               qsort( cars, COUNT, sizeof(car), strACompName);
                for (int j = 0; j < COUNT; j++){
                printInfo(cars[j]);
                }
            }    
            if(option == 2){
                
                qsort( cars, COUNT, sizeof(car), strDCompName);
                for (int j = 0; j < COUNT; j++){
                printInfo(cars[j]);
                }
                
            }
            if(option == 3){
                
                 qsort( cars, COUNT, sizeof(car), compareInt);
                for (int j = 0; j < COUNT; j++){
                printInfo(cars[j]);

                }
            }
            if(option == 4){   
                qsort( cars, COUNT, sizeof(car), compareDInt);
                for (int j = 0; j < COUNT; j++){
                printInfo(cars[j]);

                }
            }
            if(option == 5){
                qsort( cars, COUNT, sizeof(car), compareDouble);
                for (int j = 0; j < COUNT; j++){
                printInfo(cars[j]);
            }
            }
            if(option == 6){
                qsort( cars, COUNT, sizeof(car), compareDDouble);
                for (int j = 0; j < COUNT; j++){
                printInfo(cars[j]);
            } 
            }  
            if(option == 7){
        
                for (int j = 0; j < COUNT; j++){
                printInfo(cars[j]);
                } 
            }    

    return 0;
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
int randInt(int min, int max){
    return min + rand() % (max -min + 1); // [min; max]
}
void printInfo(car cars){
   
    printf("Name:   %s,     ", cars.model);
    printf("Pages:  %d,     ", cars.maxspeed);
    printf("Price:  %.2lf\n", cars.price);
}
int strACompName(const void* cars1, const void* cars2){
    car* carn = (car*)cars1;
    car* carm = (car*)cars2;
    char name1 = *carn->name;
    char name2 = *carm->name;

    if (name1 == name2) {
        return 0;
    } else if (name1 < name2){
        return 1;
    } else {
        return -1;
    }

}
int strDCompName(const void* cars1, const void* cars2){
    car* carn = (car*)cars1;
    car* carm = (car*)cars2;
    char name1 = *carn->model;
    char name2 = *carm->model;

    if (name1 == name2) {
        return 0;
    } else if (name1 > name2){
        return 1;
    } else {
        return -1;
    }

}
int compareInt(const void* cars1, const void* cars2){
    car* carn = (car*)cars1;
    car* carm = (car*)cars2;
    char maxspeed1 = *carn->maxspeed;
    char maxspeed2 = *carm->maxspeed;

    if (maxspeed1 == maxspeed2) {
        return 0;
    } else if (maxspeed1 > maxspeed2){
        return 1;
    } else {
        return -1;
    }
}
int compareDInt(const void* cars1, const void* cars2){
    car* carn = (car*)cars1;
    car* carm = (car*)cars2;
    char maxspeed1 = *carn->maxspeed;
    char maxspeed2 = *carm->maxspeed;

    if (maxspeed1 == maxspeed2) {
        return 0;
    } else if (maxspeed1 < maxspeed2){
        return 1;
    } else {
        return -1;
    }
}
int compareDouble(const void* cars1, const void* cars2){
    car* carn = (car*)cars1;
    car* carm = (car*)cars2;
    double price1 = carn->price;
    double price2 = carm->price;

    if ((fabs(price1-price2)) < 0.001) {
        return 0;
    } else if (price1 > price2){
        return 1;
    } else {
        return -1;
    }
}
int compareDDouble(const void* cars1, const void* cars2){
    car* carn = (car*)cars1;
    car* carm = (car*)cars2;
    double price1 = carn->price;
    double price2 = carm->price;

    if ((fabs(price1-price2)) < 0.001) {
        return 0;
    } else if (price1 < price2){
        return 1;
    } else {
        return -1;
    }
}
int (*getComparator(int n))(const void*, const void*){




    
}