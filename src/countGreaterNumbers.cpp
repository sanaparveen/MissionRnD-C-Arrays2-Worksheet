/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

void toString(char date[], int d[], int mid);
int lessDate(int date1[], int date2[])
{
	int i;
	for (i = 2; i >= 0; i--)
	if (date1[i] < date2[i])
		return 1;
	return 0;
}
int equalDate(int date1[], int date2[])
{
	int i;
	for (i = 0; i < 3; i++)
	if (date1[i] != date2[i])
		return 0;
	return 1;
}
int binarySearch(struct transaction *Arr, int low, int high, int *date1)
{
	int mid;
	int date2[] = { 0, 0, 0 };
	int date3[] = { 0, 0, 0 };

	if (high >= low)
	{
		mid = low + (high - low) / 2;
		toString(Arr[mid].date, date2, mid);
		if (mid + 1 <= high)
			toString(Arr[mid + 1].date, date3, mid + 1);
		if ((mid == high || lessDate(date1, date3)) && equalDate(date1, date2))
			return mid;
		else if (equalDate(date1, date2) || lessDate(date1, date2))
			return binarySearch(Arr, mid + 1, high, date1);
		else
			return binarySearch(Arr, low, mid - 1, date1);
	}
	else if (high < low)
	{
		toString(Arr[0].date, date2, 0);
		if (equalDate(date1, date2))
			return 0;
	}
	return -1;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int index = -1;
	int low = 0;
	int high = len - 1;
	int date1[] = { 0, 0, 0 };

	toString(date, date1, 2);

	index = binarySearch(Arr, low, high, date1);
	if (index != -1)
		return len - (index + 1);
	else
		return 0;
}
void toString(char date[], int d[], int mid){

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