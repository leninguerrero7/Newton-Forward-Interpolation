#include<stdio.h>
#define MAXN 100
#define ORDER 4
 
int main()
{
    float ax[MAXN+1], ay [MAXN+1], diff[MAXN+1][ORDER+1], nr[ORDER+1], dr[ORDER+1],x,p,h,yp;
    int n,i,j,k;
    printf("\nEnter the value of n:\n");
    scanf("%d",&n);
 
    printf("\nEnter the values in form x,y:\n");
    for (i=0;i<=n;i++)
        scanf("%f %f",&ax[i],&ay[i]);
    printf("\nEnter the value of x for which the value of y is wanted: \n");
    scanf("%f",&x);
    h=ax[1]-ax[0];
 
    //now making the difference table
    //calculating the 1st order of differences
    #pragma omp parallel for private(i) shared(diff)
    for (i=0;i<=n-1;i++)
        diff[i][1] = ay[i+1]-ay[i];
 
    //now calculating the second and higher order differences
    #pragma omp parallel for private(i,j) shared(diff)
    for (j=2;j<=ORDER;j++)
        for(i=0;i<=n-j;i++)
            diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
 
    //now finding x0
    i=0;
    while (!(ax[i]>x))
        i++;
 
    //now ax[i] is x0 and ay[i] is y0
    i--;
    p = (x-ax[i])/h;
    yp = ay[i];
 
    //now carrying out interpolation
    nr[0] = 1.0;
    dr[0] = 1.0;

    for (k=1;k<=ORDER;k++)
    {
        nr[k]=nr[k-1]*(p-k+1);
        dr[k]=dr[k-1]*k;
    }

    #pragma omp parallel for private(k) reduction(+:yp)
    for (k=1;k<=ORDER;k++)
    {
        yp +=(nr[k]/dr[k])*diff[i][k];
    }
    printf("\nWhen x = %6.1f, corresponding y = %6.2f\n",x,yp);
    return 0;
}