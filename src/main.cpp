#include <iostream>
#include "Cipher.h"

int main()
{
    std::string in_secret;
    std::string in_message;
    std::string out_message = "";
    uint in_choice = 0;

    std::cout << "Enter secret key: ";
    std::cin >> in_secret;

    std::cout << "Enter message: ";
    std::cin >> in_message;
    
    auto cipher = Encryption::Cipher(static_cast<std::string>(in_secret));

    while (in_choice != 1 && in_choice != 2)
    {
        std::cout << "(1) Encrypt, (2) Decrypt: ";
        std::cin >> in_choice;
    }

    if (in_choice == 1)
    {
        cipher.encrypt(static_cast<std::string>(in_message), out_message);
    }
    else
    {
        cipher.decrypt(static_cast<std::string>(in_message), out_message);
    }

    std::cout << out_message;

    return 0;
}