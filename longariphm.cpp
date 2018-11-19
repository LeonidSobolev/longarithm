#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_NUMBER_LEN 126

void input_big_number(char *number)
{
    char buffer[MAX_NUMBER_LEN];
    char i, j, k;

    fgets(buffer, MAX_NUMBER_LEN, stdin);

    if (buffer[strlen(buffer) - 1] != '\n') {
        exit(EXIT_FAILURE);
    }

    buffer[strlen(buffer) - 1] = '\0';

    k = strlen(buffer) - 1;
    for(i = k; i >= 0 ; i--) {
        number[k - i] = buffer[i] - '0';
    }
}

void output_big_number(char *number)
{
    char i, j, k;

    for(k = MAX_NUMBER_LEN - 1; number[k] == 0 && k > 0; k--);

    for(i = k; i >= 0; i--) {
        printf("%d", number[i]);
    }
}

void add_big_numbers(char* sum, const char *a, const char* b)
{
    char carry = 0;
    char w = 0;
    char t;
    char i, j, k;

    for (t = 0; t <= MAX_NUMBER_LEN; t++)
    {
        w = a[t] + b[t] + carry;
        carry = w / 10;
        sum[t] = w % 10;
    }
}

int main()
{
    char a[MAX_NUMBER_LEN];
    char b[MAX_NUMBER_LEN];
    char c[MAX_NUMBER_LEN];

    memset(a, 0, MAX_NUMBER_LEN);
    memset(b, 0, MAX_NUMBER_LEN);
    memset(c, 0, MAX_NUMBER_LEN);

    input_big_number(a);
    input_big_number(b);

    add_big_numbers(c, a, b);

    output_big_number(c);

    printf("\n");
    return 0;
}
