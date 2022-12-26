#include<stdio.h>
#include<math.h>

#define EPSILON 0.0001

float bisect( float x1, float x2 ){
    return (x1+x2)/2;
}

float func( float x ){
    float res = (x*x*x - 2*x - 5);
    return res;
}

int main (){

    int n;
    printf("Enter the maimum number of iterations: ");
    scanf("%d",&n);

    float x1 , x2, x3, x;
    do{
        printf("Enter the valus of x1 and x2: ");
        scanf("%f %f",&x1,&x2);

        if( func(x1)*func(x2) > 0 ){
            printf("Roots are invalid.\n");
        }
        else{
            printf("Roots are valid.\n");
            break;
        }
    }while(1);

    int i=0;
    /*When the number of iterations are restricted*/
    // while( n-- ){ 
    //     x=bisect(x1,x2);
    //     if( func(x)*func(x1) < 0 ){
    //         x2=x;
    //     }
    //     else if( func(x)*func(x2) ){
    //         x1=x;
    //     }
    //     printf("Iteration is %d : x1 = %f and x2 : %f\n",(i+1),x1,x2);
    //     i++;
    // }

    /*when asked for the specific point values*/
    x = bisect(x1,x2);
    do{
        if( func(x)*func(x1) < 0 ){
            x2=x;
        }
        else if( func(x)*func(x2) ){
            x1=x;
        }
        printf("Root is : %f and iteration is %d\n",x,(i+1));
        x3 = bisect(x1,x2);
        if( fabs(x-x3) < EPSILON ){
            printf("Root : %f and iteration is : %d\n",x,(i+1));
            break;
        }
        x=x3;
        i++;
    }while(i<=n);

    printf("Result is : %f and iteration is : %d\n",x,i+1);
    return 0;
}