#include "Library.h"	

namespace Prog3 {
	void Library::getLiteratureCourses() {
		std::vector<std::string> Curse=lib.getCourses();
		 
		for (int i = 0; i < Curse.size(); i++) {
			std::cout << "Обеспеченый курс" << Curse[i];
		 }
	}
	void Library::giveCopies() {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите шифр" << std::endl;
		std::string vCipher = getNum();
		book* book = lib.findBook(vCipher);
		if (book != nullptr) {
			int copies = book->getCopies();
			if (copies >= 1) {
				book->setCopies(copies - 1);
			}
			else {
				std::cout << "Издание закончилось" << std::endl;
			}
		}
		else {
			std::cout << "Издание не найдено" << std::endl;
		}
	}
	void Library::acceptCopies() {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите шифр" << std::endl;
		std::string vCipher = getNum();
		book* book = lib.findBook(vCipher);
		if (book != nullptr ) {
			book->setCopies(book->getCopies() + 1);

		}
		else {
			std::cout << "Издание не найдено" << std::endl;
		}
	}
	std::string Library::getTypeCipher() {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите шифр" << std::endl;
		std::string vCipher = getNum();
		book* book = lib.findBook(vCipher);
		if (book != nullptr) {
			return book->getType_literature();
		}
		else
		{
			std::cout << "Издание не найдено" << std::endl;
		}
	}
	book* Library::initialization(const book& newBook) {
		if (newBook.getType_literature() == "Fictional") {			
			book* value = new Fictional(newBook);
			return value;
		}
		else if (newBook.getType_literature() == "Scientific") {
			book* value = new Scientific(newBook);
			return value;
		}
		else if (newBook.getType_literature() == "Educational") {
			book* value = new Educational(newBook);
			return value;
		}
		else {
			return nullptr;
		}
	}
}