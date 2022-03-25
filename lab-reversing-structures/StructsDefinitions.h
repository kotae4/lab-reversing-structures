#pragma once

#include <format>
#include <iostream>
#include <string>

struct SimpleFieldsStruct
{
	unsigned char SmolIntVal = 191;
	short SmallIntVal = 18343;
	int IntVal = 2040683912;
	float FloatVal = 13.37f;
	__int64 BigIntVal = 8380392170516529805;
	const char CharArray[6] = "Hello";

	SimpleFieldsStruct()
	{
		std::cout << "SimpleFieldsStruct constructor called\n";
	}

	void PrintStruct()
	{
		int fields_size = sizeof(SmolIntVal) + sizeof(SmallIntVal) + sizeof(IntVal) + sizeof(FloatVal) + sizeof(BigIntVal) + sizeof(CharArray);
		int struct_size = sizeof(*this);

		std::string msg = std::format(
			"[{:#x}] SimpleFieldsStruct [fields size: {} bytes, struct size: {} bytes]:"
			"\n\t[{:#x}] SmolIntVal: {} [{} bytes]"
			"\n\t[{:#x}] SmallIntVal: {} [{} bytes]"
			"\n\t[{:#x}] IntVal: {} [{} bytes]"
			"\n\t[{:#x}] FloatVal: {} [{} bytes]"
			"\n\t[{:#x}] BigIntVal: {} [{} bytes]"
			"\n\t[{:#x}] CharArray: {} [{} bytes]"
		,reinterpret_cast<uintptr_t>(this), fields_size, struct_size,
			reinterpret_cast<uintptr_t>(&SmolIntVal), SmolIntVal, sizeof(SmolIntVal),
			reinterpret_cast<uintptr_t>(&SmallIntVal), SmallIntVal, sizeof(SmallIntVal),
			reinterpret_cast<uintptr_t>(&IntVal), IntVal, sizeof(IntVal),
			reinterpret_cast<uintptr_t>(&FloatVal), FloatVal, sizeof(FloatVal),
			reinterpret_cast<uintptr_t>(&BigIntVal), BigIntVal, sizeof(BigIntVal),
			reinterpret_cast<uintptr_t>(const_cast<char*>(&CharArray[0])), CharArray, sizeof(CharArray));

		std::cout << msg << std::endl;
	}
};

struct PointerStruct
{
	short* pSmallIntVal;
	int* pIntVal;
	float* pFloatVal;
	__int64* pBigIntVal;
	const char* pString;

	int* pIntArray;

	const char CharArray[14];

	PointerStruct() 
		: CharArray("PointerStruct")
	{
		pSmallIntVal = new short(30429);
		pIntVal = new int(1314748125);
		pFloatVal = new float(3.14159f);
		pBigIntVal = new __int64(7476263630889907933);
		pString = "HelloWorld";
		pIntArray = new int[8];
		for (int index = 0; index < 8; index++)
		{
			pIntArray[index] = (index + 1) * 113;
		}

		std::cout << "PointerStruct constructor called\n";
	}

	~PointerStruct()
	{
		delete pSmallIntVal;
		delete pIntVal;
		delete pFloatVal;
		delete pBigIntVal;
		delete[] pIntArray;
	}

	void PrintStruct()
	{
		int fields_size = sizeof(pSmallIntVal) + sizeof(pIntVal) + sizeof(pFloatVal) + sizeof(pBigIntVal) + sizeof(pString) + sizeof(pIntArray) + sizeof(CharArray);
		int struct_size = sizeof(*this);
		int total_allocated_bytes = struct_size + sizeof(*pSmallIntVal) + sizeof(*pIntVal) + sizeof(*pFloatVal) + sizeof(*pBigIntVal) + sizeof(*pString) + (sizeof(*pIntArray) * 8);

		std::string msg = std::format(
			"[{:#x}] PointerStruct [fields size: {} bytes, struct size: {} bytes, total allocated: {} bytes]:"
			"\n\t[{:#x}] pSmallIntVal: {} [{} bytes]"
			"\n\t[{:#x}] pIntVal: {} [{} bytes]"
			"\n\t[{:#x}] pFloatVal: {} [{} bytes]"
			"\n\t[{:#x}] pBigIntVal: {} [{} bytes]"
			"\n\t[{:#x}] pString: {} [{} bytes]"
			"\n\t[{:#x}] pIntArray: {} [{} bytes]"
			"\n\t[{:#x}] CharArray: {} [{} bytes]"
			, reinterpret_cast<uintptr_t>(this), fields_size, struct_size, total_allocated_bytes,
			reinterpret_cast<uintptr_t>(&pSmallIntVal), reinterpret_cast<uintptr_t>(pSmallIntVal), sizeof(pSmallIntVal),
			reinterpret_cast<uintptr_t>(&pIntVal), reinterpret_cast<uintptr_t>(pIntVal), sizeof(pIntVal),
			reinterpret_cast<uintptr_t>(&pFloatVal), reinterpret_cast<uintptr_t>(pFloatVal), sizeof(pFloatVal),
			reinterpret_cast<uintptr_t>(&pBigIntVal), reinterpret_cast<uintptr_t>(pBigIntVal), sizeof(pBigIntVal),
			reinterpret_cast<uintptr_t>(&pString), reinterpret_cast<uintptr_t>(const_cast<char*>(pString)), sizeof(pString),
			reinterpret_cast<uintptr_t>(&pIntArray), reinterpret_cast<uintptr_t>(pIntArray), sizeof(pIntArray),
			reinterpret_cast<uintptr_t>(const_cast<char*>(&CharArray[0])), CharArray, sizeof(CharArray));

		std::cout << msg << std::endl;
	}
};

