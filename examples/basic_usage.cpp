/**
 * @file basic_usage.cpp
 * @author united-earth-government
 * @brief
 * @version 0.1
 * @date 2023-02-07
 *
 * @copyright ueg (c) 2023
 *
 */

#include <cassert>
#include <iostream>
#include <string>

#include "csvfile.hpp"
#include "csvrow.hpp"

auto main(void) -> int
{
    static_assert(std::is_convertible<std::vector<std::string>, csvcc::csvrow>::value);

    csvcc::csvfile file("example_file.csv");

    assert(file.num_rows() == 0);
    assert(file.num_cols() == 0);

    file.read();

    for (const csvcc::csvrow& row : file.rows)
    {
        for (const std::string& cell : row.data)
        {
            std::cout << cell << ",";
        }
        std::cout << "\n";
    }

    // num_rows() and num_cols()
    std::cout << "number of rows: " << file.num_rows() << "\n";
    std::cout << "number of cols: " << file.num_cols() << "\n";

    // shape()
    std::cout << "number of rows using shape(): " << std::get<0>(file.shape()) << "\n";
    std::cout << "number of cols using shape(): " << std::get<1>(file.shape()) << "\n";

    // expecting a warning message to be printed to the terminal
    file.read();

    file.clear_data();

    assert(file.num_rows() == 0);
    assert(file.num_cols() == 0);

    return EXIT_SUCCESS;
}
