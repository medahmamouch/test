#ifndef BOOK_H
#define BOOK_H

#define MAX_BOOKS 100
#define TITLE_LEN 50
#define AUTHOR_LEN 50

typedef struct {
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
} Book;

extern Book library[MAX_BOOKS];
extern int book_count;

// دوال إدارة الكتب
void add_book(const char *title, const char *author, int year);
void list_books();
void search_book(const char *title);

#endif
