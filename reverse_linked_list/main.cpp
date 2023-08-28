#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
    
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* reverseList(ListNode* head) {
    
    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current != nullptr)
    {
        ListNode* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    return prev;

}


int main() 
{
    // Test cases
    ListNode* input = new ListNode();
    
    reverseList(input);
    
    return 0;
}