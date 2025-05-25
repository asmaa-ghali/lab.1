#include <stdio.h>
#include <stdlib.h>

static int counter_rec = 0;
static int counter_iter = 0;

void increment_counter(int *counter);
void reset_counter(int *counter);

long fibonacci(int n);
long fibonacci_mem(int n, long *T);
void init_tab(long *T, int n);
long fibonacci_iter_tab(int n);
long fibonacci_iter(int n);

void increment_counter(int *counter) {
    (*counter)++;
}

void reset_counter(int *counter) {
    *counter = 0;
}

long fibonacci(int n) {
    increment_counter(&counter_rec);
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

long fibonacci_mem(int n, long *T) {
    increment_counter(&counter_rec);
    if (n <= 1) return n;
    if (T[n] == -1)
        T[n] = fibonacci_mem(n - 1, T) + fibonacci_mem(n - 2, T);
    return T[n];
}

void init_tab(long *T, int n) {
    for (int i = 0; i <= n; i++) T[i] = -1;
    T[0] = 0;
    if (n > 0) T[1] = 1;
}

long fibonacci_iter_tab(int n) {
    if (n <= 1) return n;
    long *T = malloc((n + 1) * sizeof(long));
    T[0] = 0;
    T[1] = 1;
    for (int i = 2; i <= n; i++) {
        increment_counter(&counter_iter);
        T[i] = T[i - 1] + T[i - 2];
    }
    long result = T[n];
    free(T);
    return result;
}

long fibonacci_iter(int n) {
    if (n <= 1) return n;
    long a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        increment_counter(&counter_iter);
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int time_rec[20];
    int time_mem[20];
    int time_iter_tab[20];
    int time_iter[20];

    for (int i = 0; i < 20; i++) {
        reset_counter(&counter_rec);
        fibonacci(i);
        time_rec[i] = counter_rec;

        reset_counter(&counter_rec);
        long *T = malloc((i + 1) * sizeof(long));
        init_tab(T, i);
        fibonacci_mem(i, T);
        time_mem[i] = counter_rec;
        free(T);

        reset_counter(&counter_iter);
        fibonacci_iter_tab(i);
        time_iter_tab[i] = counter_iter;

        reset_counter(&counter_iter);
        long dummy = fibonacci_iter(i);
        time_iter[i] = counter_iter;
    }

    printf("n\ttime_rec\ttime_mem\ttime_iter_tab\ttime_iter\n");
    for (int i = 0; i < 20; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t\t%d\n", i, time_rec[i], time_mem[i], time_iter_tab[i], time_iter[i]);
    }

    return 0;
}