struct StringsStruct
{
	const char CharArray[9] = "FirstStr";
	const char* pString = "SecondStr";

	StringsStruct()
	{
		std::cout << "StringsStruct constructor called\n";
	}

	void PrintStruct()
	{
		int fields_size = sizeof(CharArray) + sizeof(pString);
		int struct_size = sizeof(*this);
		int total_allocated_bytes = struct_size + (strlen(pString) + 1);

		std::string msg = std::format(
			"[{:#x}] PointerStruct [fields size: {} bytes, struct size: {} bytes, total allocated: {} bytes]:"
			"\n\t[{:#x}] pString: {} [{} bytes]"
			"\n\t[{:#x}] CharArray: {} [{} bytes]"
			, reinterpret_cast<uintptr_t>(this), fields_size, struct_size, total_allocated_bytes,
			reinterpret_cast<uintptr_t>(&pString), pString, sizeof(pString),
			reinterpret_cast<uintptr_t>(const_cast<char*>(&CharArray[0])), CharArray, sizeof(CharArray));

		std::cout << msg << std::endl;
	}
};

struct DerivedStruct : SimpleFieldsStruct
{
	int OtherIntVal;
	float OtherFloatVal;
	__int64 OtherBigIntVal;
	char OtherCharArray[14];

	DerivedStruct()
		: OtherCharArray("DerivedStruct")
	{
		OtherIntVal = 1155363548;
		OtherFloatVal = 6.626f;
		OtherBigIntVal = 2361300354103867101;

		std::cout << "DerivedStruct constructor called\n";
	}

	void PrintStruct()
	{
		int fields_size = sizeof(SmolIntVal) + sizeof(SmallIntVal) + sizeof(IntVal) + sizeof(FloatVal) + sizeof(BigIntVal) + sizeof(CharArray);
		int struct_size = sizeof(*this);

		std::string msg = std::format(
			"[{:#x}] DerivedStruct [fields size: {} bytes, struct size: {} bytes]:"
			"\n\t[{:#x}] SmolIntVal: {} [{} bytes]"
			"\n\t[{:#x}] SmallIntVal: {} [{} bytes]"
			"\n\t[{:#x}] IntVal: {} [{} bytes]"
			"\n\t[{:#x}] FloatVal: {} [{} bytes]"
			"\n\t[{:#x}] BigIntVal: {} [{} bytes]"
			"\n\t[{:#x}] CharArray: {} [{} bytes]"
			"\n\t[{:#x}] OtherIntVal: {} [{} bytes]"
			"\n\t[{:#x}] OtherFloatVal: {} [{} bytes]"
			"\n\t[{:#x}] OtherBigIntVal: {} [{} bytes]"
			"\n\t[{:#x}] OtherCharArray: {} [{} bytes]"
			, reinterpret_cast<uintptr_t>(this), fields_size, struct_size,
			reinterpret_cast<uintptr_t>(&SmolIntVal), SmolIntVal, sizeof(SmolIntVal),
			reinterpret_cast<uintptr_t>(&SmallIntVal), SmallIntVal, sizeof(SmallIntVal),
			reinterpret_cast<uintptr_t>(&IntVal), IntVal, sizeof(IntVal),
			reinterpret_cast<uintptr_t>(&FloatVal), FloatVal, sizeof(FloatVal),
			reinterpret_cast<uintptr_t>(&BigIntVal), BigIntVal, sizeof(BigIntVal),
			reinterpret_cast<uintptr_t>(const_cast<char*>(&CharArray[0])), CharArray, sizeof(CharArray),
			reinterpret_cast<uintptr_t>(&OtherIntVal), OtherIntVal, sizeof(OtherIntVal),
			reinterpret_cast<uintptr_t>(&OtherFloatVal), OtherFloatVal, sizeof(OtherFloatVal),
			reinterpret_cast<uintptr_t>(&OtherBigIntVal), OtherBigIntVal, sizeof(OtherBigIntVal),
			reinterpret_cast<uintptr_t>(const_cast<char*>(&OtherCharArray[0])), OtherCharArray, sizeof(OtherCharArray));

		std::cout << msg << std::endl;
	}
};

