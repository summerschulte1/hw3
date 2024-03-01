#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    // Initialize smaller and larger only here, before recursion starts
    smaller = NULL;
    larger = NULL;
    // Start the recursive partitioning process
    llpivotRecursive(head, smaller, larger, pivot);
    // The original list has been partitioned, so head should point to NULL
    head = NULL;
}
void llpivotRecursive(Node* head, Node*& smaller, Node*& larger, int pivot) {
  if(head == NULL){
    return;
  }
  Node *next = head->next;
  llpivotRecursive(next, smaller, larger, pivot);
  if(head->val <= pivot){
    head->next = smaller; //heads now going to point to smaller list
    smaller = head;
  }
  else{
    head->next = larger;
    larger = head;
  } 

  //llpivotRecursive(next, smaller, larger, pivot);
}




