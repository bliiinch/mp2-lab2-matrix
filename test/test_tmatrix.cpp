#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);
  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)//скопированная матрица равна исходной
{
    TDynamicMatrix<int> m(10);
    m[0][2] = 20;
    TDynamicMatrix<int> m1(m);
    EXPECT_EQ(20, m1[0][2]);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)//скопированная матрица имеет свою собственную память
{
    TDynamicMatrix<int> m(10);
    TDynamicMatrix<int> m1(m);
    m[0][2] = 20;
    EXPECT_EQ(0, m1[0][2]);
}

TEST(TDynamicMatrix, can_get_size)//может получить размер
{
    TDynamicMatrix<int> m(10);
    EXPECT_EQ(10, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)//можно установить и получить элемент
{
    TDynamicMatrix<int> m(4);
    m[0][2] = 20;    
    EXPECT_EQ(20, m[0][2]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)//выдает исключение при установке элемента с отрицательным индексом
{
    TDynamicMatrix<int>m(4);
    ASSERT_ANY_THROW(m.at(2).at(-10));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)//выдает исключение при установке элемента со слишком большим индексом
{
    TDynamicMatrix<int>m(4);
    ASSERT_ANY_THROW(m.at(2).at(5));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)//может назначить матрицу самому себе
{
    TDynamicMatrix<int> m(4);
    ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size) // может назначать матрицы одинакового размера
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(4);
    m[0][2] = 4;
    m1 = m;
    EXPECT_EQ(m[0][2], m1[0][2]);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)//назначить оператор изменить размер матрицы
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(8);
    m = m1;
    EXPECT_EQ(8, m.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)//может назначать матрицы разного размера
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(5);
    m[0][2] = 4;
    m1 = m;
    EXPECT_EQ(m[0][2], m1[0][2]);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)//сравнение равных матриц возвращает значение true
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(4);

    EXPECT_EQ(true, m == m1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)//сравните матрицу с самим собой, верните true
{
    TDynamicMatrix<int> m(4);
    EXPECT_EQ(true, m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)//матрицы с разным размером не равны
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(5);
    EXPECT_EQ(false, m == m1);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)//можно складывать матрицы одинакового размера
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m3;
    m[0][2] = 4;
    m1[0][2] = 4;
    m3 = m + m1;
    EXPECT_EQ(8, m3[0][2]);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)//не удается сложить матрицы с неодинаковым размером
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(5);
    m[0][2] = 4;
    m1[0][2] = 4;
    ASSERT_ANY_THROW(m + m1);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)//может вычитать матрицы одинакового размера
{
    TDynamicMatrix<int> m(4);
    TDynamicMatrix<int> m1(4);
    TDynamicMatrix<int> m3;
    m[0][2] = 4;
    m1[0][2] = 3;
    m3 = m - m1;
    EXPECT_EQ(1, m3[0][2]);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)//не удается вычесть матрицы с неодинаковым размером
{
    TDynamicMatrix<int> m(5);
    TDynamicMatrix<int> m1(4);
    m[0][2] = 4;
    m1[0][2] = 4;
    ASSERT_ANY_THROW(m - m1);
}

