#include <iostream>
#include <string>
#include <bitset>
#include <random>

using namespace std;

string encrypt(string message, string key) {
    string cipher_text = "";
    for (int i = 0; i < message.size(); i++) {
        // Convert each character to its ASCII value
        int plain_char = (int)message[i];
        int key_char = (int)key[i];
        // XOR the ASCII values of the characters
        int cipher_char = plain_char ^ key_char;
        // Convert the result back to a character and append to cipher_text
        cipher_text += (char)cipher_char;
    }
    return cipher_text;
}

string decrypt(string cipher_text, string key) {
    string plain_text = "";
    for (int i = 0; i < cipher_text.size(); i++) {
        // Convert each character to its ASCII value
        int cipher_char = (int)cipher_text[i];
        int key_char = (int)key[i];
        // XOR the ASCII values of the characters
        int plain_char = cipher_char ^ key_char;
        // Convert the result back to a character and append to plain_text
        plain_text += (char)plain_char;
    }
    return plain_text;
}

int main() {
    // Example usage
    string message = "hello world";
    string key = "";
    // Generate a random key of the same length as the message
    for (int i = 0; i < message.size(); i++) {
        key += (char)(rand() % 256); // Generate a random byte
    }
    string cipher_text = encrypt(message, key);
    cout << "Cipher text: " << cipher_text << endl;
    string plain_text = decrypt(cipher_text, key);
    cout << "Plain text: " << plain_text << endl;
    return 0;
}
