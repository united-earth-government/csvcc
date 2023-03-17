/**
 * @file csvfile.hpp
 * @author united-earth-government
 * @brief
 * @version 0.1
 * @date 2023-02-07
 *
 * @copyright ueg (c) 2023
 *
 */

#ifndef CSVFILE_HPP
#define CSVFILE_HPP

#include <filesystem>
#include <fstream>
#include <iostream>

#include "csvrow.hpp"
#include "parse.hpp"

namespace csvcc
{

class csvfile
{
public:
    explicit csvfile() = default;
    explicit csvfile(std::string filename)
        : file_name(filename)
    {
    }
    explicit csvfile(const csvfile& rhs)       = default;
    csvfile& operator=(const csvfile& rhs)     = default;
    csvfile(csvfile&& src) noexcept            = default;
    csvfile& operator=(csvfile&& src) noexcept = default;
    virtual ~csvfile()                         = default;

    std::vector<csvrow> rows{};

    inline const std::size_t num_rows() const
    {
        return rows.size();
    }
    inline const std::size_t num_cols() const
    {
        if (num_rows() == 0)
        {
            return 0;
        }
        else
        {
            std::size_t init_row_size = rows[0].size();
            for (const csvrow& row : rows)
            {
                if (row.size() != init_row_size)
                {
                    std::cerr << "Number of data across different rows are not consistent"
                              << "\n";
                }
            }
            return init_row_size;
        }
    }

    inline const std::tuple<std::size_t, std::size_t> shape() const
    {
        return std::make_tuple(num_rows(), num_cols());
    }

    void read()
    {
        if (num_rows() != 0) {
            std::cout << "Warning! Current csvfile object may have already been initialized"
                      << "\n";
            return;
        }
        std::filesystem::path file_path = file_name;
        std::fstream          file{};

        file.open(file_path, std::ios::in);

        if (!file.is_open())
        {
            std::cout << "Failed to open file"
                      << "\n";
            return;
        }

        std::string line{};
        while (std::getline(file, line))
        {
            rows.push_back(csvcc::csvrow{csvcc::parse::split_str(line, ',')});
        }

        file.close();

        return;
    }

    inline void clear_data()
    {
        rows.clear();
    }

    const std::string& filename() const
    {
        return file_name;
    }

    std::string& filename()
    {
        return file_name;
    }

private:
    std::string file_name;
};

} // namespace csvcc

#endif // !CSVFILE_HPP
