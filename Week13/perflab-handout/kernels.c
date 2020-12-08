/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "Kim Beom Jin",              /* name */

    "2016025205",     /* student ID */
    "User email",  /* student email */

    "",                   /* Second member full name (leave blank if none) */
    ""                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
	   		dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}
char test1_rotate_descr[] = "test1";
void test1_rotate(int dim, pixel *src, pixel *dst){
	int i, j;
	for (i = 0; i < dim; i+=32)
		for (j = 0; j < dim; j++){
	   		dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
	   		dst[RIDX(dim-1-j, i+1, dim)] = src[RIDX(i+1, j, dim)];
	   		dst[RIDX(dim-1-j, i+2, dim)] = src[RIDX(i+2, j, dim)];
	   		dst[RIDX(dim-1-j, i+3, dim)] = src[RIDX(i+3, j, dim)];
	   		dst[RIDX(dim-1-j, i+4, dim)] = src[RIDX(i+4, j, dim)];
	   		dst[RIDX(dim-1-j, i+5, dim)] = src[RIDX(i+5, j, dim)];
	   		dst[RIDX(dim-1-j, i+6, dim)] = src[RIDX(i+6, j, dim)];
	   		dst[RIDX(dim-1-j, i+7, dim)] = src[RIDX(i+7, j, dim)];
	   		dst[RIDX(dim-1-j, i+8, dim)] = src[RIDX(i+8, j, dim)];
	   		dst[RIDX(dim-1-j, i+9, dim)] = src[RIDX(i+9, j, dim)];
	   		dst[RIDX(dim-1-j, i+10, dim)] = src[RIDX(i+10, j, dim)];
	   		dst[RIDX(dim-1-j, i+11, dim)] = src[RIDX(i+11, j, dim)];
	   		dst[RIDX(dim-1-j, i+12, dim)] = src[RIDX(i+12, j, dim)];
	   		dst[RIDX(dim-1-j, i+13, dim)] = src[RIDX(i+13, j, dim)];
	   		dst[RIDX(dim-1-j, i+14, dim)] = src[RIDX(i+14, j, dim)];
	   		dst[RIDX(dim-1-j, i+15, dim)] = src[RIDX(i+15, j, dim)];
	   		dst[RIDX(dim-1-j, i+16, dim)] = src[RIDX(i+16, j, dim)];
	   		dst[RIDX(dim-1-j, i+17, dim)] = src[RIDX(i+17, j, dim)];
	   		dst[RIDX(dim-1-j, i+18, dim)] = src[RIDX(i+18, j, dim)];
	   		dst[RIDX(dim-1-j, i+19, dim)] = src[RIDX(i+19, j, dim)];
	   		dst[RIDX(dim-1-j, i+20, dim)] = src[RIDX(i+20, j, dim)];
	   		dst[RIDX(dim-1-j, i+21, dim)] = src[RIDX(i+21, j, dim)];
	   		dst[RIDX(dim-1-j, i+22, dim)] = src[RIDX(i+22, j, dim)];
	   		dst[RIDX(dim-1-j, i+23, dim)] = src[RIDX(i+23, j, dim)];
	   		dst[RIDX(dim-1-j, i+24, dim)] = src[RIDX(i+24, j, dim)];
	   		dst[RIDX(dim-1-j, i+25, dim)] = src[RIDX(i+25, j, dim)];
	   		dst[RIDX(dim-1-j, i+26, dim)] = src[RIDX(i+26, j, dim)];
	   		dst[RIDX(dim-1-j, i+27, dim)] = src[RIDX(i+27, j, dim)];
	   		dst[RIDX(dim-1-j, i+28, dim)] = src[RIDX(i+28, j, dim)];
	   		dst[RIDX(dim-1-j, i+29, dim)] = src[RIDX(i+29, j, dim)];
	   		dst[RIDX(dim-1-j, i+30, dim)] = src[RIDX(i+30, j, dim)];
	   		dst[RIDX(dim-1-j, i+31, dim)] = src[RIDX(i+31, j, dim)];
	   	}
}

