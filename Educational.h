#pragma once
#ifndef CLASS_Educational
#define CLASS_Educational
#include "classBook.h"
#include <vector>

namespace Prog3 {
	class Educational : public book
	{
	private:
		std::string courseName;
		std::vector <std::string> group;

	public:
		Educational() = default;
		Educational(const book& other);
		~Educational() = default;
		Educational(const book& other, const std::string& vCourseName, const std::vector <std::string>& vGroup);
		void setCourseName(const std::string& other) {
			courseName = other;
		}
		const std::string getCourseName() {
			return courseName;
		}
		void addGroup(const std::string& other);
		const std::vector<std::string> gerGroup() {
			return group;
		}
		void deleteGroup(int index);
		void Display() override;
		Educational* clone()const override {
			return new Educational(*this);
		}



	};



}



#endif 