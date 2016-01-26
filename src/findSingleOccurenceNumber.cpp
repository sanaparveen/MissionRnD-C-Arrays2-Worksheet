/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

int findSingleOccurenceNumber(int *A, int len) {

	if (len < 0 || A == nullptr )
		return -1;
	int value1 = 0, value2 = 0, index = 0, mask;

	for (index = 0; index < len; index++)
	{
		value2 = value2 | (value1 & A[index]);
		value1 = value1 ^ A[index];
		mask = ~(value1 & value2);
		value1 &= mask;
		value2 &= mask;
	}

	return value1;
	return -1;
}