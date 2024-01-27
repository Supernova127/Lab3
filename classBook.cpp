#pragma once
#include "classBook.h"

namespace Prog3 {
	std::string getNum() {
		std::string str;
		while (true) {
			std::getline(std::cin, str);
			if (std::cin.eof()) // обнаружен конец файла
				throw std::runtime_error("Не удалось прочитать строку EOF");
			else if (std::cin.bad()) // обнаружена невосстановимая ошибка входного потока
				throw std::runtime_error(std::string("Не удалось прочитать номер: "));
			// прочие ошибки (неправильный формат ввода) либо число не входит в заданный диапазон
			else if (std::cin.fail()) {
				std::cin.clear(); // очищаем флаги состояния потока
				// игнорируем все символы до конца строки
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Ошибка ввода. Повторите ввод " << std::endl;
			}
			else // успешный ввод
				return str;
		}
	}


	void book::initialization() {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введите фамилию автора " << std::endl; Name = getNum(); std::cout << "Введите  название издания " << std::endl; edition = getNum();
		std::cout << "Введите год и издательсво" << std::endl; year_publisher = getNum();
		std::cout << "Введите количество экземпляров " << std::endl; copies = getNum<int>(0); 
		setTypeLiterature();
		cipher += Name[0]; cipher += edition[0]; cipher += year_publisher[0]; cipher += type_literature[0];

	}
	void book::setTypeLiterature() {
		bool R = true;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		while (R) {
			std::string other;
			std::cout << "Введите тип литературы Educational Scientific Fictional" << std::endl;
			other = getNum();
			if (other == "Educational" || other == "Scientific" || other == "Fictional") {
				type_literature = other;
				R = false;
			}
			else {
				std::cerr << "Ошибка: Недопустимый тип литературы." << std::endl;
			}
		}
	}
	std::ostream& operator << (std::ostream& os, const book& obj) {

		os << "Фамилия Автора " << obj.getName() << "\nНазвания издания  " << obj.getEdition()
			<< "\nГод и издательсво " << obj.getYear_publisher() << "\nКоличество экземпляров " << obj.getCopies() << "\nТип литературы " << obj.getType_literature()
			<< "\nШифр " << obj.getCipher() << std::endl;
		return os;

	}
	
	void book::print() const {
		std::cout << *this;
	}



}