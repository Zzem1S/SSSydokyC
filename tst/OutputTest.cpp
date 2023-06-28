//
// Created by whoee on 20.06.2023.
//
#include "output.h"
#include "gtest/gtest.h"

std::vector<std::vector<int>> true_sudoku_field2 {{3, 9, 1, 2, 8, 6, 5, 7, 4},
                                                  {4, 8, 7, 3, 5, 9, 1, 2, 6},
                                                  {6, 5, 2, 7, 1, 4, 8, 3, 9},
                                                  {8, 7, 5, 4, 3, 1, 6, 9, 2},
                                                  {2, 1, 3, 9, 6, 7, 4, 8, 5},
                                                  {9, 6, 4, 5, 2, 8, 7, 1, 3},
                                                  {1, 4, 9, 6, 7, 3, 2, 5, 8},
                                                  {5, 3, 8, 1, 4, 2, 9, 6, 7},
                                                  {7, 2, 6, 8, 9, 5, 3, 4, 1}};

std::string string_sudoku_field = "3 9 1 2 8 6 5 7 4 \n"
                                  "4 8 7 3 5 9 1 2 6 \n"
                                  "6 5 2 7 1 4 8 3 9 \n"
                                  "8 7 5 4 3 1 6 9 2 \n"
                                  "2 1 3 9 6 7 4 8 5 \n"
                                  "9 6 4 5 2 8 7 1 3 \n"
                                  "1 4 9 6 7 3 2 5 8 \n"
                                  "5 3 8 1 4 2 9 6 7 \n"
                                  "7 2 6 8 9 5 3 4 1 \n";

TEST(OutputTestSuite, CheckOutputCorrectness1) {
    std::stringstream ss;
    print_sudoku_field(true_sudoku_field2, ss);
    ASSERT_EQ(ss.str(), string_sudoku_field);
}

TEST(OutputTestSuite, CheckOutputCorrectness2) {
    std::stringstream ss;
    std::vector<std::vector<int>> test_field;
    std::string expected_out;
    const int seed = 42;
    std::srand(seed);
    for (int i = 0; i < 9; i++) {
        test_field.push_back({});
        for (int j = 0; j < 9; j++) {
            int rand_int = std::rand() % 10;
            expected_out.push_back((char)(rand_int + '0'));
            expected_out.push_back(' ');
            test_field[i].push_back(rand_int);
        }
        expected_out.push_back('\n');
    }

    print_sudoku_field(test_field, ss);
    ASSERT_EQ(ss.str(), expected_out);
}

TEST(OutputTestSuite, CheckInvalidInput) {
    std::vector<std::vector<int>> bad_input {{3, 9, 1, 2, 8, 6, 5, 7, 4}};
    ASSERT_THROW(print_sudoku_field(bad_input), std::invalid_argument);
}