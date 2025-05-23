/******************************************************************************
 * Not a header for matrices
 *
 * Use with care.
 *
 * #include "MATRIX!.h"
 *
 * MATRIX_H_TYPE_DEF(3, 3);
 * MATRIX_H_ADD_DEF(3, 3);
 * MATRIX_H_PRINT_DEF(3, 3);
 *
 * ...
 *
 * Mat3x3 matrix1 = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }, };
 * Mat3x3 matrix2 = { { 3, 2, 1 }, { 6, 5, 4 }, { 9, 7, 8 }, };
 *
 * Mat3x3 result;
 * Mat3x3_add(&matrix1, &matrix2, &result);
 * Mat3x3_print(&result);
 *
 * Do not declare these functions in an actual header.
 * Do not use MATRIX_H_***_DEF(...) inside of a scope.
 *
 *****************************************************************************/

#ifndef MATRIX_H
#define MATRIX_H

#ifndef MATRIX_H_FN
#ifndef MATRIX_H_INLINE_NONE
#define MATRIX_H_FN static inline
#else
#define MATRIX_H_FN static
#endif /* MATRIX_H_INLINE_NONE */
#endif /* MATRIX_H_FN */

#define MATRIX_H_TYPE_DEF(r, c) typedef float Mat##r##x##c[r][c];

#ifndef MATRIX_H_PRINT_NONE
#include <stdio.h>
#define MATRIX_H_PRINT_DEF(r, c)                                               \
    MATRIX_H_FN void Mat##r##x##c##_print(Mat##r##x##c * mat) {                \
        for (int i = 0; i < r; ++i) {                                          \
            printf("{");                                                       \
            for (int j = 0; j < c; ++j) {                                      \
                printf("%.2f, ", (*mat)[i][j]);                                \
            }                                                                  \
            printf("}\n");                                                     \
        }                                                                      \
    }
#else
#define MATRIX_H_PRINT_DEF(r, c)
#endif /* MATRIX_H_PRINT_NONE */

#define MATRIX_H_ADD_DEF(r, c)                                                 \
    MATRIX_H_FN void Mat##r##x##c##_add(                                       \
        Mat##r##x##c * mat1, Mat##r##x##c * mat2, Mat##r##x##c * target) {     \
        for (int i = 0; i < r; ++i)                                            \
            for (int j = 0; j < c; ++j)                                        \
                (*target)[i][j] = (*mat1)[i][j] + (*mat2)[i][j];               \
    }

#define MATRIX_H_SUB_DEF(r, c)                                                 \
    MATRIX_H_FN void Mat##r##x##c##_sub(                                       \
        Mat##r##x##c * mat1, Mat##r##x##c * mat2, Mat##r##x##c * target) {     \
        for (int i = 0; i < r; ++i)                                            \
            for (int j = 0; j < c; ++j)                                        \
                (*target)[i][j] = (*mat1)[i][j] - (*mat2)[i][j];               \
    }

#define MATRIX_H_SCALE_DEF(r, c)                                               \
    MATRIX_H_FN void Mat##r##x##c##_scale(Mat##r##x##c * mat, float s,         \
                                          Mat##r##x##c * target) {             \
        for (int i = 0; i < r; ++i)                                            \
            for (int j = 0; j < c; ++j)                                        \
                (*target)[i][j] = (*mat)[i][j] * s;                            \
    }

#define MATRIX_H_MUL_DEF(r1, c1, c2)                                           \
    MATRIX_H_FN void Mat##r1##x##c1##_mul_Mat##c1##x##c2(                      \
        Mat##r1##x##c1 * mat1, Mat##c1##x##c2 * mat2,                          \
        Mat##r1##x##c2 * target) {                                             \
        for (int i = 0; i < r1; ++i)                                           \
            for (int j = 0; j < c2; ++j) {                                     \
                (*target)[i][j] = 0;                                           \
                for (int k = 0; k < c1; ++k)                                   \
                    (*target)[i][j] += (*mat1)[i][k] * (*mat2)[k][j];          \
            }                                                                  \
    }

#define MATRIX_H_TRANSPOSE_DEF(r, c)                                           \
    MATRIX_H_FN void Mat##r##x##c##_transpose(Mat##r##x##c * mat,              \
                                              Mat##c##x##r * target) {         \
        for (int i = 0; i < r; ++i) {                                          \
            for (int j = 0; j < c; ++j) {                                      \
                (*target)[j][i] = (*mat)[i][j];                                \
            }                                                                  \
        }                                                                      \
    }

#endif /* MATRIX_H */
