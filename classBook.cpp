#pragma once
#include "classBook.h"

namespace Prog3 {
	std::string getNum() {
		std::string str;
		while (true) {
			std::getline(std::cin, str);
			if (std::cin.eof()) // ��������� ����� �����
				throw std::runtime_error("�� ������� ��������� ������ EOF");
			else if (std::cin.bad()) // ���������� ��������������� ������ �������� ������
				throw std::runtime_error(std::string("�� ������� ��������� �����: "));
			// ������ ������ (������������ ������ �����) ���� ����� �� ������ � �������� ��������
			else if (std::cin.fail()) {
				std::cin.clear(); // ������� ����� ��������� ������
				// ���������� ��� ������� �� ����� ������
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "������ �����. ��������� ���� " << std::endl;
			}
			else // �������� ����
				return str;
		}
	}


	void book::initialization() {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "������� ������� ������ " << std::endl; Name = getNum(); std::cout << "�������  �������� ������� " << std::endl; edition = getNum();
		std::cout << "������� ��� � �����������" << std::endl; year_publisher = getNum();
		std::cout << "������� ���������� ����������� " << std::endl; copies = getNum<int>(0); 
		setTypeLiterature();
		cipher += Name[0]; cipher += edition[0]; cipher += year_publisher[0]; cipher += type_literature[0];

	}
	void book::setTypeLiterature() {
		bool R = true;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		while (R) {
			std::string other;
			std::cout << "������� ��� ���������� Educational Scientific Fictional" << std::endl;
			other = getNum();
			if (other == "Educational" || other == "Scientific" || other == "Fictional") {
				type_literature = other;
				R = false;
			}
			else {
				std::cerr << "������: ������������ ��� ����������." << std::endl;
			}
		}
	}
	std::ostream& operator << (std::ostream& os, const book& obj) {

		os << "������� ������ " << obj.getName() << "\n�������� �������  " << obj.getEdition()
			<< "\n��� � ����������� " << obj.getYear_publisher() << "\n���������� ����������� " << obj.getCopies() << "\n��� ���������� " << obj.getType_literature()
			<< "\n���� " << obj.getCipher() << std::endl;
		return os;

	}
	
	void book::print() const {
		std::cout << *this;
	}



}