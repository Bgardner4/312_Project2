/* Project2.cpp
 * Ima Student
 * EE312, Summer 2017
 * Project 2, Matrix Multiplication
 */

#include "header.c"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "MatrixMultiply.h"

void multiplyMatrices(
        double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {
    // https://en.wikipedia.org/wiki/Row-_and_column-major_order

    for(uint32_t m = 0; m < a_rows; m++){        //selects the row of matrix A
        for(uint32_t k = 0; k < b_cols; k++){    //selects the column of matrix B
            double element = 0;
            for(uint32_t n = 0; n < a_cols; n++){        //selects column of A and Row of B
                element += (a[m * a_cols + n] * b[n * b_cols + k]);
            }
            //printf("%f\n",element);
            c[m * a_rows + k] = element;
        }
    }
}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {

    double ** c = (double **)malloc(a_rows * sizeof(double *));      //create array pointing to rows c
    for(uint32_t m = 0; m < a_rows; m++){
        c[m] = (double *)malloc(b_cols * sizeof(double));           //allocate k columns for each row
    }

    for(uint32_t m = 0; m < a_rows; m++){        //selects the row of matrix A
        for(uint32_t k = 0; k < b_cols; k++){    //selects the column of matrix B
            double element = 0;
            for(uint32_t n = 0; n < a_cols; n++){        //selects column of A and Row of B
                element += (a[m][n] * b[n][k]);
            }
            c[m][k] = element;
        }
    }

    return c;
}

// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix(
         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols) {

    double** b = (double**)malloc(a_cols * sizeof(double*));    //generate a matrix B with columns equal to matrix A rows
    for(uint32_t n = 0; n < a_cols; n++){
        b[n] = (double*)malloc(a_rows * sizeof(double));
    }

    for(uint32_t m = 0; m < a_rows; m++){           // flip coordinates to transpose matrix
        for(uint32_t n = 0; n < a_cols; n++){
            b[n][m] = a[m][n];
        }
    }

    return b;
}
