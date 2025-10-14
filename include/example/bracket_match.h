//
// Created by KuroNeko359 on 2025/10/14.
//

#ifndef CSAPP_BRACKET_MATCH_H
#define CSAPP_BRACKET_MATCH_H
#include "types.h"

enum bracket {
    LEFT_PARENTHESIS,
    LEFT_SQUARE_BRACKET,
    LEFT_CURLY_BRACKET,
    RIGHT_PARENTHESIS,
    RIGHT_SQUARE_BRACKET,
    RIGHT_CURLY_BRACKET,
    INVALID_BRACKET
};

enum bracket parse_char(char str);

bool bracket_is_match(enum bracket left_bracket, enum bracket right_bracket);

#endif //CSAPP_BRACKET_MATCH_H