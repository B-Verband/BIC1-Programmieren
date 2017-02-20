/* Exercise 09_1 */

/********************************* Master.c *********************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "helpers.h"

#define SIZE 7

int minimum(int data[], int length);
int maximum(int data[], int length);
int sum(int data[], int length);
double average(int data[], int length);
double median(int data[], int length);
double variance(int data[], int length);
double stddev(int data[], int length);

int main(int argc, char* argv[])
{
	int array[SIZE];
	
	fill_random(array, SIZE);

	printf("Array-Werte: \n");
	int i = 0;
	for (i = 0; i < SIZE; i++) {
		printf("%6d: %6d\n", i, array[i]);
	}

	printf("Minimum: %d\n", minimum(array, SIZE));
	printf("Maximum: %d\n", maximum(array, SIZE));
	printf("Summe: %d\n", sum(array, SIZE));
	printf("Arithmetisches Mittel: %f\n", average(array, SIZE));
	printf("Median: %f\n", median(array, SIZE));
	printf("Varianz: %f\n", variance(array, SIZE));
	printf("Standardabweichung: %f\n", stddev(array, SIZE));

	return 0;
}

double average(int data[], int length)
{
	return (double) sum(data, length) / length;
}

double median(int data[], int length)
{
	bubblesort(data, length);

	if (length % 2) {
		return (double) data[((length) + 1) / 2 - 1];
	}
	else {
		return (data[(length / 2) - 1] + data[length / 2]) / (double) 2;
	}
}

int minimum(int data[], int length)
{
	int minimum = data[0];

	int i = 0;
	for (i = 1; i < length; i++) {
		minimum = (minimum < data[i]) ? minimum : data [i];
	}

	return minimum;
}

int maximum(int data[], int length)
{
	int maximum = data[0];

	int i = 0;
	for (i = 1; i < length; i++) {
		maximum = (maximum > data[i]) ? maximum : data[i];
	}

	return maximum;
}

int sum(int data[], int length)
{
	long sum = 0;

	int i = 0;
	for (i = 0; i < length; i++) {
		sum += data[i];
	}

	return sum;
}

double variance(int data[], int length)
{
	double variance = 0.0;
	double average_var = average(data, length);

	int i = 0;
	for (i = 0; i < length; i++) {
		variance += (data[i] - average_var) * (data[i] - average_var);
	}

	return variance / length;
}

double stddev(int data[], int length)
{
	return sqrt(variance(data, length));
}

/********************************* helpers.h *********************************/
#ifndef HELPERS_H
#define HELPERS_H

void bubblesort(int data[], int length);
void fill_random(int data[], int length);

#endif
/********************************* helpers.c *********************************/
#include <stdlib.h>
#include "helpers.h"

void bubblesort(int data[], int length)
{
	int i = 0, j = 0;
	for (i = 0; i < length - 1; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (data[i] > data[j])
			{
				int tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
		}
	}
}

void fill_random(int data[], int length)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		data[i] = rand();
	}
}
