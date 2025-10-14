#include <string.h>

#include "include/linearlist/static_stack.h"

#include "log.h"
#include "linearlist/dynamic_stack.h"


void test_static_stack() {
    static_stack *static_stack = static_stack_init(10);
    static_stack_push(static_stack, 1);
    static_stack_push(static_stack, 2);
    static_stack_push(static_stack, 3);
    static_stack_push(static_stack, 4);

    printf("%d\n", static_stack_pop(static_stack));
    printf("%d\n", static_stack_pop(static_stack));
    printf("%d\n", static_stack_pop(static_stack));
    printf("%d\n", static_stack_pop(static_stack));
    printf("%d\n", static_stack_pop(static_stack));
}

void test_dynamic_stack() {
    dynamic_stack *stack = dynamic_stack_init();
    dynamic_stack_push(stack, 1);
    dynamic_stack_push(stack, 2);
    dynamic_stack_push(stack, 3);
    printf("%d\n", dynamic_stack_pop(stack));
    printf("%d\n", dynamic_stack_pop(stack));
    printf("%d\n", dynamic_stack_pop(stack));

    if (dynamic_stack_is_empty(stack)) {
        printf("stack is empty");
    }
    printf("%d\n", dynamic_stack_pop(stack));
}

void test_reverse_string_using_stack() {
    char *str1 = "Hello!";
    printf("%s\n", str1);
    dynamic_stack *stack = dynamic_stack_init();
    for (int i = 0; i < strlen(str1); i++) {
        dynamic_stack_push(stack, str1[i]);
    }
    char str2[6];
    int str2_index = 0;
    while (!dynamic_stack_is_empty(stack)) {
        str2[str2_index] = dynamic_stack_pop(stack);
        str2_index++;
    }
    printf("%s\n", str2);
}

#include "example/bracket_match.h"

bool bracket_match(char *str1) {
    dynamic_stack *stack = dynamic_stack_init();
    for (int i1 = 0; i1 < strlen(str1); i1++) {
        enum bracket recent_bracket = parse_char(str1[i1]);
        if (recent_bracket == 6) continue;
        if (recent_bracket < 3) {
            dynamic_stack_push(stack, recent_bracket);
        } else if (recent_bracket >= 3 && recent_bracket < 6) {
            if (dynamic_stack_is_empty(stack)) {
                return false;
            }
            if (bracket_is_match(dynamic_stack_get_top(stack),
                                 recent_bracket)) {
                dynamic_stack_pop(stack);
            }
        }
    }
    return dynamic_stack_is_empty(stack);
}

void test_bracket_match() {
    char *str1 = "(1+2)+3)";
    char *str2 = "(){}[]";
    char *str3 = "[{(]})";
    if (bracket_match(str1)) {
        printf("bracket_matched 1\n");
    }
    if (bracket_match(str2)) {
        printf("bracket_matched 2\n");
    }
    if (bracket_match(str3)) {
        printf("bracket_matched 3\n");
    }
}


int main(int argc, char *argv[]) {
    test_bracket_match();
    return 0;
}
