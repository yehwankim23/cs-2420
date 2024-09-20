// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// September 19, 2024

#include <vector>
#include <stdexcept>

#include "pch.h"
#include "Matrix.h"

struct MatrixTest : testing::Test {
    Matrix* matrix11 = new Matrix();
    Matrix* matrix12 = new Matrix();

    Matrix* matrix21 = new Matrix();
    Matrix* matrix22 = new Matrix();

    Matrix* matrix31 = new Matrix();
    Matrix* matrix32 = new Matrix();

    Matrix* matrix41 = new Matrix();
    Matrix* matrix42 = new Matrix();

    Matrix* matrix51 = new Matrix();

    void SetUp() {
        matrix11->setMatrix(
            {
                {1, 2, 3},
                {2, 4, 5},
                {3, 6, 8}
            }
        );

        matrix12->setMatrix(
            {
                {-1, 2, -3},
                {2, -4, 5},
                {-3, 6, -8}
            }
        );

        matrix21->setMatrix(
            {
                {2, 1},
                {4, 1}
            }
        );

        matrix22->setMatrix(
            {
                {2, 1},
                {3, 0},
                {5, 2}
            }
        );

        matrix31->setMatrix(
            {
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0}
            }
        );

        matrix32->setMatrix(
            {
                {-1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1}
            }
        );

        matrix41->setMatrix(
            {
                {10, 10, 10, 10, 10}
            }
        );

        matrix42->setMatrix(
            {
                {2},
                {2},
                {1},
                {1},
                {3}
            }
        );

