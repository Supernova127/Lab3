#pragma once
#ifndef CLASS_Table
#define CLASS_Table

#include "Fictional.h"
#include "Scientific.h"
#include "Educational.h"

namespace Prog3 {
	class Table
	{
	private:
		std::vector<book*> Books;
	public:
		Table() = default;
		Table(const Table& other) {
			copyBooks(other);
		}
		~Table() {
			clearBooks();
		}
		void addBook(book* newBook) {			
			Books.push_back(newBook);  
		}
		book* findBook(const std::string& cipher);
		void removeBook(const std::string& cipher);
		void Print()const;
		std::vector<std::string> getCourses();
		Table& operator=(const Table& other) {
			if (this != &other) {
				clearBooks();

				copyBooks(other);
			}
			return *this;
		}

		void clearBooks();
		void copyBooks(const Table& other);


	};





}










#endif