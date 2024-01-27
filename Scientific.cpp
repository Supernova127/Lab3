#pragma once
#include "Scientific.h"


namespace Prog3 {

	Scientific::Scientific(const book& other, const std::vector <std::string>& course) : book(other), courseName(course) {
	}
	Scientific::Scientific(const book& other) : book(other) {
		std::cout << "Введите количество курсов" << std::endl;
		int line = getNum<int>(1, 3);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i <line; i++) {
		std::cout << "Введите название курса" << std::endl;
		this->addCourse(getNum());
		}
		
	}
	void Scientific::addCourse(const std::string& other) {
		if ((courseName.size() + 1) <= 3) {
			courseName.push_back(other);
		}
		else if ((courseName.size() + 1) > 3) {

			std::cout << "Групп не может быить больше чем 3 " << std::endl;
		}

	}
	void Scientific::deleteCourse(int index) {
		if ((courseName.size() - 1) >= 1) {
			courseName.erase(courseName.begin() + index);
		}
		else if ((courseName.size() - 1) < 1) {

			std::cout << "Групп не может быть меньше 1 " << std::endl;
		}
	}
	void Scientific::setCourse(int index) {
		courseName[index] = getNum();
	}
	void Scientific::changeCourse(const std::string& other) {
		for (int i = 0; i < courseName.size(); i++) {
			if (courseName[i] == other) {
				std::cout << "Введите название курса" << std::endl;
				setCourse(i);
			}

		}
	}
	const std::vector<std::string> Scientific::GetCureseName() {
		return courseName;
	}
	void Scientific::Display() {
		this->print();
		for (int i = 0; i < courseName.size(); i++) {
			std::cout << "Названия групп " << courseName[i] << std::endl;
		}
	}


}


