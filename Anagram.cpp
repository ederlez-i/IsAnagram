/*
Check if two strings are anagram
with classic method and frequency method.

*/

#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

bool IsAnagram(string text1, string text2);
bool IsAnagram2(string text1, string text2);


int main()
{
	string text1="aazrt";
	string text2="zarat";

	cout<<"Text 1:"<<text1.c_str()<<endl;
	cout<<"text 2:"<<text2.c_str()<<endl;
	
	if (IsAnagram2(text1,text2))
		cout<<"is anagram"<<endl<<endl;
	else
		cout<<"is not anagram"<<endl<<endl;
	return 0;
}

/*
Classic method. compare all characters of text1 with characters in text2
complexity is more than o(n). 
complexity of for is o(n), 
complexity of string::find() method is assumed o(n)
total complexity is o(n^2)
*/
bool IsAnagram(string text1, string text2)
{	
	string temp = text2;
	basic_string <char>::size_type indexCh;
	char space =' ';

	//anagram words have equal length
	if(text1.length() != text2.length())
		return false;

	//traverse first string
	for (int i=0;i < text1.length();i++)
	{	
		//check if second string includes char
		indexCh = temp.find(text1[i]); 
		if(indexCh == string::npos)
			return false;
		else
		{
			//remove found char from second string
			temp = temp.replace(indexCh,1,1,space); //substr can be used
		}
	}
	return true;

}

/*
implementation of frequency counter pattern. 
find frequency of all characreters in first string and second string
then compare frequency values. total o(n) complexity
*/

bool IsAnagram2(string text1, string text2)
{
	int hash[256]={0};
	int hash2[256]={0};

	//anagram words have equal length
	if(text1.length() != text2.length())
		return false;
	//character frequency of first string
	for (int i=0;i < text1.length();i++)
	{		
		hash[text1[i]]++;		
	}
	//character frequency of second string
	for (int i=0;i < text2.length();i++)
	{		
		hash2[text2[i]]++;		
	}

	//check if first string and second string have same frequency values
	for (int i=0;i < 256;i++)
	{		
		if(hash[i] != hash2[i])
			return false;
	}	
	return true;

}
