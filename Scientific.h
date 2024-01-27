#pragma once
#ifndef CLASS_Scientific
#define CLASS_Scientific
#include "classBook.h"
#include <vector>

namespace Prog3 {
	class Scientific :public book
	{
	private:
		std::vector<std::string> courseName;
	public:
		Scientific() = default;
		Scientific(const book& other, const std::vector <std::string>& course);
		Scientific(const book& other);
		~Scientific() = default;
		void addCourse(const std::string& other);
		void deleteCourse(int index);
		void changeCourse(const std::string& other);
		void setCourse(int index);
		const std::vector<std::string> GetCureseName();
		void Display() override;
		Scientific* clone()const override {
			return new Scientific(*this);
		}
	};




}


#endif