#pragma once
#include "Fictional.h"

namespace Prog3 {
	Fictional::Fictional(const book& other):book(other) {
		std::cout << "Введите Жанр" << std::endl;
		genre = getNum();
	}
	Fictional::Fictional(const book& other, const std::string& value) :book(other), genre(value) {
	}
	const std::string Fictional::GetGener() const {
		return genre;
	}
	void Fictional::SetGener(const std::string other) {
		genre = other;
	}
	void Fictional::Display() {
		this->print();
		std::cout << "Названия Жанра " << genre << std::endl;
	}
	
}