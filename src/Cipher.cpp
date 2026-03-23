#include "Cipher.h"
#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <set>

namespace Encryption
{
Cipher::Cipher(std::string secret) : m_secret(secret)
{
    std::transform(
        m_secret.begin(), 
        m_secret.end(), 
        m_secret.begin(), 
        ::toupper
    );
    createKey();
    createTransposedAlpha();
    std::cout << m_key;
}

void Cipher::createKey()
{
    std::set<std::string> key_set;
    auto secret_length = m_secret.length();
    for (auto i = 0; i < secret_length; i++)
    {
        std::string secret_char(1, m_secret[i]);
        if (Encryption::ALPHA.find(secret_char) != std::string::npos)
        {
            key_set.emplace(secret_char);
        }
    }
    for (const auto& str : key_set)
    {
        m_key += str;
    }
}

void Cipher::createTransposedAlpha()
{
    m_transposed_alpha = m_key;
    auto alpha_length = Encryption::ALPHA.length();
    for (auto i = 0; i < alpha_length; i++)
    {
        std::string ch(1, Encryption::ALPHA[i]);
        if (m_key.find(ch) == std::string::npos)
        {
            m_transposed_alpha += ch;
        }
    }
}

void Cipher::encrypt(std::string in_message, std::string &out_message)
{
    convertMessage(in_message, out_message, Encryption::ALPHA, m_transposed_alpha);
}

void Cipher::decrypt(std::string in_message, std::string &out_message)
{
    convertMessage(in_message, out_message, m_transposed_alpha, Encryption::ALPHA);
}

void Cipher::convertMessage(
    std::string &in_message, 
    std::string &out_message, 
    std::string alpha_a, 
    std::string alpha_b
)
{
    prepareMessages(in_message, out_message);
    auto msg_length = in_message.length();
    for (auto i = 0; i < msg_length; i++)
    {
        std::string ch(1, in_message[i]);
        if (alpha_a.find(ch) != std::string::npos)
        {
            auto alpha_index = alpha_a.find(ch);
            out_message += alpha_b[alpha_index];
        }
        else
        {
            out_message += ch;
        }
    }
}

void Cipher::prepareMessages(std::string &in_message, std::string &out_message)
{
    std::transform(
        in_message.begin(),
        in_message.end(),
        in_message.begin(),
        ::toupper
    );
    out_message = "";
}
}