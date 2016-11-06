#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-3));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -3));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);
  TVector<int> v1(10);
  v1 = v;

  ASSERT_NO_THROW(v=v1);
}

TEST(TVector, copied_vector_is_equal_to_source_one) // &?
{
	int n;
	TVector<int> v(n);
	TVector<int> v1(n);
	
	for (int i = 0; i < n; i++) v[i] = 2;
	v1 = v;

	EXPECT_EQ(v, v1);
}

TEST(TVector, copied_vector_has_its_own_memory) //    ????
{
	int n;
	TVector<int> v1(n);
	TVector<int> v2(n);
	for (int i = 0; i < n; i++) v1[i] = 1;
	v2 = v1;
	v1[0] = 2;
	EXPECT_NE(v1[0], v2[0]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
	int n, m;
  TVector<int> v(n,m);

  EXPECT_EQ(m, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)  //&&
{
	ASSERT_ANY_THROW(TVector<int> v(4, -2));
}

TEST(TVector, throws_when_set_element_with_too_large_index)   //?? проверь
{
	TVector<int> v(4);

	ASSERT_ANY_THROW(v[5]);
}

TEST(TVector, can_assign_vector_to_itself)  ///&&&&&&&&&&&&
{
	int n;
	TVector<int> v(n);
	for (int i = 1; i < n; i++) v[i] = 0;
	v = v;
	ASSERT_NO_THROW(TVector<int> v(n));
}

TEST(TVector, can_assign_vectors_of_equal_size)   //??
{ 
	int g;
	TVector<int> v(g);
	TVector<int> v1(g);

	ASSERT_NO_THROW(TVector<int> v(g), TVector<int> v2(g));
}

TEST(TVector, assign_operator_change_vector_size) //&&&&
{
	int n, m;
	TVector<int> v1(n), v2(m);
	v2 = v1;
	EXPECT_NE(m, v2.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size) // &&&&&&&&
{
	int size1 = 4; int size2 = 5;
	TVector<int> v(size1);
	TVector<int> v1(size2);
	

	for (int i = 0; i < size1; i++)
	{
		v[i] = 2;
	}
	v1=v;

	EXPECT_NE(0, v1[1]);
	EXPECT_NE(0,v1[2] );

}

TEST(TVector, compare_equal_vectors_return_true) //&&&&
{
	TVector<int> v1(4, 2);
	TVector<int> v2(4, 15);
	for (int i = 0; i < 4; i++)
	{
		v1[i] = 2; v2[i] = 2;
	}

	EXPECT_EQ(1,(v1==v2));
}

TEST(TVector, compare_vector_with_itself_return_true) //&&&&&&&&
{
	TVector<int> v1(4, 2);
	
	for (int i = 0; i < 4; i++)
	{
		v1[i] = 2; 
	}

 	EXPECT_EQ(1,(v1== v1));
}

TEST(TVector, vectors_with_different_size_are_not_equal) //&&&
{
	TVector<int> v1(4);
	TVector<int> v2(6);

	for (int i = 0; i < 4; i++)
	{
		v1[i] = 2;
	}
	for (int i = 0; i < 6; i++)
	{
		v2[i] = 2;
	}


	EXPECT_NE(v1, v2);
}

TEST(TVector, can_add_scalar_to_vector) //&&&
{
	int n = 2;
	int g;
	TVector<int> v1(g);
	for (int i = 0; i < g; i++)
	{
		v1[i] = v1[i] + n;
	}
	
	ASSERT_NO_THROW(v1+n);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	int n = 2;
	int g;
	TVector<int> v1(g);
	for (int i = 0; i < g; i++)
	{
		v1[i] = v1[i] - n;
	}

	ASSERT_NO_THROW(v1-n);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	int n = 2;
	int g;
	TVector<int> v1(g);
	for (int i = 0; i < g; i++)
	{
		v1[i] = v1[i] * n;
	}

	ASSERT_NO_THROW(v1*n);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	int n;
	TVector<int> v1(n);
	TVector<int> v2(n);
	
	TVector<int> v3(n);
	for (int i = 0; i < n; i++)
	{
		v3[i] = v1[i] + v2[i];
	}

	ASSERT_NO_THROW(TVector<int> v3(n));
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(4);
	TVector<int> v2(5);
	TVector<int> v3(5);
	v3 = v1 + v2;

	ASSERT_ANY_THROW(TVector<int> v3(5));

}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	int n;
	TVector<int> v1(n);
	TVector<int> v2(n);

	TVector<int> v3(n);
	v3 = v1 - v2;

	ASSERT_NO_THROW(TVector<int> v3(n));
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(4);
	TVector<int> v2(5);
	TVector<int> v3(5);
	v3 = v1 - v2;

	ASSERT_ANY_THROW(TVector<int> v3(5));
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	int n, k;
	k = 0;
	TVector<int> v1(n);
	TVector<int> v2(n);
	for (int i = 1; i < n; i++) k = k + v1[i] + v2[i];
	
	ASSERT_NO_THROW(k);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	int n,m, k;
	k = 0;
	TVector<int> v1(n);
	TVector<int> v2(m);
	for (int i = 1; i < n; i++) k = k + v1[i] + v2[i]; //?
	ASSERT_ANY_THROW(v1*v2);
}

