#include <iostream.h>
#include <conio.h>
#include <alloc.h>
#include <stdlib.h> 

struct Book {
    int bookId;
    char title[50];
    char author[50];
    int quantity;
};

struct LibraryQueue {
    Book books[100];
    int front, rear;

    LibraryQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(const Book& book);
    void dequeue();
    void displayBooks();
};

void LibraryQueue::enqueue(const Book& book) {
    if (rear == 99) {
        cout << "Queue is full!";
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        books[rear] = book;
        cout << "\nBook added successfully!";
    }
}

void LibraryQueue::dequeue() {
    if (front == -1) {
        cout << "Queue is empty!";
    } else {
        cout << "\nBook deleted successfully!";
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void LibraryQueue::displayBooks() {
    if (front == -1) {
        cout << "Queue is empty!";
    } else {
        cout << "\nBook List:\n";
        cout << "--------------------------------------------------\n";
        cout << "ID\tTitle\t\tAuthor\t\tQuantity\n";
        cout << "--------------------------------------------------\n";

        for (int i = front; i <= rear; i++) {
            cout << books[i].bookId << "\t" << books[i].title << "\t\t" << books[i].author << "\t\t" << books[i].quantity << "\n";
        }

        cout << "--------------------------------------------------\n";
    }
}

int main() {
    int choice;
    LibraryQueue library;

    clrscr();

    while (1) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Delete Book\n";
        cout << "3. Display Books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1: {
                Book newBook;
                cout << "\nEnter Book ID: ";
                cin >> newBook.bookId;
                cout << "Enter Title: ";
                cin >> newBook.title;
                cout << "Enter Author: ";
                cin >> newBook.author;
                cout << "Enter Quantity: ";
                cin >> newBook.quantity;
                library.enqueue(newBook);
                break;
            }
            case 2:
                library.dequeue();
                break;
            case 3:
                library.displayBooks();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice!";
        }
    }
    return 0;
}