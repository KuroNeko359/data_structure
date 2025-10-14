//
// Created by KuroNeko359 on 2025/10/14.
//
#include "example/bracket_match.h"


enum bracket parse_char(char str) {
    switch (str) {
        case '(': return LEFT_PARENTHESIS;
        case ')': return RIGHT_PARENTHESIS;
        case '[': return LEFT_SQUARE_BRACKET;
        case ']': return RIGHT_SQUARE_BRACKET;
        case '{': return LEFT_CURLY_BRACKET;
        case '}': return RIGHT_CURLY_BRACKET;
        default: return INVALID_BRACKET;
    }
}

bool bracket_is_match(enum bracket left_bracket, enum bracket right_bracket) {
    return (left_bracket + 3 == right_bracket);
}