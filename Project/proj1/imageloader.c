/************************************************************************
**
** NAME:        imageloader.c
**
** DESCRIPTION: CS61C Fall 2020 Project 1
**
** AUTHOR:      Dan Garcia  -  University of California at Berkeley
**              Copyright (C) Dan Garcia, 2020. All rights reserved.
**              Justin Yokota - Starter Code
**				YOUR NAME HERE
**
**
** DATE:        2020-08-15
**
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "imageloader.h"

//Opens a .ppm P3 image file, and constructs an Image object. 
//You may find the function fscanf useful.
//Make sure that you close the file with fclose before returning.
Image *readData(char *filename) 
{
	//YOUR CODE HERE
	//打开文件且读取头信息
	FILE *fp=fopen(filename,"r");
	char format[3];
	fscanf(fp,"%s",format);
	int width, height;
	fscanf(fp,"%d %d",&width,&height);
	int scale;
	fscanf(fp,"%d",&scale);
	//初始化image结构体
	Image *img=(Image*)malloc(sizeof(Image));
	img->rows=height;
	img->cols=width;
	//分配像素矩阵内存(动态二维数组)
	img->image=(Color**)malloc(sizeof(Color*)*height);//行
	for(int i=0;i<height;i++){
		img->image[i]=(Color*)malloc(sizeof(Color)*width);
	}
	//读取像素数据
	for(int i=0;i<height;i++){
		for(int j==0;j<width;j++){
			int r,g,b;
			fscanf(fp,"%d %d %d",&r,&g,&b);
			img->image[i][j].R=r;
			img->image[i][j].G=g;
			img->image[i][j].B=b;
		}
	}
	fclose(fp);
	return img;


}

//Given an image, prints to stdout (e.g. with printf) a .ppm P3 file with the image's data.
void writeData(Image *image)
{
	//YOUR CODE HERE
	printf("P3\n");
	printf("%d %d",image->cols,image->rows);
	printf("255\n");
	for(int i=0;i<image->rows;i++){
		for(int j=0;j<image->cols;j++){
			printf("%3d %3d %3d",image->image[i][j].R,image->image[i][j].G,image->image[i][j].B);
			if(j<image->cols-1){
				printf("   ");
			}
		}
		printf("\n");
	}
}

//Frees an image
void freeImage(Image *image)
{
	//YOUR CODE HERE
	for(int i=0;i<image->rows;i++){
		free(image->image[i]);
	}
	free(image->image);
	free(image);
}