#include <stdio.h>
#include <mpi.h>
#define MAXN 100
#define ORDER 4
#define MASTER 0

int main(int argc, char *argv[])
{
    float ax[MAXN + 1], ay[MAXN + 1], diff[(MAXN + 1) * (ORDER + 1)], nr = 1.0, dr = 1.0, x, p, h, yp;
    int n, i, j, k;
    int taskid, /* task ID - also used as seed number */
        numtasks,
        stride, /* number of tasks */
        rc;     /* return code */

    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &taskid);

    if (taskid == MASTER)
    {

        printf("\nEnter the value of n:\n");
        scanf("%d", &n);

        printf("\nEnter the values in form x,y:\n");
        for (i = 0; i <= n; i++)
            scanf("%f %f", &ax[i], &ay[i]);
        printf("\nEnter the value of x for which the value of y is wanted: \n");
        scanf("%f", &x);
        h = ax[1] - ax[0];

        MPI_Barrier(MPI_COMM_WORLD);
        MPI_Bcast(&ax, MAXN + 1, MPI_FLOAT, MASTER, MPI_COMM_WORLD);
        MPI_Bcast(&ay, MAXN + 1, MPI_FLOAT, MASTER, MPI_COMM_WORLD);
        MPI_Bcast(&h, MAXN + 1, MPI_FLOAT, MASTER, MPI_COMM_WORLD);
    }

    for (i = taskid + 1; i <= n; i += numtasks)
    {
        diff[i + 1 * (MAXN + 1)] = ay[i + 1] - ay[i];
    }

    for (j = taskid + 2; j <= ORDER; j += numtasks)
        for (i = 0; i <= n - j; i++)
            diff[i + j * (MAXN + 1)] = diff[(i + 1) + (j - 1) * (MAXN + 1)] - diff[i + (j - 1) * (MAXN + 1)];

    if (taskid == MASTER)
    {
        i = 0;
        while (!(ax[i] > x))
            i++;

        //now ax[i] is x0 and ay[i] is y0
        i--;
        p = (x - ax[i]) / h;
        yp = ay[i];
    }

    MPI_Barrier(MPI_COMM_WORLD);

    //now carrying out interpolation
    for (k = taskid+1; k <= ORDER; k+=numtasks)
    {
        nr *= p - k + 1;
        dr *= k;
        yp += (nr / dr) * diff[i + (MAXN + 1) * k];
    }

    if (taskid == MASTER)
    {
        printf("\nWhen x = %6.1f, corresponding y = %6.2f\n", x, yp);
    }

    return MPI_Finalize();
}