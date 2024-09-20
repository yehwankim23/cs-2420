// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// September 19, 2024

#include "gtest/gtest.h"
#include "Matrix.h"

#include <vector>
#include <stdexcept>

////////////////////////////////////////////////////////////////////////////////////////////////////
// provided test fixture
struct MatrixClass : testing::Test {
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
// provided addition tests
TEST_F(MatrixClass, ProvidedAdditionTest1) {
    Matrix result = *matrix11 + *matrix12;

    std::vector<std::vector<int>> answer = {
        {0, 4, 0},
        {4, 0, 10},
        {0, 12, 0}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}

TEST_F(MatrixClass, ProvidedAdditionTest2) {
    EXPECT_THROW(*matrix21 + *matrix22, std::invalid_argument);
}

TEST_F(MatrixClass, ProvidedAdditionTest3) {
    Matrix result = *matrix31 + *matrix32;

    std::vector<std::vector<int>> answer = {
        {-1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}

TEST_F(MatrixClass, ProvidedAdditionTest4) {
    EXPECT_THROW(*matrix41 + *matrix42, std::invalid_argument);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// provided subtraction tests
TEST_F(MatrixClass, ProvidedSubtractionTest1) {
    Matrix result = *matrix11 - *matrix12;

    std::vector<std::vector<int>> answer = {
        {2, 0, 6},
        {0, 8, 0},
        {6, 0, 16}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}

TEST_F(MatrixClass, ProvidedSubtractionTest2) {
    EXPECT_THROW(*matrix21 - *matrix22, std::invalid_argument);
}

TEST_F(MatrixClass, ProvidedSubtractionTest3) {
    Matrix result = *matrix31 - *matrix32;

    std::vector<std::vector<int>> answer = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}
TEST_F(MatrixClass, ProvidedSubtractionTest4) {
    EXPECT_THROW(*matrix41 - *matrix42, std::invalid_argument);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// provided multiplication tests
TEST_F(MatrixClass, ProvidedMultiplicationTest1) {
    Matrix result = *matrix11 * *matrix12;

    std::vector<std::vector<int>> answer = {
        {-6, 12, -17},
        {-9, 18, -26},
        {-15, 30, -43}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}

TEST_F(MatrixClass, ProvidedMultiplicationTest2) {
    EXPECT_THROW(*matrix21 * *matrix22, std::invalid_argument);
}

TEST_F(MatrixClass, ProvidedMultiplicationTest3) {
    EXPECT_THROW(*matrix31 * *matrix32, std::invalid_argument);
}

TEST_F(MatrixClass, ProvidedMultiplicationTest4) {
    Matrix result = *matrix41 * *matrix42;

    std::vector<std::vector<int>> answer = {
        {90}
    };

    EXPECT_EQ(result.getMatrix(), answer);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// provided diagonal sum tests
TEST_F(MatrixClass, ProvidedDiagonalSumTest1) {
    float diagonal_sum = matrix11->digonalSum();
    EXPECT_EQ(diagonal_sum, 13);
}

TEST_F(MatrixClass, ProvidedDiagonalSumTest2) {
    EXPECT_THROW(matrix32->digonalSum(), std::invalid_argument);
}

TEST_F(MatrixClass, ProvidedDiagonalSumTest3) {
    EXPECT_THROW(matrix41->digonalSum(), std::invalid_argument);
}

TEST_F(MatrixClass, ProvidedDiagonalSumTest4) {
    float diagonal_sum = matrix51->digonalSum();
    EXPECT_EQ(diagonal_sum, -5);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// additional addition tests
TEST_F(MatrixClass, AdditionalAdditionTest1) {
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

TEST_F(MatrixClass, AdditionalAdditionTest2) {
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
TEST_F(MatrixClass, AdditionalSubtractionTest1) {
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

TEST_F(MatrixClass, AdditionalSubtractionTest2) {
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
TEST_F(MatrixClass, AdditionalMultiplicationTest1) {
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

TEST_F(MatrixClass, AdditionalMultiplicationTest2) {
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
TEST_F(MatrixClass, AdditionalDiagonalSumTest1) {
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

TEST_F(MatrixClass, AdditionalDiagonalSumTest2) {
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
