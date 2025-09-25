#include <stdio.h>

#include "include/linearlist/seq_list.h"

int main() {
    //test init
    int arr[10] = {2,0,7,7,0,5,6,9,6,6};
    seq_list *seq = seq_list_init(arr, 10);
    //test print
    seq_print(seq);
    printf("%d\n",seq->size);
    //test add
    seq_add_elem(seq,1);
    printf("%d\n",seq->size);
    seq_print(seq);
    seq_add_elem(seq,2);
    seq_add_elem(seq,3);
    seq_print(seq);
    printf("%d\n",seq->size);
    //test append
    printf("1.seq->elem + seq->len : %d\n",*(seq->elem + seq->len));
    int arr2[5] = {1,3,5,7,9};
    seq_append_elems(seq,arr2,5);
    printf("2.seq->elem + seq->len : %d\n",*(seq->elem + seq->len));
    seq_print(seq);
    //test delete
    seq_delete_elem(seq,0);
    seq_print(seq);
    seq_delete_elem(seq,2);
    seq_print(seq);

    // test for
    printf("for:\n");
    int i;
    for (i = 0; i < seq->len; i ++) {
        printf("%d ",seq->elem[i]);
    }
    printf("\n");
    //end
    return 0;
}
