#include <mpi.h>
#include <stdio.h>
#define MASTER 0        /* task ID of master task */

int main (int argc, char *argv[])
{
    float x[100],
	  y[100],
	  a,
	  homes,
	  homet,
 	  homek,
	  sumk;
    int n,i,j,d=1;
    int	taskid,	        /* task ID - also used as seed number */
	numtasks,
	iterations,       /* number of tasks */
	rc;             /* return code */

    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
    
    if (taskid == MASTER) {
        printf("\n\n Enter the number of the terms of the table: ");
        scanf("%d",&n);
        printf("\n\n Enter the respective values of the variables x and y: \n");
        for(i=0; i<n; i++)
        {
            scanf ("%f",&x[i]);
            scanf("%f",&y[i]);
        }
        printf("\n\n The table you entered is as follows :\n\n");
        for(i=0; i<n; i++)
        {
            printf("%0.3f\t%0.3f",x[i],y[i]);
            printf("\n");
        }

	printf(" \n\n\n Enter the value of the x to find the respective value of y\n\n\n");
        scanf("%f",&a);

	MPI_Barrier(MPI_COMM_WORLD);	
	MPI_Bcast(&x, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&y, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
	MPI_Bcast(&a, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
    }
    //while(d==1)
    //{
        
	iterations = n/numtasks + 1;
	
 	homek=0,
	sumk=0;

        for(i=taskid; i<iterations; i +=  numtasks)
        {
	   homes=1;
	   homet=1;
	   if(i<n){
            	for(j=0; j<n; j++)
            	{
                    if(j!=i)
                    {
                    	homes=homes*(a-x[j]);
                    	homet=homet*(x[i]-x[j]);
                    }
                }
            	homek+=((homes/homet)*y[i]);
	    }
        }

	MPI_Reduce(&homek, &sumk, 1, MPI_FLOAT, MPI_SUM, MASTER, MPI_COMM_WORLD);
	if (taskid == MASTER) {
 	    printf("\n\n The respective value of the variable y is: %f\n",sumk);
	}
	return MPI_Finalize();   
    //}
}
