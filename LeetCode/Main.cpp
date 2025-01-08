
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cstdint>


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

static char* ReverseChar(char* CharIn, int IndexLast)
 {
    if (IndexLast == 0)
        return CharIn;
    
    char* charOut = new char[100];
     int indexTemp = 0;


     while (IndexLast >= 0)
     {
         *(charOut + indexTemp) = *(CharIn + IndexLast);
         --IndexLast;
         ++indexTemp;
     }

     *(charOut + indexTemp) = '\0';

     return charOut;
 }


class Solution {
public:
    ListNode* Result;

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        
        char* str1 = new char[100];
        char* str2 = new char[100];
        int index1 = 0;
        int index2 = 0;

        while (l1->next != nullptr || l2->next != nullptr)
        {
            *(str1 + index1) = l1->val + '0';
            *(str2 + index2) = l2->val + '0';

            if (l1->next != nullptr)
            {
                l1 = l1->next;
                ++index1;
            }

            if (l2->next != nullptr)
            {
                l2 = l2->next;
                ++index2;
            }
            
        }

        if (index1 == index2)
        {
            *(str1 + index1) = l1->val + '0';
            *(str1 + index1 + 1) =  '\0';
            *(str2 + index2) = l2->val + '0';
            *(str2 + index2 + 1) = '\0';
        }
        else if (index1 > index2)
        {
            *(str1 + index1) = l1->val + '0';
            *(str1 + index1 + 1) = '\0';
            *(str2 + index2 + 1) = '\0';
        }
        else
        {
            *(str2 + index2) = l2->val + '0';
            *(str1 + index1 + 1) = '\0';
            *(str2 + index2 + 1) = '\0';
        }

        char* ReverseStr1 = ReverseChar(str1, index1);
        char* ReverseStr2 = ReverseChar(str2, index2);
        
        
        

        std::uint64_t str1Int = std::stoll(std::string(ReverseStr1));
        std::uint64_t str2Int = std::stoll(std::string(ReverseStr2));
        std::uint64_t sum = str1Int + str2Int;

        ListNode* Start = new ListNode;
        ListNode* Temp = new ListNode;
        Start->next = Temp;

        while (sum >= 10)
        {
            Temp->val = sum % 10;
            sum /= 10;
            Temp->next = new ListNode;
            Temp = Temp->next;
        }
        Temp->val = sum;


        Result = Start->next;

        return Result;
	}

    
};



int main()
{
    ListNode node1;
    node1.val = 9;


    ListNode node4;
    node4.val = 1;
    ListNode node5;
    node5.val = 9;
    ListNode node6;
    node6.val = 9;
    ListNode node7;
    node7.val = 9;
    ListNode node8;
    node8.val = 9;
    ListNode node9;
    node9.val = 9;
    ListNode node10;
    node10.val = 9;
    ListNode node11;
    node11.val = 9;
    ListNode node12;
    node12.val = 9;
    ListNode node13;
    node13.val = 9;


    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = &node8;
    node8.next = &node9;
    node9.next = &node10;
    node10.next = &node11;
    node11.next = &node12;
    node12.next = &node13;
  


    Solution sol;
    ListNode* Res = sol.addTwoNumbers(&node1, &node4);

    while (Res->next != nullptr)
    {
        std::cout << Res->val << "\n";
        Res = Res->next;
    }


	return 0;
}