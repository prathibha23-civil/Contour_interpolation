#include <stdio.h>
#include <math.h>
#define MAX 20
#define EPS 1e-6
/* Function to display the RL grid */
void displayGrid(double rl[MAX][MAX], int rows, int cols)
{
    int i, j;
    printf("\nReduced Levels (m):\n\n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%8.2f ", rl[i][j]);
        }
        printf("\n");
    }
}
/* Function to check whether a point is already stored */
int isDuplicate(double contour, double x, double y,
                double contours[], double xs[], double ys[],
                int count)
{
    int i;
    for(i = 0; i < count; i++)
    {
        if(fabs(contours[i] - contour) < EPS &&
           fabs(xs[i] - x) < EPS &&
           fabs(ys[i] - y) < EPS)
        {
            return 1;
        }
    }
    return 0;
}
/* Function to add a new contour point */
int addPoint(double contour, double x, double y,
             double contours[], double xs[], double ys[],
             int count)
{
    if(!isDuplicate(contour, x, y,                                       
                    contours, xs, ys, count))
    {
        contours[count] = contour;
        xs[count] = x;
        ys[count] = y;
        return count + 1;
    }
    return count;
}
/* Function to interpolate contour point between two grid points */
int interpolate(double x1, double y1, double z1,
                double x2, double y2, double z2,
                double contour,
                double contours[], double xs[], double ys[],
                int count)
{
    double t, x, y;
    /* If both RLs are equal, no interpolation is required */
    if(fabs(z2 - z1) < EPS)
        return count;
    /* Check whether contour lies between the two RLs */
    if((contour >= z1 && contour <= z2) ||
       (contour >= z2 && contour <= z1))
    {
        /* Linear interpolation */
        t = (contour - z1) / (z2 - z1);
        x = x1 + t * (x2 - x1);
        y = y1 + t * (y2 - y1);
        count = addPoint(contour, x, y,
                         contours, xs, ys, count);
    }
    return count;
}
/* Function to find contour interpolation points */
void findContours(double rl[MAX][MAX],
                  int rows, int cols,
                  double dx, double dy,
                  double minRL, double maxRL,
                  double contourInterval)
{
    double contours[MAX * MAX * 10];
    double xs[MAX * MAX * 10];
    double ys[MAX * MAX * 10];
    int count = 0;
    int i, j;
    int c;
    double contour;
    double firstContour;
    /*
       Find the first contour value which is
       equal to or greater than minimum RL
    */
    firstContour =
        ceil((minRL - EPS) / contourInterval)
        * contourInterval;
    /*
       Process each contour
    */
    for(contour = firstContour;
        contour <= maxRL + EPS;
        contour += contourInterval)
    {
        /*
           Check horizontal grid edges
        */
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols - 1; j++)
            {
                count = interpolate(
                    j * dx,
                    i * dy,
                    rl[i][j],
                    (j + 1) * dx,
                    i * dy,
                    rl[i][j + 1],
                    contour,
                    contours,
                    xs,
                    ys,
                    count
                );
            }
        }
        /*
           Check vertical grid edges
        */
        for(i = 0; i < rows - 1; i++)
        {
            for(j = 0; j < cols; j++)
            {
                count = interpolate(
                    j * dx,
                    i * dy,
                    rl[i][j],
                    j * dx,
                    (i + 1) * dy,
                    rl[i + 1][j],
                    contour,
                    contours,
                    xs,
                    ys,
                    count
                );
            }
        }
    }
    /*
       Display final contour points
    */
    printf("\nContour Interpolation Points:\n");
    printf("------------------------------------------\n");

    for(c = 0; c < count; c++)
    {
        printf("Contour %.2f m : "
               "Interpolation Point (%.2f, %.2f)\n",
               contours[c],
               xs[c],
               ys[c]);
    }
}
/* Main function */
int main()
{
    double rl[MAX][MAX];
    int rows, cols;
    int i, j;
    double dx, dy;
    double contourInterval;
    double minRL, maxRL;
    printf("CONTOUR INTERPOLATION FROM GRID LEVELLING\n");
    printf("==========================================\n");
    /* Input number of rows and columns */
    printf("\nEnter number of rows (max %d): ", MAX);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX);
    scanf("%d", &cols);
    /* Validate grid size */
    if(rows < 2 || cols < 2 ||
       rows > MAX || cols > MAX)
    {
        printf("\nInvalid grid size.\n");
        return 1;
    }
    /* Input grid spacing */
    printf("\nEnter grid spacing in X direction (m): ");
    scanf("%lf", &dx);
    printf("Enter grid spacing in Y direction (m): ");
    scanf("%lf", &dy);
    if(dx <= 0 || dy <= 0)
    {
        printf("\nGrid spacing must be positive.\n");
        return 1;
    }
    /* Input RL values */
    printf("\nEnter Reduced Levels at grid points:\n");
    minRL = 1e9;
    maxRL = -1e9;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("RL[%d][%d] = ", i + 1, j + 1);
            scanf("%lf", &rl[i][j]);
            if(rl[i][j] < minRL)
                minRL = rl[i][j];
            if(rl[i][j] > maxRL)
                maxRL = rl[i][j];
        }
    }
    /* Input contour interval */
    printf("\nEnter contour interval (m): ");
    scanf("%lf", &contourInterval);
    if(contourInterval <= 0)
    {
        printf("\nContour interval must be positive.\n");
        return 1;
    }
    /* Display RL grid */
    displayGrid(rl, rows, cols);
    /* Display minimum and maximum RL */
    printf("\nMinimum RL = %.2f m\n", minRL);
    printf("Maximum RL = %.2f m\n", maxRL);
    printf("Contour Interval = %.2f m\n",
           contourInterval);
    /* Calculate contour interpolation */
    findContours(
        rl,
        rows,
        cols,
        dx,
        dy,
        minRL,
        maxRL,
        contourInterval
    );
    return 0;
}