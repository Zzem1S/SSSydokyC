#include "solve.h"
#include "utils.h"
#include "output.h"
#include "gtest/gtest.h"

#include <vector>

std::vector<std::vector<int>> true_sudoku_field {{3, 9, 1, 2, 8, 6, 5, 7, 4},
                                                 {4, 8, 7, 3, 5, 9, 1, 2, 6},
                                                 {6, 5, 2, 7, 1, 4, 8, 3, 9},
                                                 {8, 7, 5, 4, 3, 1, 6, 9, 2},
                                                 {2, 1, 3, 9, 6, 7, 4, 8, 5},
                                                 {9, 6, 4, 5, 2, 8, 7, 1, 3},
                                                 {1, 4, 9, 6, 7, 3, 2, 5, 8},
                                                 {5, 3, 8, 1, 4, 2, 9, 6, 7},
                                                 {7, 2, 6, 8, 9, 5, 3, 4, 1}};


TEST(SolveTestSuite, CheckSolve1) {
    std::vector<std::vector<int>> sudoku_field_1 = true_sudoku_field;
    sudoku_field_1[3][6] = 0;
    solve(sudoku_field_1);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            ASSERT_EQ(sudoku_field_1[i][j], true_sudoku_field[i][j]);
        }
    }
}

TEST(SolveTestSuite, CheckSolve2) {
    std::vector<std::vector<int>> sudoku_field_1 = true_sudoku_field;
    sudoku_field_1[2][1] = 0;
    sudoku_field_1[0][1] = 0;
    sudoku_field_1[3][7] = 0;
    sudoku_field_1[8][0] = 0;
    sudoku_field_1[7][2] = 0;
    sudoku_field_1[5][5] = 0;
    sudoku_field_1[4][8] = 0;
    solve(sudoku_field_1);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            ASSERT_EQ(sudoku_field_1[i][j], true_sudoku_field[i][j]);
        }
    }
}

TEST(SolveTestSuite, CheckSolveHalfEmptyField) {
    std::vector<std::vector<int>> sudoku_field_1 = true_sudoku_field;
    std::srand(42);
    for (int i = 0; i < 55; ++i) {
        int a = std::rand() % 9, b = std::rand() % 9;
        if (sudoku_field_1[a][b] != 0) {    // such statement to be sure that there are n distinct zeros in field
            sudoku_field_1[a][b] = 0;
        } else {
            --i;
        }
    }
    solve(sudoku_field_1);
    ASSERT_TRUE(is_valid_sudoku_field(sudoku_field_1));
}

//TEST(SolveTestSuite, CheckSolveEmptyField) {
//    std::vector<std::vector<int>> sudoku_field_1(9, std::vector<int>(9, 0));
//    solve(sudoku_field_1);
//    ASSERT_TRUE(is_valid_sudoku_field(sudoku_field_1));
//}

TEST(SolveTestSuite, CheckSolveInvalidInput) {
    std::vector<std::vector<int>> bad_input {{3, 9, 1, 2, 8, 6, 5, 7, 4}};
    ASSERT_THROW(solve(bad_input), std::invalid_argument);
}

TEST(SolveTestSuite, CheckGetPossibleValuesForCoordinates1) {
    std::vector<std::vector<int>> sudoku_field_1 = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    std::set<int> result = get_possible_values_for_coordinates(sudoku_field_1, 0, 0);
    std::set<int> expected_rslt = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ASSERT_EQ(result, expected_rslt);
}

TEST(SolveTestSuite, CheckGetPossibleValuesForCoordinates2) {
    std::vector<std::vector<int>> sudoku_field_1 = {{0, 1, 2, 3, 4, 5, 6, 7, 8},
                                                    {3, 5, 6, 0, 0, 0, 0, 0, 0},
                                                    {4, 7, 8, 0, 0, 0, 0, 0, 0},
                                                    {5, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {6, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {7, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {8, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {9, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {1, 0, 0, 0, 0, 0, 0, 0, 0}};
    std::set<int> result = get_possible_values_for_coordinates(sudoku_field_1, 0, 0);
    std::set<int> expected_rslt = {};
    ASSERT_EQ(result, expected_rslt);
}

TEST(SolveTestSuite, CheckGetPossibleValuesForCoordinates3) {
    std::vector<std::vector<int>> sudoku_field_1 = {{0, 1, 2, 3, 4, 5, 6, 7, 8},
                                                    {3, 5, 6, 0, 0, 0, 0, 0, 0},
                                                    {4, 7, 8, 0, 0, 0, 0, 0, 0},
                                                    {5, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {6, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {7, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {8, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {2, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {1, 0, 0, 0, 0, 0, 0, 0, 0}};
    std::set<int> result = get_possible_values_for_coordinates(sudoku_field_1, 0, 0);
    std::set<int> expected_rslt = {9};
    ASSERT_EQ(result, expected_rslt);
}

TEST(SolveTestSuite, CheckGetPossibleValuesForCoordinates4) {
    std::vector<std::vector<int>> sudoku_field_1 = {{0, 1, 2, 3, 4, 0, 6, 7, 8},
                                                    {3, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {4, 7, 8, 0, 0, 0, 0, 0, 0},
                                                    {5, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {7, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {8, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {2, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {1, 0, 0, 0, 0, 0, 0, 0, 0}};
    std::set<int> result = get_possible_values_for_coordinates(sudoku_field_1, 0, 0);
    std::set<int> expected_rslt = {9};
    ASSERT_EQ(result, expected_rslt);
}

TEST(SolveTestSuite, CheckGetPossibleValuesForCoordinates5) {
    std::vector<std::vector<int>> sudoku_field_1 = {{0, 1, 0, 3, 4, 0, 0, 7, 8},
                                                    {3, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {4, 7, 8, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {7, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {8, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {1, 0, 0, 0, 0, 0, 0, 0, 0}};
    std::set<int> result = get_possible_values_for_coordinates(sudoku_field_1, 0, 0);
    std::set<int> expected_rslt = {2, 5, 6, 9};
    ASSERT_EQ(result, expected_rslt);
}

TEST(SolveTestSuite, CheckGetPossibleValuesForCoordinates6) {
    std::vector<std::vector<int>> sudoku_field_1 = {{0, 1, 0, 3, 4, 0, 0, 7, 8},
                                                    {3, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {4, 7, 8, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {7, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {8, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                    {1, 0, 0, 0, 0, 0, 0, 0, 0}};
    ASSERT_THROW(get_possible_values_for_coordinates(sudoku_field_1, 9, 0), std::invalid_argument);
}