char test2[] = "test2";
void test2_rotate(int dim, pixel *src, pixel *dst){
		int i, j;
	for (i = 0; i < dim; i+=8)
		for (j = 0; j < dim; j++){
	   		dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
	   		dst[RIDX(dim-1-j, i+1, dim)] = src[RIDX(i+1, j, dim)];
	   		dst[RIDX(dim-1-j, i+2, dim)] = src[RIDX(i+2, j, dim)];
	   		dst[RIDX(dim-1-j, i+3, dim)] = src[RIDX(i+3, j, dim)];
	   		dst[RIDX(dim-1-j, i+4, dim)] = src[RIDX(i+4, j, dim)];
	   		dst[RIDX(dim-1-j, i+5, dim)] = src[RIDX(i+5, j, dim)];
	   		dst[RIDX(dim-1-j, i+6, dim)] = src[RIDX(i+6, j, dim)];
	   		dst[RIDX(dim-1-j, i+7, dim)] = src[RIDX(i+7, j, dim)];
	   	}
}

char test3[] = "test3";
void test3_rotate(int dim, pixel *src, pixel *dst){
	 int i, j, k, l, index=0;
	pixel temp1;
	for (i = 0; i < dim; i += 16) {
		    for (j = 0; j < dim; j+=16) {
		        for(k = j; k<j+16; k++) {
		        	for(l =i; l<i+16; l++){
		        		if(l != k)
		        			dst[RIDX(dim-1-l,k,dim)] = src[RIDX(k,l,dim)];
		    			else{
		    				temp1 = src[RIDX(k,l,dim)];
		    				index =k;
		    			}    		  
		        	}
		        	if(i == j)
		        		dst[RIDX(dim-1-index,index,dim)] = temp1;

		        }
		   	} 
		}
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;
	for (i = 0; i < dim; i+=32)
		for (j = 0; j < dim; j++){
	   		dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
	   		dst[RIDX(dim-1-j, i+1, dim)] = src[RIDX(i+1, j, dim)];
	   		dst[RIDX(dim-1-j, i+2, dim)] = src[RIDX(i+2, j, dim)];
	   		dst[RIDX(dim-1-j, i+3, dim)] = src[RIDX(i+3, j, dim)];
	   		dst[RIDX(dim-1-j, i+4, dim)] = src[RIDX(i+4, j, dim)];
	   		dst[RIDX(dim-1-j, i+5, dim)] = src[RIDX(i+5, j, dim)];
	   		dst[RIDX(dim-1-j, i+6, dim)] = src[RIDX(i+6, j, dim)];
	   		dst[RIDX(dim-1-j, i+7, dim)] = src[RIDX(i+7, j, dim)];
	   		dst[RIDX(dim-1-j, i+8, dim)] = src[RIDX(i+8, j, dim)];
	   		dst[RIDX(dim-1-j, i+9, dim)] = src[RIDX(i+9, j, dim)];
	   		dst[RIDX(dim-1-j, i+10, dim)] = src[RIDX(i+10, j, dim)];
	   		dst[RIDX(dim-1-j, i+11, dim)] = src[RIDX(i+11, j, dim)];
	   		dst[RIDX(dim-1-j, i+12, dim)] = src[RIDX(i+12, j, dim)];
	   		dst[RIDX(dim-1-j, i+13, dim)] = src[RIDX(i+13, j, dim)];
	   		dst[RIDX(dim-1-j, i+14, dim)] = src[RIDX(i+14, j, dim)];
	   		dst[RIDX(dim-1-j, i+15, dim)] = src[RIDX(i+15, j, dim)];
	   		dst[RIDX(dim-1-j, i+16, dim)] = src[RIDX(i+16, j, dim)];
	   		dst[RIDX(dim-1-j, i+17, dim)] = src[RIDX(i+17, j, dim)];
	   		dst[RIDX(dim-1-j, i+18, dim)] = src[RIDX(i+18, j, dim)];
	   		dst[RIDX(dim-1-j, i+19, dim)] = src[RIDX(i+19, j, dim)];
	   		dst[RIDX(dim-1-j, i+20, dim)] = src[RIDX(i+20, j, dim)];
	   		dst[RIDX(dim-1-j, i+21, dim)] = src[RIDX(i+21, j, dim)];
	   		dst[RIDX(dim-1-j, i+22, dim)] = src[RIDX(i+22, j, dim)];
	   		dst[RIDX(dim-1-j, i+23, dim)] = src[RIDX(i+23, j, dim)];
	   		dst[RIDX(dim-1-j, i+24, dim)] = src[RIDX(i+24, j, dim)];
	   		dst[RIDX(dim-1-j, i+25, dim)] = src[RIDX(i+25, j, dim)];
	   		dst[RIDX(dim-1-j, i+26, dim)] = src[RIDX(i+26, j, dim)];
	   		dst[RIDX(dim-1-j, i+27, dim)] = src[RIDX(i+27, j, dim)];
	   		dst[RIDX(dim-1-j, i+28, dim)] = src[RIDX(i+28, j, dim)];
	   		dst[RIDX(dim-1-j, i+29, dim)] = src[RIDX(i+29, j, dim)];
	   		dst[RIDX(dim-1-j, i+30, dim)] = src[RIDX(i+30, j, dim)];
	   		dst[RIDX(dim-1-j, i+31, dim)] = src[RIDX(i+31, j, dim)];
	   	}
}

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);
   // add_rotate_function(&test1_rotate, test1_rotate_descr   );
   // add_rotate_function(&test2_rotate, test2);
   // add_rotate_function(&test3_rotate, test3);
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
		for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
	 	   accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
	  		dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}