struct VirtualFuncStruct
{
	int IntVal;
	float FloatVal;
	__int64 BigIntVal;
	char CharArray[18];

	VirtualFuncStruct()
		: CharArray("VirtualFuncStruct")
	{
		IntVal = 789151249;
		FloatVal = 800.85f;
		BigIntVal = 0x7ff1985712515213;

		std::cout << "VirtualFuncStruct constructor called\n";
	}

	virtual void VirtualFuncOne()
	{
		std::cout << "VirtualFuncStruct::VirtualFuncOne called\n";
		IntVal += 8;
		return;
	}

	virtual bool VirtualFuncGetCondition()
	{
		std::cout << "VirtualFuncStruct::VirtualFuncGetCondition called\n";
		return false;
	}

	virtual int VirtualFuncAdd(int val1, int val2)
	{
		std::cout << "VirtualFuncStruct::VirtualFuncAdd called\n";
		return val1 - val2 + (val2 * 2);
	}

	void PrintStruct()
	{
		int fields_size = sizeof(IntVal) + sizeof(FloatVal) + sizeof(BigIntVal) + sizeof(CharArray);
		int struct_size = sizeof(*this);

		std::string msg = std::format(
			"[{:#x}] VirtualFuncStruct [fields size: {} bytes, struct size: {} bytes]:"
			"\n\t[{:#x}] IntVal: {} [{} bytes]"
			"\n\t[{:#x}] FloatVal: {} [{} bytes]"
			"\n\t[{:#x}] BigIntVal: {} [{} bytes]"
			"\n\t[{:#x}] CharArray: {} [{} bytes]"
			"\n\t[{:#x}] Virtual Method Table pointer: {} [{} bytes]"
			, reinterpret_cast<uintptr_t>(this), fields_size, struct_size,
			reinterpret_cast<uintptr_t>(&IntVal), IntVal, sizeof(IntVal),
			reinterpret_cast<uintptr_t>(&FloatVal), FloatVal, sizeof(FloatVal),
			reinterpret_cast<uintptr_t>(&BigIntVal), BigIntVal, sizeof(BigIntVal),
			reinterpret_cast<uintptr_t>(const_cast<char*>(&CharArray[0])), CharArray, sizeof(CharArray),
			reinterpret_cast<uintptr_t>(this), reinterpret_cast<uintptr_t>(this), sizeof(void*));

		std::cout << msg << std::endl;
	}
};

struct DerivedVirtualStruct : VirtualFuncStruct
{
	int IntVal;
	float FloatVal;
	__int64 BigIntVal;
	char CharArray[21];

	DerivedVirtualStruct()
		: CharArray("DerivedVirtualStruct")
	{
		IntVal = 189057125;
		FloatVal = 60054.137f;
		BigIntVal = 0xffbaaaaaaaaaaaaa;

		std::cout << "DerivedVirtualStruct constructor called\n";
	}

	bool VirtualFuncGetCondition() override
	{
		std::cout << "DerivedVirtualStruct::VirtualFuncGetCondition called\n";
		return true;
	}

	void PrintStruct()
	{
		int fields_size = sizeof(IntVal) + sizeof(FloatVal) + sizeof(BigIntVal) + sizeof(CharArray);
		int struct_size = sizeof(*this);

		std::string msg = std::format(
			"[{:#x}] DerivedVirtualStruct [fields size: {} bytes, struct size: {} bytes]:"
			"\n\t[{:#x}] IntVal: {} [{} bytes]"
			"\n\t[{:#x}] FloatVal: {} [{} bytes]"
			"\n\t[{:#x}] BigIntVal: {} [{} bytes]"
			"\n\t[{:#x}] CharArray: {} [{} bytes]"
			"\n\t[{:#x}] Virtual Method Table pointer: {} [{} bytes]"
			, reinterpret_cast<uintptr_t>(this), fields_size, struct_size,
			reinterpret_cast<uintptr_t>(&IntVal), IntVal, sizeof(IntVal),
			reinterpret_cast<uintptr_t>(&FloatVal), FloatVal, sizeof(FloatVal),
			reinterpret_cast<uintptr_t>(&BigIntVal), BigIntVal, sizeof(BigIntVal),
			reinterpret_cast<uintptr_t>(const_cast<char*>(&CharArray[0])), CharArray, sizeof(CharArray),
			reinterpret_cast<uintptr_t>(this), reinterpret_cast<uintptr_t>(this), sizeof(void*));

		std::cout << msg << std::endl;
	}
};