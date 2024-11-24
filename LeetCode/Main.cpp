
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> QuickSort(std::vector<int> VectorIn)
{
	if (VectorIn.size() == 0) return std::vector<int>{};
	if (VectorIn.size() == 1) return VectorIn;

	if (VectorIn.size() == 2)
	{
		if (VectorIn[0] < VectorIn[1])
		{
			return VectorIn;
		}
		else
		{
			return std::vector<int>{VectorIn[1], VectorIn[0]};
		}
	}

	int IndexAnchor = VectorIn.size() / 2;

	std::vector<int> less;
	std::vector<int> grater;

	for (int i = 0; i < IndexAnchor; i++)
	{
		if (VectorIn[i] <= VectorIn[IndexAnchor])
		{
			less.push_back(VectorIn[i]);
		}
		else
		{
			grater.push_back(VectorIn[i]);
		}
	}

	for (int i = IndexAnchor + 1; i < VectorIn.size(); i++)
	{
		if (VectorIn[i] <= VectorIn[IndexAnchor])
		{
			less.push_back(VectorIn[i]);
		}
		else
		{
			grater.push_back(VectorIn[i]);
		}
	}
	

	std::vector<int> Result(QuickSort(less));
	Result.push_back(VectorIn[IndexAnchor]);
	
	std::vector<int> ResultGreater = QuickSort(grater);
	Result.insert(Result.end(), ResultGreater.begin(), ResultGreater.end());

	return Result;
}



int main()
{
	std::vector<int> Vec = { 0, 6 , 5, 8, 10 , 44, 22, 155, 14, 1, 200, 300, 33, 77, 14, 2, -1, -200, 999 };
	
	std::vector<int> SortVec = QuickSort(Vec);

	for (auto& c : SortVec)
	{
		std::cout << c << "\n";
	}
	
	

	
	return 0;
}