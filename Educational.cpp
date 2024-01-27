#pragma once
#include "Educational.h"

namespace Prog3 {
	Educational::Educational(const book& other) :book(other) {
		std::cout << "������� �������� �����" << std::endl;
		courseName = getNum();
		std::cout << "������� ���������� �����" << std::endl;
		int line = getNum<int>(1, 8);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < line; i++) {

			std::cout << "������� �������� ������" << std::endl;
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
			std::cout << "����� �� ����� ����� ������ ��� 8 " << std::endl;
		}

	}
	void Educational::deleteGroup(int index) {
		if ((group.size() - 1) >= 1) {
			group.erase(group.begin() + index);
		}
		else if ((group.size() - 1) < 1) {
			std::cout << "����� �� ����� ���� ������ 1 " << std::endl;
		}
	}

	void Educational::Display()  {
		this->print();
		std::cout << "�������� ����� " << courseName << std::endl;
		for (int i = 0; i < group.size(); i++) {
			std::cout << "�������� ������ " << i << " " << group[i] << std::endl;
		}
	}
	
	





}