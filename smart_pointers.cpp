// smart_pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

template <typename T>
class SmartPointer
{
  public:
	  SmartPointer(T *ptr)
	  {
		  this->ptr = ptr;
		  cout << "Constructor invoked" << endl;
	  }
	  ~SmartPointer()
	  {
		  delete ptr;
		  cout << "Destructor invoked" << endl;
	  }
  private:
	T *ptr;
};

class Song {
public:
	Song(wstring str1, wstring str2)
	{
		this->duration_ = str1 + L" " + str2;
		cout << "Constructor of the Song class has been invoked" << endl;
		wcout << duration_ << endl;
	}
	~Song()
	{
		cout << "Destructor of the Song class has been invoked" << endl;
	}
	wstring duration_;
};

void UseRawPointer()
{
	// Using a raw pointer -- not recommended.
	Song* pSong = new Song(L"Nothing on You", L"Bruno Mars");

	// Use pSong...

	// Don't forget to delete!
	delete pSong;
}


void UseSmartPointer()
{
	// Declare a smart pointer on stack and pass it the raw pointer.
	unique_ptr<Song> song2(new Song(L"Nothing on You", L"Bruno Mars"));

	// Use song2...
	wstring s = song2->duration_;
	//...

} // song2 is deleted automatically here.


int main()
{
	{
		SmartPointer<int> ptr = new int(5);
	}
	UseSmartPointer();
	system("pause");
	//system("pause>null");
	return 0;
}

