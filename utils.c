#include <stdio.h>
#include <string.h>
#include "book.h"
#include "utils.h"
#include "menu.h"   /* اختياري إذا أردت */

void clear_screen() {
    // يعمل على لينوكس
    printf("\033[H\033[J");
}
