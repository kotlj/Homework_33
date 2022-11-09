
#include <iostream>

using namespace std;

int main()
{
    char* text = new char[1000];
    gets_s(text, 1000);
    short countSymbs = 0;
    short countWords = 0;
    short countVowel = 0;
    short countConsn = 0;
    short countNumbs = 0;
    short countPuncM = 0;
    if (text[strlen(text) - 1] >= 65 && text[strlen(text) - 1] <= 90 && text[strlen(text) - 2] >= 65 && text[strlen(text) - 2] <= 90 ||
        text[strlen(text) - 1] >= 65 && text[strlen(text) - 1] <= 90 && text[strlen(text) - 2] >= 97 && text[strlen(text) - 2] <= 122 ||
        text[strlen(text) - 1] >= 97 && text[strlen(text) - 1] <= 122 && text[strlen(text) - 2] >= 97 && text[strlen(text) - 2] <= 122)
    {
        countWords++;
    }
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 65 && text[i] <= 90) //LowerCase
        {
            countSymbs++;
            if (text[i] >= 66 && text[i] <= 68 || text[i] >= 70 && text[i] <= 72 || text[i] >= 74 && text[i] <= 78 || text[i] >= 80 && text[i] <= 84 ||
                text[i] >= 86 && text[i] <= 88 || text[i] == 90)
            {
                countConsn++;
            }
            else
            {
                countVowel++;
            }
        }
        else if (text[i] >= 97 && text[i] <= 122) //UpperCase
        {
            countSymbs++;
            if (text[i] >= 98 && text[i] <= 100 || text[i] >= 102 && text[i] <= 104 || text[i] >= 106 && text[i] <= 110 || text[i] >= 112 && text[i] <= 116 ||
                text[i] >= 118 && text[i] <= 120 || text[i] == 122)
            {
                countConsn++;
            }
            else
            {
                countVowel++;
            }
        }
        else if (text[i] >= 48 && text[i] <= 57) //numbers
        {
            countSymbs++;
            countNumbs++;
        }
        if (text[i] > 32 && text[i] < 48 || text[i] > 57 && text[i] < 65 || text[i] > 90 && text[i] < 97 || text[i] > 122) // Words & Punctuation marks
        {
            countPuncM++;
            countSymbs++;
            if (text[i] != 45 && text[i] != 126 && text[i] != 32 && text[i - 1] >= 97 && text[i - 1] <= 122 && text[i - 2] >= 97 && text[i - 2] <= 122 ||
                text[i] != 45 && text[i] != 126 && text[i] != 32 && text[i - 1] >= 97 && text[i - 1] <= 122 && text[i - 2] >= 65 && text[i - 2] <= 90 ||
                text[i] != 45 && text[i] != 126 && text[i] != 32 && text[i - 1] >= 65 && text[i - 1] <= 90 && text[i - 2] >= 65 && text[i - 2] <= 90)
            {
                countWords++;
            }
            else if (text[i] == 45 && text[i - 2] >= 97 && text[i - 2] <= 122 && text[i - 3] >= 97 && text[i - 3] <= 122 ||
                text[i] == 45 && text[i - 2] >= 97 && text[i - 2] <= 122 && text[i - 3] >= 65 && text[i - 3] <= 90 ||
                text[i] == 126 && text[i - 2] >= 97 && text[i - 2] <= 122 && text[i - 3] >= 97 && text[i - 3] <= 122 ||
                text[i] == 126 && text[i - 2] >= 97 && text[i - 2] <= 122 && text[i - 3] >= 65 && text[i - 3] <= 90 ||
                text[i] == 45 && text[i - 2] >= 65 && text[i - 2] <= 90 && text[i - 3] >= 65 && text[i - 3] <= 90 ||
                text[i] == 126 && text[i - 2] >= 65 && text[i - 2] <= 90 && text[i - 3] >= 65 && text[i - 3] <= 90)
            {
                countWords++;
            }
        } 
        //Space is not a punctMak, so:
        else if (text[i] == 32 && text[i - 1] >= 97 && text[i - 1] <= 122 && text[i - 2] >= 97 && text[i - 2] <= 122 && text[i + 1] >= 97 && text[i + 1] <= 122 ||
            text[i] == 32 && text[i - 1] >= 97 && text[i - 1] <= 122 && text[i - 2] >= 60 && text[i - 2] <= 90 && text[i + 1] >= 97 && text[i + 1] <= 122 ||
            text[i] == 32 && text[i - 1] >= 65 && text[i - 1] <= 90 && text[i + 1] >= 65 && text[i + 1] <= 90 && text[i - 2] >= 60 && text[i - 2] <= 90)
        {
            countWords++;
        }
    }
    cout << "Symbols: " << countSymbs << "\n" << "Words: " << countWords << "\n" << "Vowels: " << countVowel << "\n" << "Consonants: " << countConsn << "\n"
        << "Numbers: " << countNumbs << "\n" << "Punctuation marks: " << countPuncM << "\n";
    delete[] text;
}