char stest1_descr[] = "test1";
void stest1(int dim, pixel *src, pixel *dst){
	int i, j, pos;

	dst[0].red = (src[0].red+src[1].red+src[dim].red+src[dim+1].red)/4;
	dst[0].green = (src[0].green+src[1].green+src[dim].green+src[dim+1].green)/4;
	dst[0].blue = (src[0].blue+src[1].blue+src[dim].blue+src[dim+1].blue)/4;

	pos = RIDX(0,dim-1,dim);	
	dst[pos].red = (src[pos].red+src[pos-1].red+src[pos-1+dim].red+src[pos+dim].red)/4;
	dst[pos].green = (src[pos].green+src[pos-1].green+src[pos-1+dim].green+src[pos+dim].green)/4;
	dst[pos].blue = (src[pos].blue+src[pos-1].blue+src[pos-1+dim].blue+src[pos+dim].blue)/4;
	
	pos = RIDX(dim-1,0,dim);
	dst[pos].red = (src[pos].red+src[pos-dim].red+src[pos+1].red+src[pos-dim+1].red)/4;
	dst[pos].green = (src[pos].green+src[pos-dim].green+src[pos+1].green+src[pos-dim+1].green)/4;
	dst[pos].blue = (src[pos].blue+src[pos-dim].blue+src[pos+1].blue+src[pos-dim+1].blue)/4;
	
	pos = RIDX(dim-1,dim-1,dim);
	dst[pos].red = (src[pos].red+src[pos-1].red+src[pos-dim].red+src[pos-dim-1].red)/4;
	dst[pos].green = (src[pos].green+src[pos-1].green+src[pos-dim].green+src[pos-dim-1].green)/4;
	dst[pos].blue = (src[pos].blue+src[pos-1].blue+src[pos-dim].blue+src[pos-dim-1].blue)/4;
	
	
	for(i= 1; i<dim-1; i++){
		pos = RIDX(0,i,dim);
		dst[pos].red = (src[pos-1].red+src[pos].red+src[pos+1].red
						+src[pos+dim-1].red+src[pos+dim].red+src[pos+dim+1].red)/6;
		dst[pos].green = (src[pos-1].green+src[pos].green+src[pos+1].green+
						src[pos+dim-1].green +src[pos+dim].green+src[pos+dim+1].green)/6;
		dst[pos].blue = (src[pos-1].blue+src[pos].blue+src[pos+1].blue+
						src[pos+dim-1].blue+src[pos+dim].blue+src[pos+dim+1].blue)/6;
		
		
	}
	for(i=1; i<dim-1; i++){
		pos = RIDX(i,0,dim);
		dst[pos].red = (src[pos-dim].red+src[pos].red+src[pos+dim].red
						+src[pos-dim+1].red+src[pos+1].red+src[pos+dim+1].red)/6;
		dst[pos].green = (src[pos-dim].green+src[pos].green+src[pos+dim].green+
						src[pos-dim+1].green +src[pos+1].green+src[pos+dim+1].green)/6;
		dst[pos].blue = (src[pos-dim].blue+src[pos].blue+src[pos+dim].blue+
						src[pos-dim+1].blue+src[pos+1].blue+src[pos+dim+1].blue)/6;
		
	}
	for(i=1; i<dim-1; i++){
		pos = RIDX(i,dim-1,dim);
		dst[pos].red = (src[pos-dim].red+src[pos].red+src[pos+dim].red
						+src[pos-dim-1].red+src[pos-1].red+src[pos+dim-1].red)/6;
		dst[pos].green = (src[pos-dim].green+src[pos].green+src[pos+dim].green+
						src[pos-dim-1].green +src[pos-1].green+src[pos+dim-1].green)/6;
		dst[pos].blue = (src[pos-dim].blue+src[pos].blue+src[pos+dim].blue+
						src[pos-dim-1].blue+src[pos-1].blue+src[pos+dim-1].blue)/6;
		
	}
	
	for(i=1; i<dim-1; i++){
		pos = RIDX(dim-1,i,dim);
		dst[pos].red = (src[pos-1].red+src[pos].red+src[pos+1].red
						+src[pos-dim-1].red+src[pos-dim].red+src[pos-dim+1].red)/6;
		dst[pos].green = (src[pos-1].green+src[pos].green+src[pos+1].green+
						src[pos-dim-1].green +src[pos-dim].green+src[pos-dim+1].green)/6;
		dst[pos].blue = (src[pos-1].blue+src[pos].blue+src[pos+1].blue+
						src[pos-dim-1].blue+src[pos-dim].blue+src[pos-dim+1].blue)/6;
		
	}
	
	
	
	
	
	for (i = 1; i < dim-1; i ++) {
		    for (j = 1; j < dim-1; j++) {
		      		pos = RIDX(i,j,dim);
		dst[pos].red = (src[pos-1-dim].red+src[pos-dim].red+src[pos+1-dim].red
						+src[pos-1].red+src[pos].red+src[pos+1].red
						+src[pos-1+dim].red+src[pos+dim].red+src[pos+1+dim].red)/9;
		dst[pos].green = (src[pos-1-dim].green+src[pos-dim].green+src[pos+1-dim].green
						+src[pos-1].green+src[pos].green+src[pos+1].green
						+src[pos-1+dim].green+src[pos+dim].green+src[pos+1+dim].green)/9;
		dst[pos].blue = (src[pos-1-dim].blue+src[pos-dim].blue+src[pos+1-dim].blue
						+src[pos-1].blue+src[pos].blue+src[pos+1].blue
						+src[pos-1+dim].blue+src[pos+dim].blue+src[pos+1+dim].blue)/9;
		        

		        }
		   	} 
	
}
char stest2_descr[] = "test2";
void stest2(int dim, pixel *src, pixel *dst){
	int i, j,pos;
	
	pos =0;
	dst[pos].red = (src[pos].red+src[pos+1].red+src[pos+dim].red+src[pos+dim+1].red)/4;
	dst[pos].green = (src[pos].green+src[pos+1].green+src[pos+dim].green+src[pos+dim+1].green)/4;
	dst[pos].blue = (src[pos].blue+src[pos+1].blue+src[pos+dim].blue+src[pos+dim+1].blue)/4;
	
	for(i= 1; i<dim-1; i++){
		pos = RIDX(0,i,dim);
		dst[pos].red = (src[pos-1].red+src[pos].red+src[pos+1].red
						+src[pos+dim-1].red+src[pos+dim].red+src[pos+dim+1].red)/6;
		dst[pos].green = (src[pos-1].green+src[pos].green+src[pos+1].green+
						src[pos+dim-1].green +src[pos+dim].green+src[pos+dim+1].green)/6;
		dst[pos].blue = (src[pos-1].blue+src[pos].blue+src[pos+1].blue+
						src[pos+dim-1].blue+src[pos+dim].blue+src[pos+dim+1].blue)/6;
		
		
	}

	pos = RIDX(0,dim-1,dim);	
	dst[pos].red = (src[pos].red+src[pos-1].red+src[pos-1+dim].red+src[pos+dim].red)/4;
	dst[pos].green = (src[pos].green+src[pos-1].green+src[pos-1+dim].green+src[pos+dim].green)/4;
	dst[pos].blue = (src[pos].blue+src[pos-1].blue+src[pos-1+dim].blue+src[pos+dim].blue)/4;
	
	for(i=1; i<dim-1; i++){
		pos = RIDX(i,0,dim);
		dst[pos].red = (src[pos-dim].red+src[pos].red+src[pos+dim].red
						+src[pos-dim+1].red+src[pos+1].red+src[pos+dim+1].red)/6;
		dst[pos].green = (src[pos-dim].green+src[pos].green+src[pos+dim].green+
						src[pos-dim+1].green +src[pos+1].green+src[pos+dim+1].green)/6;
		dst[pos].blue = (src[pos-dim].blue+src[pos].blue+src[pos+dim].blue+
						src[pos-dim+1].blue+src[pos+1].blue+src[pos+dim+1].blue)/6;
		
	}
	
	
	for (i = 1; i < dim-1; i ++) {
		    for (j = 1; j < dim-1; j++) {
		      		pos = RIDX(i,j,dim);
		dst[pos].red = (src[pos-1-dim].red+src[pos-dim].red+src[pos+1-dim].red
						+src[pos-1].red+src[pos].red+src[pos+1].red
						+src[pos-1+dim].red+src[pos+dim].red+src[pos+1+dim].red)/9;
		dst[pos].green = (src[pos-1-dim].green+src[pos-dim].green+src[pos+1-dim].green
						+src[pos-1].green+src[pos].green+src[pos+1].green
						+src[pos-1+dim].green+src[pos+dim].green+src[pos+1+dim].green)/9;
		dst[pos].blue = (src[pos-1-dim].blue+src[pos-dim].blue+src[pos+1-dim].blue
						+src[pos-1].blue+src[pos].blue+src[pos+1].blue
						+src[pos-1+dim].blue+src[pos+dim].blue+src[pos+1+dim].blue)/9;
		        

		        }
		   	} 
		   	
	
	for(i=1; i<dim-1; i++){
		pos = RIDX(i,dim-1,dim);
		dst[pos].red = (src[pos-dim].red+src[pos].red+src[pos+dim].red
						+src[pos-dim-1].red+src[pos-1].red+src[pos+dim-1].red)/6;
		dst[pos].green = (src[pos-dim].green+src[pos].green+src[pos+dim].green+
						src[pos-dim-1].green +src[pos-1].green+src[pos+dim-1].green)/6;
		dst[pos].blue = (src[pos-dim].blue+src[pos].blue+src[pos+dim].blue+
						src[pos-dim-1].blue+src[pos-1].blue+src[pos+dim-1].blue)/6;
		
	}
	
	
	pos = RIDX(dim-1,0,dim);
	dst[pos].red = (src[pos].red+src[pos-dim].red+src[pos+1].red+src[pos-dim+1].red)/4;
	dst[pos].green = (src[pos].green+src[pos-dim].green+src[pos+1].green+src[pos-dim+1].green)/4;
	dst[pos].blue = (src[pos].blue+src[pos-dim].blue+src[pos+1].blue+src[pos-dim+1].blue)/4;
	
	for(i=1; i<dim-1; i++){
		pos = RIDX(dim-1,i,dim);
		dst[pos].red = (src[pos-1].red+src[pos].red+src[pos+1].red
						+src[pos-dim-1].red+src[pos-dim].red+src[pos-dim+1].red)/6;
		dst[pos].green = (src[pos-1].green+src[pos].green+src[pos+1].green+
						src[pos-dim-1].green +src[pos-dim].green+src[pos-dim+1].green)/6;
		dst[pos].blue = (src[pos-1].blue+src[pos].blue+src[pos+1].blue+
						src[pos-dim-1].blue+src[pos-dim].blue+src[pos-dim+1].blue)/6;
		
	}
	
	pos = RIDX(dim-1,dim-1,dim);
	dst[pos].red = (src[pos].red+src[pos-1].red+src[pos-dim].red+src[pos-dim-1].red)/4;
	dst[pos].green = (src[pos].green+src[pos-1].green+src[pos-dim].green+src[pos-dim-1].green)/4;
	dst[pos].blue = (src[pos].blue+src[pos-1].blue+src[pos-dim].blue+src[pos-dim-1].blue)/4;
	
}

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{
    stest2(dim, src, dst);
}


/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
   // add_smooth_function(&stest1, stest1_descr);
    //add_smooth_function(&stest2, stest2_descr);
    /* ... Register additional test functions here */
}

