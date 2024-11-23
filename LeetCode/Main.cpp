
#include <vector>

int BinarySearch(const std::vector<int>& SortedArray, const int& Target)
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




struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {  
		ListNode* dummy = new ListNode(0);  
		ListNode* current = dummy;  
		
		while (list1 != nullptr && list2 != nullptr) {  
			if (list1->val <= list2->val) {  
				current->next = list1;  
				list1 = list1->next;  
			} else {  
				current->next = list2;  
				list2 = list2->next;  
			}  
			current = current->next;  
		}  
		
		if (list1 != nullptr) {  
			current->next = list1;  
		}  
        
		if (list2 != nullptr) {  
			current->next = list2;  
		}  

		return dummy->next;  
	}  


int main()
{

	

	
	return 0;
}