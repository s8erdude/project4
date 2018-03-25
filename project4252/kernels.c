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
    "dkiselevjpuerto",              /* Team name */

    "Daniel Kiselev",     /* First member full name */
    "dkiselev@u.rochester.edu",  /* First member email address */

    "Juan Puerto",                   /* Second member full name (leave blank if none) */
    "jpuerto@u.rochester.edu"                    /* Second member email addr (leave blank if none) */
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

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst)
{
	int i, j;
	int dst_index_plus_i, dst_index, dim_mult;
        //dim^2 - dim - dimj
        dim_mult = dim*dim - dim;
	int tmp_i, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32;

        for (i = 0; i < dim; i+=32) {
		tmp_i = i;
                i2 = ++tmp_i;
                i3 = ++tmp_i;
                i4 = ++tmp_i;
                i5 = ++tmp_i;
                i6 = ++tmp_i;
                i7 = ++tmp_i;
                i8 = ++tmp_i;
                i9 = ++tmp_i;
                i10 = ++tmp_i;
                i11 = ++tmp_i;
                i12 = ++tmp_i;
                i13 = ++tmp_i;
                i14 = ++tmp_i;
                i15 = ++tmp_i;
                i16 = ++tmp_i;
                i17 = ++tmp_i;
                i18 = ++tmp_i;
                i19 = ++tmp_i;
                i20 = ++tmp_i;
                i21 = ++tmp_i;
                i22 = ++tmp_i;
                i23 = ++tmp_i;
                i24 = ++tmp_i;
                i25 = ++tmp_i;
                i26 = ++tmp_i;
                i27 = ++tmp_i;
                i28 = ++tmp_i;
                i29 = ++tmp_i;
		i30 = ++tmp_i;
		i31 = ++tmp_i;
		i32 = ++tmp_i;
                for (j = 0; j < dim; j++) {
                        dst_index = dim_mult - dim*j;
                        dst_index_plus_i = dst_index + i;
                        dst[dst_index_plus_i++] = src[i * dim + j];
                        dst[dst_index_plus_i++] = src[i2 * dim + j];
                        dst[dst_index_plus_i++] = src[i3 * dim + j];
                        dst[dst_index_plus_i++] = src[i4 * dim + j];
                        dst[dst_index_plus_i++] = src[i5 * dim + j];
                        dst[dst_index_plus_i++] = src[i6 * dim + j];
                        dst[dst_index_plus_i++] = src[i7 * dim + j];
                        dst[dst_index_plus_i++] = src[i8 * dim + j];
                        dst[dst_index_plus_i++] = src[i9 * dim + j];
                        dst[dst_index_plus_i++] = src[i10 * dim + j];
                        dst[dst_index_plus_i++] = src[i11 * dim + j];
                        dst[dst_index_plus_i++] = src[i12 * dim + j];
                        dst[dst_index_plus_i++] = src[i13 * dim + j];
                        dst[dst_index_plus_i++] = src[i14 * dim + j];
                        dst[dst_index_plus_i++] = src[i15 * dim + j];
                        dst[dst_index_plus_i++] = src[i16 * dim + j];
                        dst[dst_index_plus_i++] = src[i17 * dim + j];
                        dst[dst_index_plus_i++] = src[i18 * dim + j];
                        dst[dst_index_plus_i++] = src[i19 * dim + j];
                        dst[dst_index_plus_i++] = src[i20 * dim + j];
                        dst[dst_index_plus_i++] = src[i21 * dim + j];
                        dst[dst_index_plus_i++] = src[i22 * dim + j];
                        dst[dst_index_plus_i++] = src[i23 * dim + j];
                        dst[dst_index_plus_i++] = src[i24 * dim + j];
                        dst[dst_index_plus_i++] = src[i25 * dim + j];
                        dst[dst_index_plus_i++] = src[i26 * dim + j];
                        dst[dst_index_plus_i++] = src[i27 * dim + j];
                        dst[dst_index_plus_i++] = src[i28 * dim + j];
                        dst[dst_index_plus_i++] = src[i29 * dim + j];
                        dst[dst_index_plus_i++] = src[i30 * dim + j];
                        dst[dst_index_plus_i++] = src[i31 * dim + j];
                        dst[dst_index_plus_i++] = src[i32 * dim + j];
                }
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

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{
    naive_smooth(dim, src, dst);
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
    /* ... Register additional test functions here */
}

