#include "Palindrome.h"
#include <vector>

int BinarySearch(std::vector<int> SortedArray, int Target)
{
	int Start = 0;
	int End = SortedArray.size() - 1;

	while (Start <= End)
	{
		int Mid = Start + (End - Start) / 2;
		if (SortedArray[Mid] == Target) return Mid;

		if (SortedArray[Mid] > Target)
		{
			End = Mid - 1;
		}
		else if (SortedArray[Mid] < Target)
		{
			Start = Mid + 1;
		}
	}
	
}


int main()
{
	std::vector<int> Sortedarray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int Target = 8;
	int result = BinarySearch(Sortedarray, Target);
	printf("%d\n", result);

	
	return 0;
}