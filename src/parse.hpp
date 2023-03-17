/**
 * @file parse.hpp
 * @author united-earth-government
 * @brief
 * @version 0.1
 * @date 2023-02-06
 *
 * @copyright ueg (c) 2023
 *
 */

#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

namespace csvcc
{
namespace parse
{

std::vector<std::string> split_str(const std::string& input, const char delimiter = ',')
{
    std::vector<std::string> tokens{};
    std::stringstream        ss(input);
    std::string              token;
    while (std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

} // namespace parse
} // namespace csvcc

#endif // !PARSE_HPP
