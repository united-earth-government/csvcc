/**
 * @file csvrow.hpp
 * @author united-earth-government
 * @brief
 * @version 0.1
 * @date 2023-02-07
 *
 * @copyright ueg (c) 2023
 *
 */

#ifndef CSVROW_HPP
#define CSVROW_HPP

#include <string>
#include <vector>

namespace csvcc
{

struct csvrow
{
    explicit csvrow()                        = default;
    explicit csvrow(const csvrow& rhs)       = default;
    csvrow& operator=(const csvrow& rhs)     = default;
    csvrow(csvrow&& src) noexcept            = default;
    csvrow& operator=(csvrow&& src) noexcept = default;
    virtual ~csvrow()                        = default;

    csvrow(const std::vector<std::string>& external_data)
        : data(external_data)
    {
    }

    std::vector<std::string> data;

    const std::string& operator[](std::size_t index) const
    {
        return data[index];
    }

    std::string& operator[](std::size_t index)
    {
        return data[index];
    }

    const std::size_t size() const
    {
        return data.size();
    }
};

} // namespace csvcc

#endif // !CSVROW_HPP
