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
			std::cout << "������� 1 ����� �������� ����������� ������ �������\n"
				<< "������� 2 ����� �������� ������ ���������� �������\n"
				<< "������� 3 ����� �������� ������� ���������� �������\n"
				<< "������� 4 ����� ���������� ��� ������� �� ��������� �����\n"
				<< "������� 5 ����� �������� ����� ��� ���� ��������\n"
				<< "������� 6 ����� �������� �������� ������, ������������ �����������, ��������� �����-��������\n"
				<< "������� 0 ����� �����" << std::endl;

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