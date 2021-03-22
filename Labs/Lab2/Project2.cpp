// matrix-multiplication <Project2.cpp>
// EE 312 Project 2 submission by
// Christian Daniel
// cad4254
// Slip days used: <0>
// Spring 2020

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


            uint32_t currRowA = 0;
            while(currRowA < a_rows){
                uint32_t currColB = 0;



                while(currColB < b_cols){
                    uint32_t currColA = 0;
                    double currSum = 0;

                    while(currColA < a_cols){
                        currSum+= (a[currRowA * a_cols + currColA] * b[currColA * b_cols + currColB]);
                        currColA++;

                    }

                    c[currRowA * b_cols + currColB] = currSum;
                    currColB++;
                }
                currRowA++;
            }
}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {

        double** c;
        c = (double **)malloc(sizeof(double *) * a_rows);
        for (uint32_t i = 0; i < a_rows; i++) {
            *(c + i) = (double *)malloc(sizeof(double) * b_cols);
        }



        
            uint32_t currRowA = 0;
            while(currRowA < a_rows){
                uint32_t currColB = 0;



                while(currColB < b_cols){
                    uint32_t currColA = 0;
                    double currSum = 0;

                    while(currColA < a_cols){
                        currSum += (a[currRowA][currColA] * b[currColA][currColB]);
                        currColA++;

                    }

                    c[currRowA][currColB] = currSum;
                    currColB++;
                }
                currRowA++;
            }

    return c;
}

double** transposeMatrix(

         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols) {

        double** c;
        c = (double **)malloc(sizeof(double *) * a_cols);
        for (uint32_t i = 0; i < a_cols; i++) {
            *(c + i) = (double *)malloc(sizeof(double) * a_rows);
        }

        for(uint32_t i = 0; i < a_rows; i++){
            for(uint32_t j = 0; j < a_cols; j++){
                c[j][i] = a[i][j];
            }
        }

    return c;
}
