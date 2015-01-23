#ifndef ARABIC_ROMAN_H
#define ARABIC_ROMAN_H

std::string arabic_to_roman(uint32_t arabic, bool allow_subtractive = true);

uint32_t roman_to_arabic(std::string roman);

#endif
