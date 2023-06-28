//#include "input.h"
//#include "gtest/gtest.h"
//#include <vector>
//
//std::vector<std::vector<int>> true_sudoku_field2 {{3, 9, 1, 2, 8, 6, 5, 7, 4},
//                                                  {4, 8, 7, 3, 5, 9, 1, 2, 6},
//                                                  {6, 5, 2, 7, 1, 4, 8, 3, 9},
//                                                  {8, 7, 5, 4, 3, 1, 6, 9, 2},
//                                                  {2, 1, 3, 9, 6, 7, 4, 8, 5},
//                                                  {9, 6, 4, 5, 2, 8, 7, 1, 3},
//                                                  {1, 4, 9, 6, 7, 3, 2, 5, 8},
//                                                  {5, 3, 8, 1, 4, 2, 9, 6, 7},
//                                                  {7, 2, 6, 8, 9, 5, 3, 4, 1}};
//
//
//TEST(InputTestSuite, CheckInput) {
//    freopen("input_emulation.txt", "r", stdin);
//    std::vector<std::vector<int>> field = parse_input_to_vector();
//    ASSERT_EQ(field.size(), 9);
//    ASSERT_EQ(field[0].size(), 9);
//    for (int i = 0; i < 9; ++i) {
//        for (int j = 0; j < 9; ++j) {
//            ASSERT_EQ(field[i][j], true_sudoku_field2[i][j]);
//        }
//    }
//}
