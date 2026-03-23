#pragma once
#include <string>

namespace Encryption
{
class Cipher
{
public:
    explicit Cipher(std::string secret);
    void encrypt(std::string in_message, std::string &out_message);
    void decrypt(std::string in_message, std::string &out_message);
private:
    std::string m_secret;
    std::string m_key;
    std::string m_transposed_alpha;

    static const std::string& get_alpha();
    void createKey();
    void createTransposedAlpha();
    static void prepareMessages(std::string &in_message, std::string &out_message);
    static void convertMessage(
        std::string &in_message, 
        std::string &out_message, 
        const std::string& alpha_a,
        std::string alpha_b
    );
};
}
