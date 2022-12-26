#include<stdio.h>
#include<math.h>

#define EPSILON 0.0001

float func( float x ){
    return (x*x*x-2*x-5);
}

float bisect( float x1, float x2 ){
    return (x1*func(x2)-x2*func(x1))/(func(x2)-func(x1));
}

int main (){
    
    int n;
    printf("Enter the maximum number of interactions: ");
    scanf("%d",&n);

    float x1, x2 , x3 , x;

    do{
        printf("Enter the value of x1 and x2 : ");
        scanf("%f %f",&x1,&x2);

        if( func(x1)*func(x2) < 0 ){
            printf("Roots are valid.\n");
            break;
        }
        else{
            printf("Roots are invalid.\n");
        }
    }while(1);

    int i=0;
    /*when the number of iterations are provided*/
    // while( n-- ){
    //     x=bisect( x1 , x2 );
    //     if( func(x) * func(x2) < 0 ){
    //         x2=x;
    //     }
    //     else if( func(x) * func(x1) < 0 ){
    //         x1=x;
    //     }
    //     printf("Root is : %f and iteration is : %d\n",x,(i+1));
    //     i++;
    // }

    /*when the number of point values are provided*/
    x = bisect(x1,x2);
    do{
        if( func(x)*func(x1) < 0 ){
            x2=x;
        }
        else if( func(x)*func(x2) ){
            x1=x;
        }
        printf("Root is : %f and iteration is : %d\n",x,(i+1));
        x3 = bisect(x1,x2);
        if( fabs(x3-x) < EPSILON ){
            printf("Root is : %f and iteration is : %d\n",x,(i+1));
            break;
        }
        x=x3;
        i++;
    }while(i<=n);

    printf("Result root is : %f @ iteration : %d",x,(i+1));
    return 0;
}