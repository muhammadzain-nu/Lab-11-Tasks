#include <stdio.h>
#include <time.h>

// A simple struct to hold timestamp components
struct Timestamp {
    int year, month, day, hour, min, sec;
};

// Recursive function to print timestamp digits
void printNumber(int num, FILE *file) {
    if (num == 0) 
        return;
    printNumber(num / 10, file);
    fputc((num % 10) + '0', file);
}

int main() {
    FILE *file = fopen("log.txt", "a"); 

    if (!file) {
        printf("Could not open log.txt\n");
        return 1;
    }

    time_t t = time(NULL);
    struct tm *lt = localtime(&t);

    struct Timestamp ts;
    ts.year  = lt->tm_year + 1900;
    ts.month = lt->tm_mon + 1;
    ts.day   = lt->tm_mday;
    ts.hour  = lt->tm_hour;
    ts.min   = lt->tm_min;
    ts.sec   = lt->tm_sec;

    fprintf(file, "Run at: ");

    printNumber(ts.year, file);  fputc('-', file);
    printNumber(ts.month, file); fputc('-', file);
    printNumber(ts.day, file);   fputc(' ', file);

    printNumber(ts.hour, file);  fputc(':', file);
    printNumber(ts.min, file);   fputc(':', file);
    printNumber(ts.sec, file);

    fprintf(file, "\n");

    fclose(file);
    printf("Timestamp recorded in log.txt\n");
    return 0;
}

