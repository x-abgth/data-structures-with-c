#include<stdio.h>
#include<stdlib.h>

int arr[50], size = 0;

void displayElements();
void insertAtBegin(int);
void insertAtPos(int, int);
void insertAtEnd(int);
void deleteAtBegin();
void deleteAtPos(int);
void deleteAtEnd();

int main() {
	int choice, data, loc;
	
	while(1) {
		printf("\nChoose an option from below : \n");
		printf("1. Insert at beginning\n2. Insert at Position\n3. Insert at end\n4. Delete at beginning\n5. Delete at position\n6. Delete at end\n7. Display\n8. Exit from the program\n");
		scanf("%d", &choice);	
		
		switch(choice) {
			case 1 : printf("Enter the data to insert : ");
			scanf("%d", &data);
			insertAtBegin(data);
			break;
			case 2: printf("\nEnter the data to insert : ");
			scanf("%d", &data);
			printf("Enter the position to insert data : ");
			scanf("%d", &loc);
			insertAtPos(data, loc);
			break;
			case 3: printf("Enter the data to insert : ");
			scanf("%d", &data);
			insertAtEnd(data);
			break;
			case 4: deleteAtBegin();
			break;
			case 5: printf("Enter the position to delete : ");
			scanf("%d", &loc);
			deleteAtPos(loc);
			break;
			case 6: deleteAtEnd();
			break;
			case 7: displayElements();
			break;
			case 8: printf("\nThe program got exited!\n");
			exit(0);
			default: printf("\nWrong choice!\n");
		}
	}
	return 0;
}

// TO DISPLAY THE ELEMENTS IN THE ARRAY
void displayElements() {
	int i;
	
	printf("\n");
	if(size == 0) {
		printf("Sorry, No elements to display!\n");
	} else {
		for(i = 0; i < size; i++) {
			printf("%d\t", arr[i]);
		}	
	}
	
	printf("\nSIZE = %d\n", size);
}


// INSERTION CODE STARTS FROM HERE
void insertAtBegin(int data) {
	
	int i, max = sizeof(arr) / sizeof(arr[0]);
	
	if(size != max - 1) {
		if(size == 0) {
			arr[0] = data;		
		} else {
			for(i = size-1; i >= 0; i--) {
				arr[i+1] = arr[i]; 
			}
			arr[0] = data;
		}
		
		size++;
	} else {
		printf("The array is overflowing!");
	}
}

void insertAtPos(int data, int pos) {
	int i;
	
	if(size < pos-1) {
		printf("Sorry, The position is invalid.");
	} else {
		// because size and pos will be always one plus the actual index.
		for(i = size-1; i >= pos-1; i --) {
			arr[i+1] = arr[i];
		}
		
		arr[pos-1] = data;
		size++;
	}
}

void insertAtEnd(int data) {
	arr[size] = data;
	size ++;
}

// DELETION CODE STARTS FROM HERE
void deleteAtBegin() {
	int i, temp;
	
	if(size > 0) {
		temp = arr[0];
		for(i = 0; i < size-1; i++) {
			arr[i] = arr[i + 1];
		}
		
		arr[size-1] = temp;
		size --;
	} else {
		printf("\nSorry, The array is empty!\n");
	}
}

void deleteAtPos(int pos) {
	int i, temp;
	
	if(size < pos-1 && pos < 0) {
		printf("\nThe position you entered is invalid!");
	} else {
		temp = arr[pos-1];
		for(i = pos-1; i < size-1; i++) {
			arr[i] = arr[i+1];
		}
		arr[size] = temp;
		size--;
	}
}

void deleteAtEnd() {
	size--; 
}



























