#pragma once
#include "Table.h"


namespace Prog3 {
	book* Table::findBook(const std::string& cipher) {
		for (size_t i = 0; i < Books.size(); ++i) {
			if (Books[i]->getCipher() == cipher) {
				return Books[i]; 
			}
		}
		return nullptr; 
	}
	std::vector<std::string> Table::getCourses() {
		std::vector<std::string> Curse;
		for (size_t i = 0; i < Books.size(); ++i) {			
			if (Books[i]->getType_literature() == "Scientific") {
				Scientific* ScientificBook = dynamic_cast<Scientific*>(Books[i]);
				if (ScientificBook != nullptr) {
					int line = ScientificBook->getCopies();
						for (int i = 0; i < line; i++) {
							Curse.push_back(ScientificBook->GetCureseName()[i]);
						}						
				}
			}
			else if (Books[i]->getType_literature() == "Educational") {
				Educational* EducationalBook = dynamic_cast<Educational*>(Books[i]);
				if (EducationalBook != nullptr) {
					if (1 < EducationalBook->getCopies()) {
						Curse.push_back(EducationalBook->getCourseName());
					}					
				}
			}
		}
		return Curse;
	}
	void Table::removeBook(const std::string& cipher) {
		for (size_t i = 0; i < Books.size(); ++i) {
			if (Books[i]->getCipher() == cipher) {
				delete Books[i];
				Books.erase(Books.begin() + i);
				break;
			}
		}
	}
	void Table::Print()const {
		for (size_t i = 0; i < Books.size(); ++i) {
			if (Books[i]->getType_literature() == "Fictional") {
				Fictional* fictionalBook = dynamic_cast<Fictional*>(Books[i]);
				if (fictionalBook != nullptr) {					
					fictionalBook->Display();
					std::cout << std::endl;
				}	
			}
			else if (Books[i]->getType_literature() == "Scientific") {
				Scientific* ScientificBook = dynamic_cast<Scientific*>(Books[i]);
				if (ScientificBook != nullptr) {
					ScientificBook->Display();
					std::cout << std::endl;
				}				
			}
			else if (Books[i]->getType_literature() == "Educational") {
				Educational* EducationalBook = dynamic_cast<Educational*>(Books[i]);
				if (EducationalBook != nullptr) {
					EducationalBook->Display();
					std::cout << std::endl;
				}				
			}


		}
	}

	void Table::clearBooks() {
		Books.clear();
	}
	void Table::copyBooks(const Table& other) {
		for (const auto& bookPtr : other.Books) {

			Books.push_back(bookPtr-> clone());
		}
	}
}