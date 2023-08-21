#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int Row_Num=0;
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    total_number_of_books =(int*)calloc(total_number_of_shelves,sizeof(int));
    total_number_of_pages = (int**)calloc(total_number_of_shelves,sizeof(int*));
    for(Row_Num=0;Row_Num<total_number_of_shelves;Row_Num++){
        total_number_of_pages[Row_Num]=(int*)calloc(1100,sizeof(int));
    }
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
        
            int x, y;
            scanf("%d %d", &x, &y);

            total_number_of_books[x]++;
            int * book =total_number_of_pages[x];
            while(*book!=0){
                    book++;
            }
            *book = y;

        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}