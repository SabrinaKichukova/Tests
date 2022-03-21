/*
Author: Sabrina Kichukova
Purpose: This program calculate the Volume of Cylinder
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int cylinder(double, double, double*, double*, double*);

int main()
{
    double V = 0.0;
    double S1 = 0.0;
    double S = 0.0;
    double r,h;

    printf("Please, enter r and h:\n");
    while (scanf("%lf %lf",&r,&h)!=EOF){

    if (cylinder(h, r,&V ,&S,&S1)==0){
    
    printf("The volume is: %.2lf\n",V);
    printf("The aria is: %.2lf\n",S);
    printf("The S1 is: %.2lf\n",S1);
    }
   
    else {
        
        fprintf(stderr,"\n Error! Invalid input data!\n");
        return -1;
    }

 }

    return EXIT_SUCCESS;
}
int cylinder(double r, double h, double* V, double* S, double* S1){

    double const PI = 3.14;

     if ((r<0) || (h<0)){
       return -1;
    }
    else {
    *V = PI*r*r*h;
    *S1 = 2*PI*r*(r+h);
    *S = PI*r*r;
     return 0;
    }
}