# Text Encryptor and Decryptor in C

This project is a simple text encryption and decryption program implemented in C. It uses a substitution cipher, where each letter in the plaintext is replaced by a letter from a key that consists of 26 unique alphabetic characters.

## Features

- **Key Validation**: Ensures the key is exactly 26 unique alphabetic characters.
- **Encrypt Messages**: Replaces plaintext characters using the substitution cipher.
- **Decrypt Messages**: Recovers the original message from a ciphertext using the same key.
- **Case Sensitivity**: Preserves the case (uppercase/lowercase) of letters during encryption and decryption.
- **Handles Non-Alphabetic Characters**: Leaves spaces, numbers, and special characters unchanged.


## Installation

To get a local copy of the project, follow these steps:

1. Clone the repository:
   git clone https://github.com/sarpaltinok/Text-Encryptor-and-Decryptor-in-C.git
2. Navigate to the project directory:
   gcc -o encrypt_decrypt main.c
3. Run the program:
   ./encrypt_decrypt

## Usage

- Enter a key (26 unique alphabetic characters).
- Choose to either encrypt or decrypt a message.
- Enter the message and get the output

### Example Key: QWERTYUIOPLKJHGFDSAZXCVBNM


## License
This project is licensed under the MIT License - see the LICENSE file for details.

 


