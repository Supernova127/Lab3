#include "Library.h"	

using namespace Prog3;

int main() {
	setlocale(LC_ALL, "Russian");
	Library lib;
	book newBook;
	try
	{
		while (true)
		{
			std::cout << "¬ведите 1 чтобы оформить поступление нового издани€\n"
				<< "¬ведите 2 чтобы оформить выдачу экземпл€ра издани€\n"
				<< "¬ведите 3 чтобы оформить возврат экземпл€ра издани€\n"
				<< "¬ведите 4 чтобы определить тип издани€ по заданному шифру\n"
				<< "¬ведите 5 чтобы получить отчЄт обо всех издани€х\n"
				<< "¬ведите 6 чтобы получить перечень курсов, обеспеченных литературой, использу€ класс-итератор\n"
				<< "¬ведите 0 чтобы выйти" << std::endl;

			int casee = getNum<int>(0, 6);
			switch (casee)
			{
			case 1:
				{				
				newBook.initialization();
				book* value = lib.initialization(newBook);
				lib.addNewPublication(value);
				}
								
				break;
			case 2:

				lib.giveCopies();
				break;
			case 3:
				lib.acceptCopies();
				break;
			case 4:
				lib.getTypeCipher();
				break;
			case 5:
				lib.printAllPublications();
				break;
			case 6:
				lib.getLiteratureCourses();
				break;
			case 0:
				return 0;

				

			}
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}