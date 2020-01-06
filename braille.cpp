#include "braille.h"
using namespace std;

int encode_character(const char ch, char *braille) {
    strcpy(braille, "");
    if (isdigit(ch))
        strcat(braille, "..OOOO");

    if (isupper(ch))
        strcat(braille, ".....O");
    

    switch (tolower(ch)) {
        case '1':
        case 'a': strcat(braille, "O....."); break;
        case '2':
        case 'b': strcat(braille, "OO...."); break;
        case '3':
        case 'c': strcat(braille, "O..O.."); break;
        case '4':
        case 'd': strcat(braille, "O..OO."); break;
        case '5':
        case 'e': strcat(braille, "O...O."); break;
        case '6':
        case 'f': strcat(braille, "OO.O.."); break;
        case '7':
        case 'g': strcat(braille, "OO.OO."); break;
        case '8':
        case 'h': strcat(braille, "OO..O."); break;
        case '9':
        case 'i': strcat(braille, ".O.O.."); break;
        case '0':
        case 'j': strcat(braille, ".O.OO."); break;
        case 'k': strcat(braille, "O.O..."); break;
        case 'l': strcat(braille, "OOO..."); break;
        case 'm': strcat(braille, "O.OO.."); break;
        case 'n': strcat(braille, "O.OOO."); break;
        case 'o': strcat(braille, "O.O.O."); break;
        case 'p': strcat(braille, "OOOO.."); break;
        case 'q': strcat(braille, "OOOOO."); break;
        case 'r': strcat(braille, "OOO.O."); break;
        case 's': strcat(braille, ".OOO.."); break;
        case 't': strcat(braille, ".OOOO."); break;
        case 'u': strcat(braille, "O.O..O"); break;
        case 'v': strcat(braille, "OOO..O"); break;
        case 'w': strcat(braille, ".O.OOO"); break;
        case 'x': strcat(braille, "O.OO.O"); break;
        case 'y': strcat(braille, "O.OOOO"); break;
        case 'z': strcat(braille, "O.O.OO"); break;
        case '.': strcat(braille, ".O..OO"); break;
        case ',': strcat(braille, ".O...."); break;
        case ';': strcat(braille, ".OO..."); break;
        case '-': strcat(braille, "..O..O"); break;
        case '!': strcat(braille, ".OO.O."); break;
        case '?': strcat(braille, ".OO..O"); break;
        case '(':
        case ')': strcat(braille, ".OO.OO"); break;
    }

    return strlen(braille);
}

void encode(const char *str, char *braille) {
    if (str[0] == '\0')
        return;

    int size = encode_character(str[0], braille);
    encode(str+1, braille+size);
}

void print_braille(const char *str, ostream &output) {
    char braille[512];
    encode(str, braille);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < strlen(braille); j+=3) {
            output << braille[i+j];
            if (j % 2 != 0)
                output << " ";
        }
        output << endl;
    }

    for (int i = 0; i < strlen(str); ++i) {
        if (isupper(str[i]) || isdigit(str[i]))
            output << "   ";

        output << str[i] << "  ";
    }

    output << endl;
}