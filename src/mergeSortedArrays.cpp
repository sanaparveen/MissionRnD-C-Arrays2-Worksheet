/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <iostream>
#include <stdio.h>
#include <malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

void numDate(char date[], int d[]);
int greater2(int date1[], int date2[])
{
	int i, count = 0;
	for (i = 2; i >= 0; i--)
	if (date1[i] < date2[i])
		return 0;
	else if (date1[i] == date2[i])
		count++;
	if (count<3)
		return 1;
	else
		return 0;
}
int greater1(int date1[], int date2[])
{
	int i, count = 0;
	for (i = 2; i >= 0; i--)
	if (date1[i] > date2[i])
		return 0;
	else if (date1[i] == date2[i])
		count++;
	if (count < 3)
		return 1;
	else
		return 0;
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	int date1[] = { 0, 0, 0 };
	int date2[] = { 0, 0, 0 };
	int index1 = 0, index2 = 0, index = 0,AEnd = 0,BEnd = 0;
	struct transaction *result = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	int afinish = 0, bfinish = 0;

	if (A == NULL || B == NULL)
		return NULL;

	numDate(A[index1].date, date1);
	numDate(B[index2].date, date2);
	for (index = 0; index < ALen + BLen ; index++)
	{
		if ( BEnd != 1 &&(greater2(date1, date2) || AEnd == 1))
		{
			result[index] = B[index2];
			index2++;
			if (index2 < BLen)
				numDate(B[index2].date, date2);
		}
		else if (greater1(date1, date2)|| BEnd == 1)
		{
			result[index] = A[index1];
			index1++;
			if (index1 < ALen)
				numDate(A[index1].date, date1);
		}
		else
		{
			result[index] = A[index1];
			result[index + 1] = B[index2];
			index = index + 1;
			index1++;
			index2++;
			if (index1 < ALen)
				numDate(A[index1].date, date1);
			if (index2 < BLen)
				numDate(B[index2].date, date2);
		}
		if (index1 == ALen)
			AEnd = 1;
		if (index2 == BLen)
			BEnd = 1;

	}
	return result;
}
void numDate(char date[], int d[]){

	int i = 0, j = 0, k;
	d[0] = 0;
	d[1] = 0;
	d[2] = 0;

	for (i = j; date[i] != '-'; i++) {
		d[0] = d[0] * 10 + date[i] - '0';
	}

	for (j = i + 1; date[j] != '-'; j++) {
		d[1] = d[1] * 10 + date[j] - '0';
	}
	for (k = j + 1; date[k] != '\0'; k++)
		d[2] = d[2] * 10 + date[k] - '0';

}