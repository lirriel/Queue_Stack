#ifndef _NICE_STACK_H_
#define _NICE_STACK_H_

#include <string>
#include <stdexcept>
#include <utility>
#include <vector>

//=============================================================================
//  ____          _          _                                     
// |    \ ___ ___| |_    ___| |_ ___ ___ ___ ___    _____ ___      
// |  |  | . |   |  _|  |  _|   | .'|   | . | -_|  |     | -_|     
// |____/|___|_|_|_|    |___|_|_|__,|_|_|_  |___|  |_|_|_|___|     
//                                      |___|                      
//=============================================================================

// �� ������ ���� ����!

using namespace std;

template <class T>
	class NiceStack
	{
	private:
		// ������ ������� NiceStack �� ���������
		// ������ � ������� ������� ������������ � ����������
		NiceStack(void) {}

		// ����������� ���� ��������� ����� - ���� <��������, �������-�����-����-���������-����>
		typedef std::pair<T,T> TypeElementStack;

		// ������ ��������� �����
		vector<TypeElementStack> storage;
		size_t m_capacity; // ����������� �����
		size_t iHead; // ������ ������ �����

	public:
		// ������� NiceStack � ������������ capacity
		NiceStack(size_t capacity);

		// ������� ��������� ��������� � �����
		size_t size() const;

		// ����������. ����� �� ��� ����������?
		~NiceStack(void);

		// �������� ����� �������
		// ��������� ���������� out_of_range ���� ���� ������
		void push (T newelement) throw (out_of_range);

		// ������� ������� �����.
		// ������������ �������� �������� �������� ����� �
		// ������� ������� ��������� �� �����
		// ��������� ���������� out_of_range ���� ���� ������
		T pop (void) throw (out_of_range);

		// ���������� ����������� ������� � �����
		T getMinimum(void) throw (out_of_range);


	};

#include "NiceStack.hpp"

#endif

