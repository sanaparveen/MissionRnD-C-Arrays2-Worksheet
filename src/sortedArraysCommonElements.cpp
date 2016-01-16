/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

void toStringDate(char date[], int d[], int v);
int lesserDate(int date1[], int date2[])
{
	int i;
	for (i = 2; i >= 0; i--)
	if (date1[i] < date2[i])
		return 1;
	return 0;
}
int greaterDate(int date1[], int date2[])
{
	int j;
	for (j = 2; j >= 0; j--)
	if (date2[j] < date1[j])
		return 1;
	return 0;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {


	int date1[] = { 0, 0, 0 };
	int date2[] = { 0, 0, 0 };
	int i = 0, j = 0, k = 0;
	struct transaction *Result[6];

	*Result = (struct transaction *) malloc(sizeof(struct transaction));

	if (A == NULL || B == NULL)
		return NULL;

	while (i < ALen && j < BLen)
	{
		toStringDate(A[i].date, date1, i);
		toStringDate(B[j].date, date2, j);
		if (lesserDate(date1, date2))
			i++;
		else if (greaterDate(date1, date2))
			j++;
		else
		{
			Result[k] = &B[j];
			k++;
			i++;
			j++;
		}
	}
	if (k == 0)
		return NULL;

	return *Result;

}

void toStringDate(char date[], int d[], int v){

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