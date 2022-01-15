//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NAA
// Workshop:       1 (diy)
// Date:		   Jan 17, 2021
//==============================================

#include "cstring.h"

namespace sdds
{
	/*void strCpy(char* des, const char* src)
	{
		int count = strLen(src);

		for (int i = 0; i < count; ++i)
			des[i] = src[i];
		
		des[count] = '\0';
	}*/
	void strCpy(char* des, const char* src)
	{
		strnCpy(des, src, strLen(src));
		des[strLen(src)] = '\0';
	}
	
	void strnCpy(char* des, const char* src, int len)
	{
		int count = strLen(src);

		for (int i = 0; i < len; ++i)
			des[i] = src[i];

		if (len > count)
			des[len] = '\0';
	}
	
	/*int strCmp(const char* s1, const char* s2)
	{
		int flag = 0;

		for (int i = 0; s1[i] != '\0'; ++i)
			if (s1[i] > s2[i])
			{
				++flag;
				break;
			}
			else if (s1[i] < s2[i])
			{
				--flag;
				break;
			}

		return flag;
	}*/
	int strCmp(const char* s1, const char* s2)
	{
		return strnCmp(s1, s2, strLen(s1));
	}

	int strnCmp(const char* s1, const char* s2, int len)
	{
		int flag = 0;

		for (int i = 0; i < len; ++i)
			if (s1[i] > s2[i])
			{
				++flag;
				break;
			}
			else if (s1[i] < s2[i])
			{
				--flag;
				break;
			}

		return flag;
	}

	int strLen(const char* s)
	{
		int count = 0;

		for (int i = 0; s[i] != '\0'; ++i)
			++count;

		return count;
	}

	const char* strStr(const char* str1, const char* str2)
	{
		int index = 0;
		bool diff = false;

		for (int i = 0; str1[i] != '\0'; ++i)
			if (str1[i] == str2[0])
			{
				diff = strnCmp(&str1[i], str2, strLen(str2));
				if (!diff)
				{
					index = i;
					break;
				}
			}
		
		return (!diff) ? &str1[index] : nullptr;
	}

	void strCat(char* des, const char* src)
	{
		int srcLen = strLen(src), desLen = strLen(des);

		for (int i = desLen, j = 0; i < desLen + srcLen; ++i, ++j)
			des[i] = src[j];
			
		des[desLen + srcLen] = '\0';
	}
}