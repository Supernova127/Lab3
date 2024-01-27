#pragma once
#include "Educational.h"

namespace Prog3 {
	Educational::Educational(const book& other) :book(other) {
		std::cout << "Введите название курса" << std::endl;
		courseName = getNum();
		std::cout << "Введите количество Групп" << std::endl;
		int line = getNum<int>(1, 8);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < line; i++) {

			std::cout << "Введите название Группы" << std::endl;
			this->addGroup(getNum());
		}
	}

	Educational::Educational(const book& other, const std::string& vCourseName, const std::vector <std::string>& vGroup) :book(other), courseName(vCourseName), group(vGroup) {
	}
	void Educational::addGroup(const std::string& other) {
		if ((group.size() + 1) <= 8) {
			group.push_back(other);
		}
		else if ((group.size() + 1) > 8)
		{
			std::cout << "Групп не может быить больше чем 8 " << std::endl;
		}

	}
	void Educational::deleteGroup(int index) {
		if ((group.size() - 1) >= 1) {
			group.erase(group.begin() + index);
		}
		else if ((group.size() - 1) < 1) {
			std::cout << "Групп не может быть меньше 1 " << std::endl;
		}
	}

	void Educational::Display()  {
		this->print();
		std::cout << "Названия курса " << courseName << std::endl;
		for (int i = 0; i < group.size(); i++) {
			std::cout << "Названия группы " << i << " " << group[i] << std::endl;
		}
	}
	
	





}