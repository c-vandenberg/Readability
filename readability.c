#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int Letter_Count = 0;
int Word_Count = 0;
int Sentence_Count = 0;

int LetterCount(int n, string s);
int WordCount(int n, string s);
int SentenceCount(int n, string s);

int main(void)

// Prompt User for Text

{
    string s = get_string("Text: ");
    int n = strlen(s);

    LetterCount(n, s);
    WordCount(n, s);
    SentenceCount(n, s);

// Average Number of Letters per 100 Words

    float L = ((float) Letter_Count / (float)(Word_Count + 1)) * 100;

// Average Number of Sentences per 100 Words

    float S = ((float) Sentence_Count / (float)(Word_Count + 1)) * 100;

// Coleman-Liau Index

    int Index = round(((0.0588 * L) - (0.296 * S)) - 15.8);

// Output for User
    {
        if (Index < 1)
        {
            printf("Before Grade 1\n");
        }
        else if (Index > 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", Index);
        }
    }
    return 0;
}


// Count Letters Program

int LetterCount(int n, string s)

{
    for (int i = 0 ; i < n ; i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            Letter_Count++;
        }
    }
    return Letter_Count;
}

// Count Words Program

int WordCount(int n, string s)

{
    for (int j = 0 ; j < n ; j++)
    {
        if (s[j] == ' ' && s[j + 1] != ' ')
        {
            Word_Count++;
        }
    }
    return Word_Count;
}

// Count Sentences Program

int SentenceCount(int n, string s)

{
    for (int k = 0 ; k < n ; k++)
    {
        if (s[k] == '.' || s[k] == '!' || s[k] == '?')
        {
            Sentence_Count++;
        }
    }
    return Sentence_Count;
}


