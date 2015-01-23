#include <string>
#include <vector>
#include <memory>

using namespace std;

typedef struct {
    uint16_t arabic;
    string roman;
    bool subtractive;
} roman_number;

typedef vector<roman_number> Romans;

static shared_ptr<Romans> sorted_roman_numbers() {
    static roman_number known[] = {
        {1, "I", false},
        {4, "IV", true},
        {5, "V", false},
        {9, "IX", true},
        {10, "X", false},
        {40, "XL", true},
        {50, "L", false},
        {90, "XC", true},
	{100, "C", false},
        {400, "CD", true},
	{500, "D", false},
        {900, "CM", true},
	{1000, "M", false},       
    }; 
    static shared_ptr<Romans> res = make_shared<Romans>(
        Romans(known, known + sizeof(known) / sizeof(roman_number)));
    return res;
}

string arabic_to_roman(uint32_t arabic, bool allow_subtractive /*= true*/) {
    string result;
    Romans romans = *sorted_roman_numbers().get();
    size_t romans_count = romans.size();
    while (arabic > 0) {
        for (int i = romans_count - 1; i >=0; --i) {
            if (arabic >= romans[i].arabic 
            && (allow_subtractive || !romans[i].subtractive)) {
                arabic -= romans[i].arabic;
                result.append(romans[i].roman);
                break;
            } 
	}
    }
    return result;
}

uint32_t roman_to_arabic(string roman) {
    size_t pos = 0;
    const size_t len = roman.length();

    uint32_t arabic = 0;
    
    Romans romans = *sorted_roman_numbers().get();
    size_t romans_count = romans.size();

    while (pos < len) {
        for (int i = romans_count - 1; i >=0; --i) {
            if (romans[i].roman == roman.substr(pos, romans[i].roman.length())) {
                arabic += romans[i].arabic;
                pos += romans[i].roman.length();
            }
        }
    }

    return arabic;
}
