/******************************************************************************
 * Not a matrix header test
 *
 *****************************************************************************/

#include "MATRIX!.h"

MATRIX_H_TYPE_DEF(3, 3);
MATRIX_H_ADD_DEF(3, 3);
MATRIX_H_PRINT_DEF(3, 3);
MATRIX_H_SUB_DEF(3, 3);
MATRIX_H_MUL_DEF(3, 3, 3);
MATRIX_H_SCALE_DEF(3, 3);
MATRIX_H_TRANSPOSE_DEF(3, 3);

MATRIX_H_TYPE_DEF(1, 3);
MATRIX_H_PRINT_DEF(1, 3);
MATRIX_H_TYPE_DEF(3, 1);
MATRIX_H_TYPE_DEF(1, 1);
MATRIX_H_PRINT_DEF(1, 1);
MATRIX_H_TRANSPOSE_DEF(1, 3);
MATRIX_H_MUL_DEF(1, 3, 1);
MATRIX_H_TYPE_DEF(4, 2);
MATRIX_H_ADD_DEF(4, 2);
MATRIX_H_PRINT_DEF(4, 2);

MATRIX_H_TYPE_DEF(2, 3);
MATRIX_H_TYPE_DEF(3, 4);
MATRIX_H_TYPE_DEF(2, 4);
MATRIX_H_MUL_DEF(2, 3, 4);
MATRIX_H_PRINT_DEF(2, 4);

int main() {
    Mat3x3 a = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f},
    };

    Mat3x3 b;
    Mat3x3_transpose(&a, &b);
    Mat3x3_print(&a);
    putchar('\n');
    Mat3x3_print(&b);
    putchar('\n');

    Mat4x2 c = {
        {1.0f, 5.0f},
        {2.0f, 6.0f},
        {3.0f, 7.0f},
        {4.0f, 8.0f},
    };

    Mat4x2 d = {
        {1.0f, 5.0f},
        {2.0f, 6.0f},
        {3.0f, 7.0f},
        {4.0f, 8.0f},
    };

    Mat3x3 res3x3;

    Mat3x3_add(&a, &b, &res3x3);

    Mat3x3 mul3x3;
    Mat3x3_mul_Mat3x3(&a, &b, &mul3x3);

    Mat3x3 sub3x3;
    Mat3x3_sub(&mul3x3, &res3x3, &sub3x3);

    Mat3x3_print(&res3x3);
    putchar('\n');
    Mat3x3_print(&mul3x3);
    putchar('\n');
    Mat3x3_print(&sub3x3);
    putchar('\n');

    Mat3x3 scale3x3;
    Mat3x3_scale(&sub3x3, 3, &scale3x3);

    Mat3x3_print(&scale3x3);
    putchar('\n');

    Mat2x3 e = {
        {2, 4, 6},
        {1, 3, 5},
    };
    Mat3x4 f = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {3, 6, 9, 12},
    };
    Mat2x4 mul2x4;
    Mat2x3_mul_Mat3x4(&e, &f, &mul2x4);
    Mat2x4_print(&mul2x4);
    putchar('\n');

    Mat4x2 res4x2;
    Mat4x2_add(&c, &d, &res4x2);
    Mat4x2_print(&res4x2);
    putchar('\n');

    Mat1x3 vec1 = {
        {1, 3, 5},
    };
    Mat1x3_print(&vec1);
    printf(".\n");
    Mat1x3 vec2 = {
        {3, 4, 7},
    };
    Mat1x3_print(&vec2);
    printf("=\n");

    Mat3x1 vec2tp;
    Mat1x3_transpose(&vec2, &vec2tp);

    Mat1x1 result;
    Mat1x3_mul_Mat3x1(&vec1, &vec2tp, &result);
    Mat1x1_print(&result);
}
