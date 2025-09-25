#include <stdio.h>
#include <string.h>
#include "book.h"
#include "utils.h"
#include "menu.h"   /* اختياري إذا أردت */

void show_menu() {
    int choice;
    char title[TITLE_LEN], author[AUTHOR_LEN];
    int year;

    do {
        printf("\n====== 📖 مكتبة بسيطة ======\n");
        printf("1. إضافة كتاب\n");
        printf("2. عرض جميع الكتب\n");
        printf("3. البحث عن كتاب\n");
        printf("0. خروج\n");
        printf("اختر: ");
        scanf("%d", &choice);
        getchar(); // تنظيف buffer

        switch (choice) {
            case 1:
                printf("أدخل العنوان: ");
                fgets(title, TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = 0;

                printf("أدخل المؤلف: ");
                fgets(author, AUTHOR_LEN, stdin);
                author[strcspn(author, "\n")] = 0;

                printf("أدخل سنة النشر: ");
                scanf("%d", &year);

                add_book(title, author, year);
                break;
            case 2:
                list_books();
                break;
            case 3:
                printf("أدخل كلمة من عنوان الكتاب: ");
                fgets(title, TITLE_LEN, stdin);
                title[strcspn(title, "\n")] = 0;
                search_book(title);
                break;
            case 0:
                printf("👋 وداعاً!\n");
                break;
            default:
                printf("❌ اختيار غير صحيح.\n");
        }
    } while (choice != 0);
}
