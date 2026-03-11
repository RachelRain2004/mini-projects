#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define DATA_FILE "library.dat"

struct Book {
    int id;
    char title[100];
    char author[80];
    char genre[50];
    char description[300];
};

struct Book library[MAX_BOOKS];
int book_count = 0;

void save_to_file() {
    FILE *fp = fopen(DATA_FILE, "wb");
    if (fp == NULL) {
        printf("Could not save data.\n");
        return;
    }
    fwrite(&book_count, sizeof(int), 1, fp);
    fwrite(library, sizeof(struct Book), book_count, fp);
    fclose(fp);
}

void load_from_file() {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (fp == NULL) return;
    fread(&book_count, sizeof(int), 1, fp);
    fread(library, sizeof(struct Book), book_count, fp);
    fclose(fp);
}

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }

    struct Book b;
    b.id = book_count + 1;

    printf("\nEnter Title       : ");
    fgets(b.title, 100, stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf("Enter Author      : ");
    fgets(b.author, 80, stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    printf("Enter Genre       : ");
    fgets(b.genre, 50, stdin);
    b.genre[strcspn(b.genre, "\n")] = '\0';

    printf("Enter Description : ");
    fgets(b.description, 300, stdin);
    b.description[strcspn(b.description, "\n")] = '\0';

    library[book_count] = b;
    book_count++;
    save_to_file();

    printf("\nBook added successfully! (ID: %d)\n", b.id);
}

void view_all_books() {
    if (book_count == 0) {
        printf("\nNo books in the library yet.\n");
        return;
    }

    printf("\n--- Your Library (%d books) ---\n", book_count);
    for (int i = 0; i < book_count; i++) {
        printf("\n[%d] %s\n", library[i].id, library[i].title);
        printf("    Author      : %s\n", library[i].author);
        printf("    Genre       : %s\n", library[i].genre);
        printf("    Description : %s\n", library[i].description);
    }
}

void search_books() {
    char keyword[100];
    printf("\nEnter title to search: ");
    fgets(keyword, 100, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strstr(library[i].title, keyword) != NULL) {
            printf("\n[%d] %s\n", library[i].id, library[i].title);
            printf("    Author      : %s\n", library[i].author);
            printf("    Genre       : %s\n", library[i].genre);
            printf("    Description : %s\n", library[i].description);
            found++;
        }
    }

    if (found == 0) {
        printf("No books found with that title.\n");
    }
}

void delete_book() {
    if (book_count == 0) {
        printf("\nNo books to delete.\n");
        return;
    }

    int id;
    printf("\nEnter the ID of the book to delete: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            printf("Deleting \"%s\"...\n", library[i].title);
            for (int j = i; j < book_count - 1; j++) {
                library[j] = library[j + 1];
            }
            book_count--;
            save_to_file();
            printf("Deleted successfully.\n");
            return;
        }
    }

    printf("No book found with ID %d.\n", id);
}

int main() {
    load_from_file();

    int choice;

    while (1) {
        printf("\n--- My Home Library ---\n");
        printf("1. Add a book\n");
        printf("2. View all books\n");
        printf("3. Search books\n");
        printf("4. Delete a book\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            add_book();
        } else if (choice == 2) {
            view_all_books();
        } else if (choice == 3) {
            search_books();
        } else if (choice == 4) {
            delete_book();
        } else if (choice == 5) {
            printf("Goodbye! Your library is saved.\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
