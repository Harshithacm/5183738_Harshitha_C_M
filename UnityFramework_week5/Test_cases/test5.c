//To find arr average

//main.c
#include "stdio.h"
#include "unity.h"
#include "arr.h"

void setUp(){}
void tearDown(){}

void test_avg(){
    int arr[]={1,2,3,4,5};
    TEST_ASSERT_FLOAT_WITHIN(0.0,3.0,arr_average(arr,5));
    TEST_ASSERT_FLOAT_WITHIN(0.21,2.8,arr_average(arr,5));
    TEST_ASSERT_FLOAT_WITHIN(0.5,2.5,arr_average(arr,5));
    TEST_ASSERT_FLOAT_WITHIN(0.0,3.0,arr_average(arr,0));

}
int main(){
    UNITY_BEGIN();
    RUN_TEST(test_avg);
    UNITY_END();
}

//average.c
#include "arr.h"
#include "unity.h"

float arr_average(int arr[],int size){
    float sum=0;
    if(arr==NULL||size==0) return 0;
    else{
        for(int i=0;i<size;i++)
        {
            sum+=arr[i];
        }
    }
    return (float)sum/size;
}
//arr.h
#ifndef __ARR__H
#define __ARR__H

float arr_average(int arr[], int size);
#endif

//Makefile
object.o: main.c average.c unity.c
	gcc $^ -c
out:main.o average.o unity.o
	gcc $^ -o out.exe
run: out
	./out.exe
clean:
	rm -rf *.o*.out

//To swap the elements in array
//main.c
#include "stdio.h"
#include "arr_swap.h"
#include "unity.h"

void setUp(){}
void tearDown(){}

void test_arr_swap(){
  int arr[]={1,2,3,4,5};
  int size =5;
  arr_swap(arr,size); 
  int expected[]={5,4,3,2,1};
  TEST_ASSERT_EQUAL_INT_ARRAY(expected,arr,size); 
}
void test_not_arr_swap(){
  int arr[]={1,2,3,4,5};
  int size =5;
  arr_swap(arr,size); 
  int expected[]={1,4,3,2,5};
  TEST_ASSERT_EQUAL_INT_ARRAY(expected,arr,size); 
}


int main(){
    UNITY_BEGIN();
    RUN_TEST(test_arr_swap);
    RUN_TEST(test_not_arr_swap);
    return UNITY_END();
}

//arr_swap.c
#include "arr_swap.h"
#include "unity.h"

void arr_swap(int arr[], int size) {
    int *st = arr;
    int *ed = arr + size - 1;

    while (st < ed) {
        int temp = *st;
        *st = *ed;
        *ed = temp;

        st++;
        ed--;
    }
}

//arr_swap.h
#ifndef __ARRSWAP__H
#define __ARRSWAP__H
void arr_swap(int arr[],int size);
#endif

//Makefile

object.o: main.c arr_swap.c unity.c
	gcc $^ -c
out:main.o arr_swap.o unity.o
	gcc $^ -o out.exe
run: out
	./out.exe
clean:
	rm -rf *.o*.out
