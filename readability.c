/*
program that computes the approximate grade level needed to comprehend some text.
One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output what (U.S.) grade level is needed to understand the text.
The formula is:
index = 0.0588 * L - 0.296 * S - 15.8
L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Functions Declaration

int lettersCount(string text);
int wordsCount(string text);
int sentencesCount(string text);
float colemanLiau(string text);

// Main function

int main(void)
{
    string text = get_string("Text: ");
    float index = colemanLiau(text);

    if (index > 16.0)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1.0)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}

// Functions Implementation

// function counting letters in a given text

int lettersCount(string text)
{
    int count = 0;

    for (int i = 0; i < strlen(text); i++)
    {

        // Any character between A and Z is considered as a letter

        if (text[i] >= 'A' && text[i] <= 'z')
        {
            count++;
        }

    }

    return count;
}

// function counting words in a given text

int wordsCount(string text)
{
    int count = 0;

    // condition to initialize number of words by 1 in case the string is not empty only

    if (strlen(text) > 0)
    {
        count++;
    }

    // Any space added is indicating a new word in the text

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }

    return count;

}

// function counting sentences in a given text

int sentencesCount(string text)
{
    int count = 0;

    for (int i = 0; i < strlen(text); i++)
    {

        // Any period, exclamation mark or a question mark is considered ending the current sentence

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }

    }

    return count;
}

float colemanLiau(string text)
{
    // index = 0.0588 * L - 0.296 * S - 15.8
    // Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

    float index;
    float L, S;
    int letters = lettersCount(text);
    int words = wordsCount(text);
    int sentences = sentencesCount(text);
    L = (float)letters * 100 / words;
    S = (float)sentences * 100 / words;
    index = 0.0588 * L - 0.296 * S - 15.8;
    return index;

}