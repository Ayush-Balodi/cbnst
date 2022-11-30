#include<stdio.h>
#include<math.h>

float func( int n ){
    return (float)1/(1+n*n);
}

int main (){

    int ul , ll; // upperlimit , lowerlimit
    printf("Enter the upper and lower limit : ");
    scanf("%d %d",&ul,&ll);

    int h; // difference among values
    printf("Enter the value of the difference : ");
    scanf("%d",&h);

    int n=(ul-ll)/h;

    float arr[n+1] ,sum1=0.0 , sum2=0.0 , sum3=0.0;
    for( int i=0 ; i<=n ; i++ ){
        
        arr[i] = func(i);
        
        if( i==0 || i==n ){
            sum1 += arr[i];
            continue;
        }
        if( i%3 == 0 ){
            sum2 += arr[i];
        }
        else{
            sum3 += arr[i];
        }
    }

    // printf("%f %f %f",sum1,sum2,sum3);

    for( int i=0 ; i<=n ; i++ ){
        printf("arr[%d] = %f\n",i,arr[i]);
    }

    float ans = (float)(3*(sum1 + 2*sum2 + 3*sum3))/8; 

    printf("Answer is : %f",ans);
    return 0;
}