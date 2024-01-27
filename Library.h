#pragma once
#ifndef CLASS_Library
#define CLASS_Library

#include "Table.h"

namespace Prog3 {
	class Library
	{
	private:
		Table lib;
	public:
		Library() = default;
		~Library() = default;
		void addNewPublication(book* newBook) {
			lib.addBook(newBook);
		}
		void giveCopies();
		void acceptCopies();
		std::string getTypeCipher();
		book* initialization(const book& newBook);
		void printAllPublications() const {
			lib.Print();
		}
		void getLiteratureCourses();
	};

	
	

}


#endif