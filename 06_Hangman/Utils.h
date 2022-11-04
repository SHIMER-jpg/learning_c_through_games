

#ifndef __UTILS_H__
#define __UTILS_H__

enum CharCaseType{
    CC_UPPER_CASE=0,
    CC_LOWER_CASE=1,
    CC_EITHER=2
};

char GetCharacter(const char *prompt, const char *error);
char GetCharacter(const char *prompt, const char *error, const char validInput[], int validInputLength, CharCaseType charCase);

#endif