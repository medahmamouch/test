#include <stdio.h>
#include <string.h>
#include "book.h"
#include "utils.h"
#include "menu.h"   /* اختياري إذا أردت */

Book library[MAX_BOOKS];
int book_count = 0;

void add_book(const char *title, const char *author, int year) {
    if (book_count >= MAX_BOOKS) {
        printf("⚠️ المكتبة ممتلئة!\n");
        return;
    }
    strcpy(library[book_count].title, title);
    strcpy(library[book_count].author, author);
    library[book_count].year = year;
    book_count++;
    printf("✅ تمت إضافة الكتاب بنجاح!\n");
}

void list_books() {
    if (book_count == 0) {
        printf("📭 لا توجد كتب.\n");
        return;
    }
    printf("\n📚 قائمة الكتب:\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d) %s - %s (%d)\n", i + 1,
               library[i].title,
               library[i].author,
               library[i].year);
    }
}

void search_book(const char *title) {
    for (int i = 0; i < book_count; i++) {
        if (strstr(library[i].title, title)) {
            printf("🔍 وُجد: %s - %s (%d)\n",
                   library[i].title,
                   library[i].author,
                   library[i].year);
            return;
        }
    }
    printf("❌ لم يتم العثور على كتاب بعنوان يحتوي: %s\n", title);
}
