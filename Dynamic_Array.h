#ifndef DYNAMIC_ARRAY_H_INCLUDED
#define DYNAMIC_ARRAY_H_INCLUDED
#include "stdafx.h"
#include<iterator>
#include<memory>
template<class T>
class myArray
{
	//member of data
private:
	int _nSize = 0;     
	T* _ptrData = nullptr; 
	int _ncapacity = 10;


protected:
	T* start;
	T* finish;
	T* end_of_storage;

	//member of function
public:
	//ctor
	myArray() :_ptrData(nullptr), _nSize(0) {}
	myArray(int m, T nvalue = 0) 
	{
		_nSize = m > 0 ? m : 1;
		_ptrData = new T[_nSize];

		for (int i = 0; i < _nSize;i++)
		{
			_ptrData[i] = nvalue;
		}

		start = _ptrData;
		finish = _ptrData + _nSize;
		end_of_storage = _ptrData + _nSize;
	}

	myArray(const myArray& obj)
	{

		_ptrData = new T[obj._nSize];
		for (int i = 0; i < obj._nSize; ++i)
		{
			_ptrData[i] = obj._ptrData[i];
		}

		_nSize = obj._nSize;
		start = obj.start;
		finish = obj.finish;
		end_of_storage = obj.end_of_storage;
	}

	myArray& operator=(const myArray& obj)
	{
		if (this->_ptrData == obj._ptrData) { return *this; }

		if (_ptrData) { delete[] _ptrData; _ptrData = nullptr; }
		//2.
		if (obj._ptrData != nullptr)
		{
			T* ptemp = new T[obj._nSize];
			for (int i = 0; i < obj._nSize; ++i)
			{
				ptemp[i] = obj._ptrData[i];
			}
			_ptrData = ptemp;
		}
		_nSize = obj._nSize;
		start = obj.start;
		finish = obj.finish;
		end_of_storage = obj.end_of_storage;
		return *this;
	}

	//dtor
	~myArray()
	{
		if (_ptrData)
		{
			delete[] _ptrData;
			_ptrData = nullptr;
		}
	}

public:
	//function
	int getLenth()const { return _nSize; }
	T& At(int npos)
	{
		if (npos < 0 || npos > _nSize - 1)
		{
			throw  1;
		}
		return _ptrData[npos];
	}
	T& operator[](int npos)
	{
		return _ptrData[npos];//5 [0,4]
	}

	void push_back(const T& value) {
		if (finish != end_of_storage) {
			//T* finish = new T(value);
			_ptrData[_nSize++] = value;
			++finish;
			//*finish = value;
		}
		else
		{
			const int old_size = _nSize;
			const int len = old_size != 0 ? 2 * old_size : 1;
			T* ptemp = new T[len];
			for (int i = 0; i < _nSize; ++i)
			{
				ptemp[i] = _ptrData[i];
			}
			ptemp[_nSize] = value;
			start = ptemp;
			finish = ptemp + (++_nSize);
			end_of_storage = ptemp + len;
			if (_ptrData)
			{
				delete[] _ptrData;
			}
			_ptrData = ptemp;
			ptemp = nullptr;
			_ncapacity = len;
		}
	}
	void judge_value(T& nvalue) {
		for (int i = 0; i < _nSize; ++i) {
			if (_ptrData[i] == nvalue)
			{
				cout <<"该元素在数组的下标是："<< i << endl;
				break;
			}
		}
	}

	void array_output() {
		for (int i = 0; i < _nSize; ++i)
		{
			cout << _ptrData[i] << "\t";
		}
		cout << endl;
	}
};

#endif // MYARRAY_H_INCLUDED


