// Design and implement a program, substitution, that encrypts messages using a substitution cipher.

#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Declarations

bool valid(string key);

// Main Function

int main(int argc, string argv[])
{
    string plaintext;
    string output;
    string key = argv[1];

    // program is executed without any command-line arguments or with more than one command-line argument, should print an error message.

    if (argc != 2)
    {
        printf("The program should be executed with a single argument provided.");
        return 1;
    }

    else
    {
        // the key is invalid  by not containing 26 characters.

        if (strlen(key) != 26)
        {
            printf("Key must contain 26 letters");
            return 1;
        }

        else
        {
            if (valid(key) == false)
            {
                printf("Invalid Key.");
                return 1;
            }

            else
            {
                plaintext = get_string("plaintext: ");
                string ciphertext = plaintext;

                for (int i = 0; i < strlen(plaintext); i++)
                {
                    if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
                    {
                        ciphertext[i] = key[(int)plaintext[i] - 65];

                        if (ciphertext[i] >= 'a' && plaintext[i] <= 'z')
                        {
                            ciphertext[i] -= 32;
                        }
                    }

                    else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
                    {
                        ciphertext[i] = key[(int)plaintext[i] - 97];

                        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
                        {
                            ciphertext[i] += 32;
                        }
                    }

                    else
                    {
                        ciphertext[i] = plaintext[i];
                    }
                }
                output = ciphertext;

            }
        }
    }
    printf("ciphertext: %s\n", output);
    return 0;
}

// Validating Input key.

bool valid(string key)
{
    char alphabet[26];
    for (char i = 'A'; i <= 'Z'; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (i == key[j] || (i + 32) == key[j])
            {
                break;
            }

            if (j == 25)
            {
                return false;
            }
        }
    }

    return true;

}