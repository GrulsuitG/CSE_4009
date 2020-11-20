//2016025205

/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N]){
	 int i, j, k,l, index;
	 int temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8;
	
	
	if(M ==32 && N== 32){
	
		for (i = 0; i < N; i += 8) {
		    for (j = 0; j < M; j+=8) {
		        for(k = j; k<j+8; k++) {
		        	for(l =i; l<i+8; l++){
		        		if(l != k)
		        			B[l][k] = A[k][l];
		    			else{
		    				temp1 = A[k][l];
		    				index =k;
		    			}    		  
		        	}
		        	if(i == j)
		        		B[index][index] = temp1;

		        }
		   	} 
		}
    }
    else if(M==64 && N ==64){
 
		for (i = 0; i < N; i += 4) {
		      for (j = 60; j >= 0; j-=4){
		      	temp1 = A[i][j];
		      	temp2= A[i][j+1];
		      	temp3 = A[i][j+2];
		      	temp4 = A[i][j+3];
		      	temp5= A[i+1][j];
		      	temp6= A[i+1][j+1];
		      	temp7= A[i+1][j+2];
		      	temp8 = A[i+1][j+3];

		      	B[j][i] = temp1;
		      	B[j][i+1] = temp5;
		      	B[j][i+2] = A[i+2][j];
		      	B[j][i+3] = A[i+3][j];
		      	
		      	B[j+1][i] =temp2;
		      	B[j+1][i+1] = temp6;
		      	B[j+1][i+2] = A[i+2][j+1];
		      	B[j+1][i+3] = A[i+3][j+1];
		      	
		      	temp1 = A[i+2][j+2];
		      	temp2 = A[i+2][j+3];
		      	temp5 = A[i+3][j+2];
		      	temp6 = A[i+3][j+3];
		      	
		      	B[j+2][i] = temp3;
		      	B[j+2][i+1] =temp7;
		      	B[j+2][i+2] = temp1;
		      	B[j+2][i+3] = temp5;
		      	
		      	
		      	B[j+3][i] = temp4;
		      	B[j+3][i+1] = temp8;
		      	B[j+3][i+2] = temp2;
		      	B[j+3][i+3] = temp6;
		      	
		      	
				
				
		        
		   	} 
		}
    }
    else{
		for (i = 0; i < M; i += 16) {
		    for (j = 0; j < N; j+=16) {
		        for(k = j; (k<j+16) && (k < N); k++) {
		        	for(l =i; (l<i+16) && (l < M); l++){
		        		if(l != k)
		        			B[l][k] = A[k][l];
		    			else{
		    				temp1 = A[k][l];
		    				index =k;
		    			}    		  
		        	}
		        	if(i == j)
		        		B[index][index] = temp1;

		        }
		   	} 
		}
    }   

}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
     int i, j;
	 int temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8;
	
		for (i = 60; i >= 0; i -= 4) {
		     for (j = 0; j <= M; j+=4) {
		      	temp1 = A[i][j];
		      	temp2= A[i][j+1];
		      	temp3 = A[i][j+2];
		      	temp4 = A[i][j+3];
		      	temp5= A[i+1][j];
		      	temp6= A[i+1][j+1];
		      	temp7= A[i+1][j+2];
		      	temp8 = A[i+1][j+3];

		      	B[j][i] = temp1;
		      	B[j][i+1] = temp5;
		      	B[j][i+2] = A[i+2][j];
		      	B[j][i+3] = A[i+3][j];
		      	
		      	B[j+1][i] =temp2;
		      	B[j+1][i+1] = temp6;
		      	B[j+1][i+2] = A[i+2][j+1];
		      	B[j+1][i+3] = A[i+3][j+1];
		      	
		      	temp1 = A[i+2][j+2];
		      	temp2 = A[i+2][j+3];
		      	temp5 = A[i+3][j+2];
		      	temp6 = A[i+3][j+3];
		      	
		      	B[j+2][i] = temp3;
		      	B[j+2][i+1] =temp7;
		      	B[j+2][i+2] = temp1;
		      	B[j+2][i+3] = temp5;
		      	
		      	
		      	B[j+3][i] = temp4;
		      	B[j+3][i+1] = temp8;
		      	B[j+3][i+2] = temp2;
		      	B[j+3][i+3] = temp6;
		      	
		      	
		      	
		      	
		      
		      	
		      
				
				
		        
		   	} 
		}

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

