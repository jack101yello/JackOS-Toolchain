#include <stdlib.h>

void abort(void) {

}

void* malloc(uint32_t size) {
    void* ptr = (void*)0;
    asm volatile(
        "int $0x80"
        : "=c"(ptr)
        : "a"(MALLOC), "b"(size)
    );
    return ptr;
}

void free(void* ptr) {
    asm volatile(
        "int $0x80"
        :
        : "a"(FREE), "b"(ptr)
    );
    return;
}

int atexit(void (*)(void)) {
    return -1;
}

char* getenv(const char* msg) {
    return "\0";
}

void* calloc(uint32_t num, uint32_t size) {
    void* ptr = (void*)0;
    asm volatile(
        "int $0x80"
        : "=d"(ptr)
        : "a"(CALLOC), "b"(num), "c"(size)
    );
    return (void*)0;
}

int abs(int n) {
    return (n >= 0) ? n : -n;
}

int ctoi(const char c) {
    if(!isdigit((int)c)) return -1;
    return (int)((unsigned)c - '0');
}

extern double intpow(double, int);

long atol(const char* str) {
    long running_number = 0;
    int length = strlen(str);
    for(int i = 0; i < length; i++) {
        int digit = ctoi(str[i]);
        if(digit == -1) return -1;
        running_number += digit * intpow(10, length-i-1);
    }
    return running_number;
}

// Performs a binary search of a sorted array at base with nitems items to find the element key given a sorting function comparison.
void* bsearch(const void* key, const void* base, size_t nitems, size_t size, int(*comparison)(const void*, const void*)) {
    /* I solve this recursively, which seems satisfying I suppose,
    but I'm not convinced that this is the best way to binary search. */
    if(nitems == 0) return NULL;
    void* pivot = base + nitems/2; // There's nothing left to check
    if(comparison(key, pivot) == 0) { // We've found it!
        return pivot;
    }
    else if(comparison(key, pivot < 0)) { // The key is earlier than the pivot
        return bsearch(key, base, nitems/2, size, comparison);
    }
    // The key must be later than the pivot
    return bsearch(key, pivot, nitems/2, size, comparison);
}

int atoi(const char* str) {
    return (int)atol(str);
}

div_t div(int a, int b) {
    div_t result;
    result.quot = a/b;
    result.rem = a%b;
    return result;
}

ldiv_t ldiv(long a, long b) {
    ldiv_t result;
    result.quot = a/b;
    result.rem = a%b;
    return result;
}

long labs(long n) {
    return (n >= 0) ? n : -1*n;
}

int rand(void) {
    // This needs to be implemented, presumably by feeding a syscall for the PIT ticks into a hash function.
    return 4; // Technically a random number
}

void srand(unsigned n) {

}

// Returns 0 if the array is sorted and -1 otherwise
int check_sorted(void* arr, size_t count, size_t size, int(*comparison)(const void*, const void*)) {
    for(int i = 0; i < count-1; i++) {
        if(comparison(arr + i, arr + i + 1) > 0) return -1;
    }
    return 0;
}

// Swaps what two void* point to
void swap(void** x, void** y) {
    void* temp = *x;
    *x = *y;
    *y = temp;
}

// Sorts an array of size count, with elements of size size, according the the comparison function
void qsort(void* arr, size_t count, size_t size, int(*comparison)(const void*, const void*)) {
    while(check_sorted(arr, count, size, comparison) != 0) {
        for(int i = 0; i < count-1; i++) {
            if(comparison(arr + i, arr + i + 1) > 0) { // Need to be swapped
                swap(arr+i, arr+i+1);
            }
        }
    }
}

void* realloc(void* ptr, uint32_t size) {
    void* dest;
    asm volatile(
        "int $0x80"
        : "=d"(dest)
        : "a"(REALLOC), "b"(ptr), "c"(size)
    );
    return dest;
}

extern void _fini(void);
void exit(int status) {
    _fini();
    asm volatile(
        "int $0x80"
        :
        : "a"(0x5)
    );
    while(1);
}
