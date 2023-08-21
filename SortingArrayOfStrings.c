#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sort_by_length(const char* a, const char* b);
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int i = 0,var_a, var_b, num_a=0, num_b=0;
    if(a != 0){
        char *arr = (char *)calloc(256,sizeof(char));
        for(i = 0;i < strlen(a); i++){
            var_a = a[i] - '0';
            if(!arr[var_a]){
                num_a++;
                arr[var_a]++;
            }
        }
        free(arr);
    }
    if(b != 0){
        char *arr = (char *)calloc(256,sizeof(char));
        for(i = 0;i < strlen(b); i++){
            var_b = b[i] - '0';
            if(!arr[var_b]){
                num_b++;
                arr[var_b]++;
            }
        }
        free(arr);
    }
    if(num_a>num_b){
        return (1);
    }
    else if(num_a<num_b){
        return (-1);
    }
    else{
        return (lexicographic_sort(a,b));
    }
    
}

int sort_by_length(const char* a, const char* b) {
    int _a = strlen(a);
    int _b = strlen(b);
    if(_a>_b){
        return (1);
    }
    else if(_a<_b){
        return (-1);
    }
    else{
       return (lexicographic_sort(a,b));
    }

}
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int i=0,j=0,value_1;
    char* ptr;

    for(i = 1;i < len; i++){
        ptr = arr[i];
        for(j = i;j > 0; j--){
            if((cmp_func(arr[j-1],ptr))>0){
                arr[j]=arr[j-1];
            }
            else{break;}
        }
        arr[j]=ptr;
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}