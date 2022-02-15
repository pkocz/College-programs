#include <stdlib.h>
#include <stdio.h>
#include "MatrixOperations.h"

int readMatrix(FILE *wp, char *name, int n, double M[n][n])
{
    if(fscanf(wp, "%s", name) != 1)
        return 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if(fscanf(wp, "%lf", &M[i][j]) != 1)
                return 0;
    }
    
    return 1;
}

int writeMatrix(FILE *wp, char *name, int n, double M[n][n])
{

    fprintf(wp, "%s \n", name);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            if(fprintf(wp,"%lf ",M[i][j]) < 0)
                return 0;
        fprintf(wp,"\n");
    }

    return 1;
}

int readVector(FILE *wp, char *name, int n, double V[n])
{
    if(fscanf(wp, "%s", name) != 1)
        return 0;

    for (int j = 0; j < n; ++j)
        if(fscanf(wp, "%lf", &V[j]) != 1)
            return 0;

    return 1;
}

int writeVector(FILE *wp, char *name, int n, double V[n])
{
    fprintf(wp, "%s \n", name);

    for(int i=0; i<n; i++)
    {
        if(fprintf(wp,"%lf ",V[i]) < 0)
            return 0;
        fprintf(wp,"\n");
    }  

    return 1;
}
int readNumber(FILE *wp, char *name, double *c)
{
    if(fscanf(wp, "%s", name) != 1)
        return 0;
    
    if(fscanf(wp, "%lf", c) != 1)
        return 0;

    return 1;
}

int writeNumber(FILE *wp, char *name, double c)
{
    fprintf(wp, "%s \n", name);
    if(fprintf(wp,"%lf \n", c) < 0)
        return 0;

    return 1;
}

void transposeMatrix(int n, double M[n][n], double MT[n][n])
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            MT[j][i] = M[i][j];
}

void addMatrices(int n, double A[n][n], double B[n][n], double C[n][n])
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
}
void subtractMatrices(int n, double A[n][n], double B[n][n], double C[n][n])
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
}

void multiplyMatrices(int n, double A[n][n], double B[n][n], double C[n][n])
{
    int i,j,k;
    double sum;
    
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j){
                sum = 0.0;
                for (k = 0; k < n; ++k)
                    sum += A[i][k]*B[k][j];
            C[i][j] = sum;
            }
}
void multipluMatrixVector(int n, double A[n][n], double V[n], double W[n])
{
    int i,j;

    for (i = 0; i < n ; ++i)
        for (j = 0; j < n; ++j)
            W[j] += A[j][i] * V[i];
}
void multiplyNumberMatrix(int n, double c, double A[n][n], double B[n][n])
{
    int i,j;

    for (i = 0; i < n ; ++i)
        for (j = 0; j < n; ++j)
            B[i][j] = A[i][j] * c;
}