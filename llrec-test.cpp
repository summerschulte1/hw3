#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------





int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------

    const char* filename = argv[1];
    int pivot = atoi(argv[2]); // Convert the second command line argument to an integer

    // Read list from file
    Node* head = readList(filename);
   

    // Print the original list
    cout << "Original list: ";
    print(head);

    Node *smaller = NULL, *larger = NULL;

    // Call llpivot with the list and pivot
    llpivot(head, smaller, larger, pivot);

    // Print the resulting lists
    cout << "Smaller or equal than pivot (" << pivot << "): ";
    print(smaller);

    cout << "Larger than pivot (" << pivot << "): ";
    print(larger);

    // Deallocate all lists
    dealloc(smaller);
    dealloc(larger);
    



    
    return 0;

}
