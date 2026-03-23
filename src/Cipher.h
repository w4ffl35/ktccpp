#pragma once
#include <string>

namespace Encryption
{
const std::string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

class Cipher
{
public:
    Cipher(std::string secret);
    void encrypt(std::string in_message, std::string &out_message);
    void decrypt(std::string in_message, std::string &out_message);
private:
    std::string m_secret;
    std::string m_key = "";
    std::string m_transposed_alpha = "";
    
    void createKey();
    void createTransposedAlpha();
    void prepareMessages(std::string &in_message, std::string &out_message);
    void convertMessage(
        std::string &in_message, 
        std::string &out_message, 
        std::string alpha_a, 
        std::string alpha_b
    );
};
}