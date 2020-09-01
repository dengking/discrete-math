#include "swap.h"
/* 
 * File:   swap.c
 * Author: 徐子珊
 *
 * Created on 2009年6月30日, 下午3:22
 */


void swap(void* x,void* y,int size){
     void* temp=(void*)malloc(size);
     memcpy(temp,x,size);
     memcpy(x,y,size);
     memcpy(y, temp,size);
	  free(temp);
}
