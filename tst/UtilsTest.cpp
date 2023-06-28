#include "utils.h"
#include "gtest/gtest.h"

#include <vector>

std::vector<std::vector<int>> true_sudoku_field1 {{3, 9, 1, 2, 8, 6, 5, 7, 4},
                                                 {4, 8, 7, 3, 5, 9, 1, 2, 6},
                                                 {6, 5, 2, 7, 1, 4, 8, 3, 9},
                                                 {8, 7, 5, 4, 3, 1, 6, 9, 2},
                                                 {2, 1, 3, 9, 6, 7, 4, 8, 5},
                                                 {9, 6, 4, 5, 2, 8, 7, 1, 3},
                                                 {1, 4, 9, 6, 7, 3, 2, 5, 8},
                                                 {5, 3, 8, 1, 4, 2, 9, 6, 7},
                                                 {7, 2, 6, 8, 9, 5, 3, 4, 1}};

TEST(UtilsTestSuite, TestGetColumnSize) {
    auto column1 = get_column(true_sudoku_field1, 0);
    ASSERT_EQ(column1.size(), 9);
}

TEST(UtilsTestSuite, TestGetColumnPrecision) {
    auto column1 = get_column(true_sudoku_field1, 0);
    std::vector<int> expected_column {3, 4, 6, 8, 2, 9, 1, 5, 7};
    ASSERT_EQ(column1.size(), 9);
    for (int i = 0; i < column1.size(); ++i) {
        ASSERT_EQ(column1[i], expected_column[i]);
    }
}

TEST(UtilsTestSuite, is_valid_row_working_correctly_for_different_sizes_of_row) {
    std::vector<int> row {1, 2, 3};
    ASSERT_EQ(is_valid_row(row), false);
}

TEST(UtilsTestSuite, is_valid_row_working_correctly_true) {
    std::vector<int> row {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ASSERT_EQ(is_valid_row(row), true);
}

TEST(UtilsTestSuite, is_valid_row_working_correctly_false) {
    std::vector<int> row {1, 1, 3, 4, 5, 6, 7, 8, 9};
    ASSERT_EQ(is_valid_row(row), false);
}

