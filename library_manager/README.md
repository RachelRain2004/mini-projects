# Home Library Manager

A simple command-line program written in C that lets you manage your personal book collection. You can add, view, search, and delete books — and everything is saved to a file so your data stays even after closing the program.

---

## Features

- Add a book with title, author, genre, and description
- View your entire book collection
- Search for a book by title
- Delete a book by ID
- Data is saved permanently to a local file

---

## How to Run

### Requirements
- A C compiler (GCC recommended)

### Steps

1. Clone this repository or download the `.c` file
2. Open a terminal in the project folder
3. Compile the program:
   ```
   gcc library_manager.c -o library_manager
   ```
4. Run it:
   ```
   ./library_manager        (Mac / Linux)
   library_manager.exe      (Windows)
   ```

---

## Usage

When you run the program, you will see a menu:

```
--- My Home Library ---
1. Add a book
2. View all books
3. Search books
4. Delete a book
5. Exit
Enter choice:
```

Enter the number of the action you want to perform and follow the prompts.

---

## Data Storage

All book data is saved in a file called `library.dat` in the same folder as the program. This file is created automatically when you add your first book.

---

## Built With

- C (standard libraries: stdio.h, stdlib.h, string.h)

---

## License

This project is open source and available under the [MIT License](LICENSE).
