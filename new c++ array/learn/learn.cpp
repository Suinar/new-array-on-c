#include <iostream>
#include <typeinfo>
#include <cassert>
#include <array>
#define DEBUG

using namespace std;

template <typename T>
class Array
{
public:
	Array(T* ptr_array, int user_array_size)
	{
		assert(user_array_size > 0);
		array_size = user_array_size;
		array = new T[array_size];
		for (int i = 0; i < array_size; ++i)
		{
			array[i] = ptr_array[i];
		}
	}

	~Array() 
	{
		delete[] array;
	}


	void Swap_element(int swap_index_1, int swap_index_2)
	{
		assert(swap_index_1 >= 0 && swap_index_2 >= 0 && swap_index_1 != swap_index_2 && swap_index_1 < array_size && swap_index_2 < array_size);
		T temp;
		temp = array[swap_index_1];
		array[swap_index_1] = array[swap_index_2];
		array[swap_index_2] = temp;
	}

	void Array_resize(int new_size_array)
	{
		assert(new_size_array > 0 && new_size_array != array_size);
		T* new_array = new T[new_size_array];
		int min_size = (new_size_array > array_size) ? array_size : new_size_array;	
		for (int i = 0; i < min_size; ++i)
		{
			new_array[i] = array[i];
		}
		delete[] array;
		array = new_array;
		array_size = new_size_array;

	}

	void Array_info()
	{
		cout << "Array has size: " << array_size << endl;
		cout << "Array type is " << typeid(T).name() << endl;
	}

protected:
	T* array;
	int array_size;
};


class int_Array : public Array<int>
{
public:
	int_Array(int* ptr_int_array,int int_array_size)
		: Array<int>(ptr_int_array, int_array_size) {}


	int find_min_namber()
	{
		for (int i = 1; i < array_size;++i)
		{
			if (min_number > array[i])
			{
				min_number = array[i];
			}
		}
		return min_number;
	}

	int find_max_number()
	{
		for (int i = 1; i < array_size; ++i)
		{
			if (max_number < array[i])
			{
				max_number = array[i];
			}
		}
		return max_number;
	}

	void sort_array()
	{
		for (int i = 0; i < array_size - 1; ++i)
		{
			for (int j = 0; j < array_size - i - 1; ++j)
			{
				if (array[j] > array[j + 1])
				{
					int temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
	}

private:
	int min_number = array[0];
	int max_number = array[0];
};