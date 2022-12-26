#include<stdio.h>
#include<math.h>

int main (){

    int n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);

    float arr[n][n+1];
    printf("Enter teh values of x: ");
    for( int i=0 ; i<n ; i++ ){
        scanf("%f",&arr[i][0]);
    }

    printf("Enter the values of y: ");
    for( int i=0 ; i<n ; i++ ){
        scanf("%f",&arr[i][1]);
    }

    float x;
    printf("Enter the value of x for which you want y: ");
    scanf("%f",&x);

    for( int j=2 ; j<n+1 ; j++ ){
        for( int i=0 ; i<n-j+1 ; i++ ){
            arr[i][j] = arr[i+1][j-1]-arr[i][j-1];
        }
    }

    printf("Difference Table:\n\n");
    for( int i=0 ; i<n+1 ; i++ ){
        for( int j=0 ; j<n-i+1 ; j++ ){
            printf("%0.3f ",arr[i][j]);
        }
        printf("\n");
    }

    float u1,u,y;

    u = (x-arr[0][0])/(arr[1][0]-arr[0][0]);
    y = arr[0][1];
    u1 = u;
    int fact=1;
    for( int i=2; i<=n ; i++ ){
        y = y + (u1*arr[0][i])/fact;
        fact = fact*i;
        u1 = u1*(u-(i-1));
    }

    printf("Value at x = %f of y = %f\n",x,y);

    return 0;
}