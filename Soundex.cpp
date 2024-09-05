#include "Soundex.h"
#include <cctype>
#include <cstring>

char soundexValue[26];

char getSoundexCode(char c) 
{
    c = toupper(c);
    return soundexValue[c - 'A'];
}

void initializeSoundexCode()
{
    soundexValue['A' - 'A'] = soundexValue['E' - 'A'] = soundexValue['I' - 'A'] = soundexValue['O' - 'A'] = soundexValue['U' - 'A'] = '0';
    soundexValue['B' - 'A'] = soundexValue['F' - 'A'] = soundexValue['P' - 'A'] = soundexValue['V' - 'A'] = '1';
    soundexValue['C' - 'A'] = soundexValue['G' - 'A'] = soundexValue['J' - 'A'] = soundexValue['K' - 'A'] = soundexValue['Q' - 'A'] = soundexValue['S' - 'A'] = soundexValue['X' - 'A'] = soundexValue['Z' - 'A'] = '2';
    soundexValue['D' - 'A'] = soundexValue['T' - 'A'] = '3';
    soundexValue['L' - 'A'] = '4';
    soundexValue['M' - 'A'] = soundexValue['N' - 'A'] = '5';
    soundexValue['R' - 'A'] = '6';
    soundexValue['H' - 'A'] = soundexValue['W' - 'A'] = soundexValue['Y' - 'A'] = '*';
}

int isCodeNotVowel(char& code)
{
    return code != '0';
}

int isCodeNotRepetive(char& code)
{
    return code != '*';
}

int isCodeAndPrevCodeNotSame(char& code, char& prevCode)
{
    return code != prevCode;
}

void updateSoundex(std::string& soundex, char& code, char& prevCode)
{
    int isProperCode = isCodeNotVowel(code) * isCodeNotRepetive(code) * isCodeAndPrevCodeNotSame(code, prevCode);
    if (isProperCode)
    {
        soundex += code;
        prevCode = code;
    }
    if (code == '0')
    {
        prevCode = '0'; 
    }
}

std::string performSoundexCalculation(const std::string& name)
{
    initializeSoundexCode();
    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i)
    {
        char code = getSoundexCode(name[i]);
        updateSoundex(soundex, code, prevCode);
    }
    return soundex;
}

bool checkForEmpty(const std::string& name)
{
    return name.empty();
}

void padSoundex(std::string& soundex)
{
    while (soundex.length() < 4) 
    {
        soundex += '0';
    }
}

std::string generateSoundex(const std::string& name)
{
    if (checkForEmpty(name)) return "";

    std::string soundex = performSoundexCalculation(name);

    padSoundex(soundex);

    return soundex;
}
