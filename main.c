#include <stdio.h>

#include "include/linearlist/seq_list.h"
void test(seq_list_type *x) {
    printf("%p",x);
}

int main() {
    int arr[3] = {1,2,3};
    seq_list_type *seq = seq_list_init(arr,3);
    printf("%p\n",seq);
    test(seq);

    return 0;
}
