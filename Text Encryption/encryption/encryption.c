#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// Prototype
bool is_valid_key(char *key);
void encrypt_message(char *plaintext, char *key);
void decrypt_message(char *ciphertext, char *key);

int main(void)
{
    // Get the encryption key from the user
    char key[27];
    printf("Key: ");
    scanf("%s", key);

    // Checks
    if (!is_valid_key(key))
    {
        printf("Invalid key! Make sure it's 26 unique alphabetic characters.\n");
        return 1; // Exit on error
    }

    // Ask if the user wants to encrypt or decrypt a message
    int choice;
    printf("Choose an option:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        char plaintext[256];
        printf("Enter the message to encrypt: ");
        scanf(" %[^\n]", plaintext); // Get the plaintext from the user
        encrypt_message(plaintext, key); // Encrypt the message
    }
    else if (choice == 2)
    {
        char ciphertext[256];
        printf("Enter the message to decrypt: ");
        scanf(" %[^\n]", ciphertext); // Get the ciphertext from the user
        decrypt_message(ciphertext, key); // Decrypt the message
    }
    else
    {
        printf("Invalid choice! Please select 1 or 2.\n");
        return 1; // Exit on error
    }

    return 0;
}

// Key validation function
bool is_valid_key(char *key)
{
    // Check if the key has 26 characters
    if (strlen(key) != 26)
        return false;

    // Check if the key contains only letters and all letters are unique
    bool seen[26] = {false};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
            return false; // Invalid if any character is not a letter
        int index = toupper(key[i]) - 'A'; // Convert letter to index
        if (seen[index])
            return false; // Invalid if the letter is repeated
        seen[index] = true; // Mark the letter as seen
    }

    return true; // Valid key
}

// Encryption function
void encrypt_message(char *plaintext, char *key)
{
    char ciphertext[256];
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
                ciphertext[i] = key[plaintext[i] - 'A']; // For uppercase letters
            else
                ciphertext[i] = tolower(key[plaintext[i] - 'a']); // For lowercase letters
        }
        else
        {
            ciphertext[i] = plaintext[i]; // Leave non-letters unchanged
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; // Add null terminator
    printf("Encrypted message: %s\n", ciphertext);
}

// Decryption function
void decrypt_message(char *ciphertext, char *key)
{
    char plaintext[256];
    for (int i = 0; ciphertext[i] != '\0'; i++)
    {
        if (isalpha(ciphertext[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (toupper(ciphertext[i]) == key[j])
                {
                    if (isupper(ciphertext[i]))
                        plaintext[i] = 'A' + j; // Decrypt to uppercase
                    else
                        plaintext[i] = 'a' + j; // Decrypt to lowercase
                    break;
                }
            }
        }
        else
        {
            plaintext[i] = ciphertext[i]; // Leave non-letters unchanged
        }
    }
    plaintext[strlen(ciphertext)] = '\0'; // Add null terminator
    printf("Decrypted message: %s\n", plaintext);
}
