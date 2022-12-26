#include<stdio.h>
#include<math.h>

#define EPSILON 0.0001

float func( float x ){
    return (pow(x,3)+pow(x,2)-1);
}

float si( float x ){
    return 1/sqrt(1+x);
}

float si_differentiation( float x ){
    return -1/(2*pow((1+x),3/2.0));
}

int main(){

    int n;
    printf("Enter the maximum number of iterations: ");
    scanf("%d",&n);

    float x1 , x2 , x0, x;
    do{
        printf("Enter the values of xa and x2(starting boundary): ");
        scanf("%f %f",&x1,&x2);

        if( func(x1)*func(x2) < 0 ){
            printf("Boundary values are valid.\n");
            break;
        }
        else{
            printf("Boundary values are invalid.\n");
        }
    }while(1);

    x0 = (x1+x2)/2;
    if( fabs(si_differentiation(x0)) > 1 ){
        printf("Function form is not correct. Iteration method cannot be applied.\n");
        return 0;
    }
    else{
        printf("Function form is correct. Iteration method can be applied.\n");
    }

    int i=0;
    do{
        x = si(x0);
        printf("Root is : %f and iteration : %d\n",x,(i+1));
        if( fabs(x-x0) < EPSILON ){
            printf("Resultant Root is : %f and iteration is : %d\n",x0,(i+2));
            return 0;
        }
        x0 = x;
        i++;
    }while(i<=n);
    printf("Resultant Root is : %f and iteration is : %d\n",x,(i));
    return 0;
}