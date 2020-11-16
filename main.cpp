#include <iostream>
#include <vector>;
using namespace std;

vector<int> getVec(int); // this is the vector function

struct Node { // this creates the linked list
	int data;
	struct Node* next;
};



vector<int> getVec(int amountOfElements) { // this will create the vector that will then be converted to a linked list
	cout << "Please enter the next " << amountOfElements << " numbers" << endl;
	
	vector<int> vec(amountOfElements); // this creates the vector that the function will return with the amount of elements the user specifies
	int input;
	for (int i = 0; i < amountOfElements; ++i) { // this fills the vector with the user numbers
		cin >> input;
		vec[i] = input;
	}


	return vec;

}

void insertAtTheBeginningOfTheList(struct Node** start, int& pos) { // this function convertes the vector numbers into the linked list
	struct Node* elementNum = (struct Node*)malloc(sizeof(struct Node));

	elementNum->data = pos; 
	elementNum->next = *start;
	*start = elementNum;

}

void printList(struct Node* it) { // this prints the linked list

	while (it != NULL) {
		cout << it->data << " ";
		it = it->next;
	}

}

struct Node* swap(struct Node* ptr1, struct Node* ptr2) {
	struct Node* tempVar = ptr2->next; // createa  temp node to swap the two nodes
	ptr2->next = ptr1;
	ptr1->next = tempVar;



	return ptr2;
}

void sortList(struct Node** start, int size) { // this function applies the bubble sorting algorithm
	struct Node** head;
	struct Node* ptr1;
	struct Node* ptr2;

	// this applies the bubble sorting algorithm to the linked list
	for (int i = 0; i <= size; ++i) {
		head = start;

		for (int k = 1; k < size - i; ++k) {

			ptr1 = *head;
			ptr2 = ptr1->next;

			if (ptr1->data > ptr2->data) { // if the data at a certain node, is greater than the data at the next node, swap them 
				*head = swap(ptr1, ptr2);
			}

			head = &(*head)->next; // goes to the next node
		}


	}


}


int main() {
	static  int amountOfElements = 0;
	cout << "Enter the amount of numbers you wish to sort" << endl;
	cin >> amountOfElements; // gets the amount of elements
	struct Node* ref = NULL; // this ref the linked list
	vector<int> vec = getVec(amountOfElements); // this creates a vector, and sets it equal to the vecotor function
	
	int* pos = vec.data(); // this gets the data at a certain position in the vector

	for (int i = 0; i < amountOfElements; ++i) {// iterates through the amount of elements
		insertAtTheBeginningOfTheList(&ref, *pos++); // inserts the linked list, and the data at a certian position into the function, 
	}                                               // that increases to the next position with the next iteration

	cout << "Your list before sorting is " << endl;
	printList(ref); // prints list

	sortList(&ref, amountOfElements); // sorts the list by passing it in by reference

	cout << "\nYour list after sorting is " << endl;
	printList(ref);


	return 0;
}