        matrix51->setMatrix(
            {
                {-1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1}
            }
        );
    }

    void TearDown() {
        delete matrix11;
        delete matrix12;

        delete matrix21;
        delete matrix22;

        delete matrix31;
        delete matrix32;

        delete matrix41;
        delete matrix42;

        delete matrix51;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// addition tests
TEST_F(MatrixTest, AdditionTest1) {
    Matrix result = *matrix11 + *matrix12;

    std::vector<std::vector<int>> answer = {
        {0, 4, 0},
        {4, 0, 10},
        {0, 12, 0}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}

TEST_F(MatrixTest, AdditionTest2) {
    EXPECT_THROW(*matrix21 + *matrix22, std::invalid_argument);
}

TEST_F(MatrixTest, AdditionTest3) {
    Matrix result = *matrix31 + *matrix32;

    std::vector<std::vector<int>> answer = {
        {-1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}

TEST_F(MatrixTest, AdditionTest4) {
    EXPECT_THROW(*matrix41 + *matrix42, std::invalid_argument);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// subtraction tests
TEST_F(MatrixTest, SubtractionTest1) {
    Matrix result = *matrix11 - *matrix12;

    std::vector<std::vector<int>> answer = {
        {2, 0, 6},
        {0, 8, 0},
        {6, 0, 16}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}

TEST_F(MatrixTest, SubtractionTest2) {
    EXPECT_THROW(*matrix21 - *matrix22, std::invalid_argument);
}

TEST_F(MatrixTest, SubtractionTest3) {
    Matrix result = *matrix31 - *matrix32;

    std::vector<std::vector<int>> answer = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}
TEST_F(MatrixTest, SubtractionTest4) {
    EXPECT_THROW(*matrix41 - *matrix42, std::invalid_argument);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// multiplication tests
TEST_F(MatrixTest, MultiplicationTest1) {
    Matrix result = *matrix11 * *matrix12;

    std::vector<std::vector<int>> answer = {
        {-6, 12, -17},
        {-9, 18, -26},
        {-15, 30, -43}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}

TEST_F(MatrixTest, MultiplicationTest2) {
    EXPECT_THROW(*matrix21 * *matrix22, std::invalid_argument);
}

TEST_F(MatrixTest, MultiplicationTest3) {
    EXPECT_THROW(*matrix31 * *matrix32, std::invalid_argument);
}

TEST_F(MatrixTest, MultiplicationTest4) {
    Matrix result = *matrix41 * *matrix42;

    std::vector<std::vector<int>> answer = {
        {90}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// diagonal sum tests
TEST_F(MatrixTest, DiagonalSumTest1) {
    float diagonal_sum = matrix11->digonalSum();
    EXPECT_EQ(diagonal_sum, 13);
}

TEST_F(MatrixTest, DiagonalSumTest2) {
    EXPECT_THROW(matrix32->digonalSum(), std::invalid_argument);
}

TEST_F(MatrixTest, DiagonalSumTest3) {
    EXPECT_THROW(matrix41->digonalSum(), std::invalid_argument);
}

TEST_F(MatrixTest, DiagonalSumTest4) {
    float diagonal_sum = matrix51->digonalSum();
    EXPECT_EQ(diagonal_sum, -5);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// additional addition tests
TEST_F(MatrixTest, Addition1) {
    Matrix left;

    left.setMatrix(
        {
            {1, 2},
            {3, 4}
        }
    );

    Matrix right;

    right.setMatrix(
        {
            {5, 6},
            {7, 8}
        }
    );

    Matrix result = left + right;

    std::vector<std::vector<int>> answer = {
        {6, 8},
        {10, 12}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}

TEST_F(MatrixTest, Addition2) {
    Matrix left;

    left.setMatrix(
        {
            {-1, -2},
            {-3, -4}
        }
    );

    Matrix right;

    right.setMatrix(
        {
            {-5, -6},
            {-7, -8}
        }
    );

    Matrix result = left + right;

    std::vector<std::vector<int>> answer = {
        {-6, -8},
        {-10, -12}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// additional subtraction tests
TEST_F(MatrixTest, Subtraction1) {
    Matrix left;

    left.setMatrix(
        {
            {1, 2},
            {3, 4}
        }
    );

    Matrix right;

    right.setMatrix(
        {
            {5, 6},
            {7, 8}
        }
    );

    std::vector<std::vector<int>> answer = {
        {-4, -4},
        {-4, -4}
    };

    Matrix result = left - right;

    EXPECT_EQ(result.getMatrix(), answer);
}

TEST_F(MatrixTest, Subtraction2) {
    Matrix left;

    left.setMatrix(
        {
            {-1, -2},
            {-3, -4}
        }
    );

    Matrix right;

    right.setMatrix(
        {
            {-5, -6},
            {-7, -8}
        }
    );

    std::vector<std::vector<int>> answer = {
        {4, 4},
        {4, 4}
    };

    Matrix result = left - right;

    EXPECT_EQ(result.getMatrix(), answer);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// additional multiplication tests
TEST_F(MatrixTest, Multiplication1) {
    Matrix left;

    left.setMatrix(
        {
            {1, 2},
            {3, 4}
        }
    );

    Matrix right;

    right.setMatrix(
        {
            {5, 6},
            {7, 8}
        }
    );

    std::vector<std::vector<int>> answer = {
        {19, 22},
        {43, 50}
    };

    Matrix result = left * right;

    EXPECT_EQ(result.getMatrix(), answer);
}

TEST_F(MatrixTest, Multiplication2) {
    Matrix left;

    left.setMatrix(
        {
            {-1, -2},
            {-3, -4}
        }
    );

    Matrix right;

    right.setMatrix(
        {
            {-5, -6},
            {-7, -8}
        }
    );

    Matrix result = left * right;

    std::vector<std::vector<int>> answer = {
        {19, 22},
        {43, 50}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// additional diagonal sum tests
TEST_F(MatrixTest, DiagonalSum1) {
    Matrix matrix;

    matrix.setMatrix(
        {
            {1, 2},
            {3, 4}
        }
    );

    float diagonal_sum = matrix.digonalSum();
    EXPECT_EQ(diagonal_sum, 5);
}

TEST_F(MatrixTest, DiagonalSum2) {
    Matrix matrix;

    matrix.setMatrix(
        {
            {5, 6},
            {7, 8}
        }
    );

    float diagonal_sum = matrix.digonalSum();
    EXPECT_EQ(diagonal_sum, 13);
}
