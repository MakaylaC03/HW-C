/*
Makayla Coomer
12/8/23
Write a code that simulates a book database
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store book information
struct book {
    char title[50];
    char author[50];
    int year;
    double price;
    struct book *next; // Pointer to the next book in the list
};

// Declare a global pointer to the head of the list
struct book *head = NULL;

// Function prototypes
void insert_book(); // Insert a new book record
void print_books(); // Print the list of all the available books based on the insertion order
void remove_book(); // Remove a book from the library according to its title
void print_sorted(); // Print all the books sorted from the oldest (publishing year) to the newest
void write_file(); // Write all the book records to a file named library.txt sorted from the oldest to the newest
void swap(struct book *a, struct book *b); // Swap two book records
void sort(); // Sort the list of books by year

// Main function
int main() {
    int choice; // Variable to store the user's choice
    printf("Welcome to the library management system.\n");
    do {
        // Display the menu and ask the user what he wants to do
        printf("\nWhat do you want to do?\n");
        printf("1. Insert a new book record\n");
        printf("2. Print the list of all the available books based on the insertion order\n");
        printf("3. Remove a book from the library according to its title\n");
        printf("4. Print all the books sorted from the oldest (publishing year) to the newest\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the corresponding action based on the user's choice
        switch(choice) {
            case 1:
                insert_book();
                break;
            case 2:
                print_books();
                break;
            case 3:
                remove_book();
                break;
            case 4:
                print_sorted();
                break;
            case 5:
                write_file();
                printf("Thank you for using the library management system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5); // Repeat until the user chooses to exit
    return 0;
}

// Function to insert a new book record
void insert_book() {
    // Allocate memory for a new book record
    struct book *new_book = (struct book *)malloc(sizeof(struct book));
    if (new_book == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Ask the user to enter the information about the book
    printf("Enter the title of the book: ");
    scanf(" %[^\n]", new_book->title); // Read a string with spaces
    printf("Enter the author of the book: ");
    scanf(" %[^\n]", new_book->author);
    printf("Enter the year of the book: ");
    scanf("%d", &new_book->year);
    printf("Enter the price of the book: ");
    scanf("%lf", &new_book->price);

    // Insert the new book record at the beginning of the list
    new_book->next = head;
    head = new_book;

    // Display a confirmation message
    printf("A new record was created.\n");
}

// Function to print the list of all the available books based on the insertion order
void print_books() {
    // Check if the list is empty
    if (head == NULL) {
        printf("There are no books in the library.\n");
        return;
    }

    // Declare a pointer to traverse the list
    struct book *current = head;

    // Print a header
    printf("\nList of all the available books based on the insertion order:\n");
    printf("Title\t\t\tAuthor\t\t\tYear\tPrice\n");

    // Loop through the list and print each book record
    while (current != NULL) {
        printf("%s\t\t\t%s\t\t\t%d\t%.2f\n", current->title, current->author, current->year, current->price);
        current = current->next;
    }
}

// Function to remove a book from the library according to its title
void remove_book() {
    // Check if the list is empty
    if (head == NULL) {
        printf("There are no books in the library.\n");
        return;
    }

    // Declare a pointer to traverse the list and a pointer to store the previous node
    struct book *current = head;
    struct book *previous = NULL;

    // Ask the user to enter the title of the book to be removed
    char title[50];
    printf("Enter the title of the book to be removed: ");
    scanf(" %[^\n]", title);

    // Loop through the list and find the book record with the matching title
    while (current != NULL && strcmp(current->title, title) != 0) {
        previous = current;
        current = current->next;
    }

    // Check if the book record was found
    if (current == NULL) {
        printf("There is no book with that title in the library.\n");
        return;
    }

    // Remove the book record from the list
    if (previous == NULL) { // The book record is the first node
        head = current->next;
    }
    else { // The book record is not the first node
        previous->next = current->next;
    }

    // Free the memory allocated for the book record
    free(current);

    // Display a confirmation message
    printf("The book record was removed from the library.\n");
}

// Function to print all the books sorted from the oldest (publishing year) to the newest
void print_sorted() {
    // Check if the list is empty
    if (head == NULL) {
        printf("There are no books in the library.\n");
        return;
    }

    // Sort the list of books by year
    sort();

    // Declare a pointer to traverse the list
    struct book *current = head;

    // Print a header
    printf("\nList of all the books sorted from the oldest (publishing year) to the newest:\n");
    printf("Title\t\t\tAuthor\t\t\tYear\tPrice\n");

    // Loop through the list and print each book record
    while (current != NULL) {
        printf("%s\t\t\t%s\t\t\t%d\t%.2f\n", current->title, current->author, current->year, current->price);
        current = current->next;
    }
}

// Function to write all the book records to a file named library.txt sorted from the oldest to the newest
void write_file() {
    // Check if the list is empty
    if (head == NULL) {
        printf("There are no books in the library.\n");
        return;
    }

    // Sort the list of books by year
    sort();

    // Open a file named library.txt in write mode
    FILE *file = fopen("library.txt", "w");
    if (file == NULL) {
        printf("File opening failed.\n");
        return;
    }

    // Declare a pointer to traverse the list
    struct book *current = head;

    // Loop through the list and write each book record to the file
    while (current != NULL) {
        fprintf(file, "%s\t\t\t%s\t\t\t%d\t%.2f\n", current->title, current->author, current->year, current->price);
        current = current->next;
    }

    // Close the file
    fclose(file);

    // Display a confirmation message
    printf("All the book records were written to the file library.txt sorted from the oldest to the newest.\n");
}

// Function to swap two book records
void swap(struct book *a, struct book *b) {
    // Swap the title
    char temp_title[50];
    strcpy(temp_title, a->title);
    strcpy(a->title, b->title);
    strcpy(b->title, temp_title);

    // Swap the author
    char temp_author[50];
    strcpy(temp_author, a->author);
    strcpy(a->author, b->author);
    strcpy(b->author, temp_author);

    // Swap the year
    int temp_year = a->year;
    a->year = b->year;
    b->year = temp_year;

    // Swap the price
    double temp_price = a->price;
    a->price = b->price;
    b->price = temp_price;
}

// Function to sort the list of books by year
void sort() {
    // Declare two pointers to traverse the list
    struct book *current = head;
    struct book *next = NULL;

    // Loop through the list and compare each pair of adjacent book records
    while (current != NULL) {
        next = current->next;
        while (next != NULL) {
            // If the current book record has a later year than the next book record, swap them
            if (current->year > next->year) {
                swap(current, next);
            }
            next = next->next;
        }
        current = current->next;
    }
}