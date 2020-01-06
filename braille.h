#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

int encode_character(const char ch, char *braille);

void encode(const char *plaintext, char *braille);

void print_braille(const char *braille, ostream &output);