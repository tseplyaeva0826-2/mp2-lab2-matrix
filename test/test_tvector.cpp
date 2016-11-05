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
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one) // &??????
{
	
	TVector<int> v(5,1);
	TVector<int> v1(5,15);
	
	for (int i = 0; i < 5; i++) v[i] = 2;
	v1 = v;

	EXPECT_EQ(v, v1);
}

TEST(TVector, copied_vector_has_its_own_memory) //    ????
{
  
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
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

TEST(TVector, throws_when_set_element_with_too_large_index)   //??
{
	TVector<int> v(4, 2);

	ASSERT_ANY_THROW(TVector<int> v(4, 3));
}

TEST(TVector, can_assign_vector_to_itself)
{
  ADD_FAILURE();
}

TEST(TVector, can_assign_vectors_of_equal_size)   //??
{
	int g, g1;
	TVector<int> v(4, 2);
	TVector<int> v1(4, 15);
	g = v.GetSize();
	g1 = v1.GetSize();

	EXPECT_EQ(g, g1);
}

TEST(TVector, assign_operator_change_vector_size)
{
  ADD_FAILURE();
}

TEST(TVector, can_assign_vectors_of_different_size) // &&&&&&&&
{
	int size1 = 4; int size2 = 5;
	TVector<int> v(size1, 2);
	TVector<int> v1(size2, 15);
	

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

	EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_vector_with_itself_return_true) //&&&&&&&&
{
	TVector<int> v1(4, 2);
	
	for (int i = 0; i < 4; i++)
	{
		v1[i] = 2; 
	}

	EXPECT_EQ(v1, v1);
}

TEST(TVector, vectors_with_different_size_are_not_equal) //&&&
{
	TVector<int> v1(4, 2);
	TVector<int> v2(6, 20);

	for (int i = 0; i < 4; i++)
	{
		v1[i] = 2;
	}


	ASSERT_NE(v1, v2);
}

TEST(TVector, can_add_scalar_to_vector) //&&&
{
	int n = 2;
	TVector<int> v1(4, 2);
	for (int i = 0; i < 4; i++)
	{
		v1[i] = v1[i] + n;
	}
	

	ASSERT_ANY_THROW(TVector<int> v1(4, 2));
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	int n = 2;
	TVector<int> v1(4, 2);
	for (int i = 0; i < 4; i++)
	{
		v1[i] = v1[i] - n;
	}


	ASSERT_ANY_THROW(TVector<int> v1(4, 2));
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	int n = 2;
	TVector<int> v1(4, 2);
	for (int i = 0; i < 4; i++)
	{
		v1[i] = v1[i]*n;
	}


	ASSERT_ANY_THROW(TVector<int> v1(4, 2));
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(6, 2);
	TVector<int> v2(6, 20);
	
	TVector<int> v3(6, 60);
	for (int i = 0; i < 6; i++)
	{
		v3[i] = v1[i] + v2[i];
	}

	ASSERT_ANY_THROW(TVector<int> v3(6,60));
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1;
	TVector<int> v2;
	int g1, g2;
	g1 = v1.GetSize();
	g2 = v2.GetSize();


	
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(6, 2);
	TVector<int> v2(6, 20);

	TVector<int> v3(6, 60);
	for (int i = 0; i < 6; i++)
	{
		v3[i] = v1[i] - v2[i];
	}

	ASSERT_ANY_THROW(TVector<int> v3(6, 60));
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  ADD_FAILURE();
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  ADD_FAILURE();
}

