#include<stdio.h>
#include<math.h>

// depends on the point of values asked in the problem 
#define EPSILON 0.0001

// function
float func( float x ){
    return pow(x,3)-3*x-5;
}

// differentiation of the function
float diff( float x ){
    return 3*pow(x,2)-3;
}

int main (){

    int n;
    printf("Enter the number of iterations: ");
    scanf("%d",&n);

    float x1, x2 ,x ,x0;
    do{
        printf("Enter the value of x1 and x2(starting boundary): ");
        scanf("%f %f",&x1,&x2);

        if( func(x1)*func(x2) < 0 ){
            printf("Boundary values are valid.\n");
            break;
        }
        else{
            printf("Boundary values are invalid.\n");
        }
    }while(1);
    
    int i=0;
    x0 = (x1+x2)/2;
    do{
        x = x0 - func(x0)/diff(x0);
        if( fabs(x-x0) < EPSILON ){
            printf("Final root is : %f and iteration is : %d\n",x,(i+1));
            return 0;
        }
        printf("Root is : %f and iteration is : %d\n",x,(i+1));
        x0 = x;
        i++;
    }while(i<=n);
    printf("Final root is : %f and iteration is : %d\n",x,(i));
    return 0;
}