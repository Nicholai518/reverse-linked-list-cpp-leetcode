#include <iostream>
using namespace std;

  struct ListNode 
  {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        // place holders
        ListNode* cur = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        // iterate through the linked list
        while (cur != NULL) 
        {
            next = cur->next;
            cur->next = prev;

            // swap node positions
            prev = cur;
            cur = next;
        }
        // return new head
        head = prev;
        return head;
    }
};

int main()
{
    Solution solution;

    ListNode four(4, NULL);
    ListNode three(3, &four);
    ListNode two(2, &three);
    ListNode head(1, &two);
    ListNode *exampleOne = solution.reverseList(&head);

    cout << "Example One : ";
    while (exampleOne != NULL) 
    {
        cout << exampleOne->val << " ";
        exampleOne = exampleOne->next;
    }
	return 0;
}
