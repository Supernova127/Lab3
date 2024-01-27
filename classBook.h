#pragma once
#ifndef CLASS_BOOK
#define CLASS_BOOK


#include<iostream>
#include <string>
#include <locale>


namespace Prog3 {
    template<class T>
    T getNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max()) {
        T a;
        while (true) {
            std::cin >> a;
            if (std::cin.eof()) // обнаружен конец файла
                throw std::runtime_error("Не удалось прочитать номер EOF");
            else if (std::cin.bad()) // обнаружена невосстановимая ошибка входного потока
                throw std::runtime_error(std::string("Не удалось прочитать номер: "));
            // прочие ошибки (неправильный формат ввода) либо число не входит в заданный диапазон
            else if (std::cin.fail() || a < min || a > max) {
                std::cin.clear(); // очищаем флаги состояния потока
                // игнорируем все символы до конца строки
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка ввода. Повторите ввод " << std::endl;
            }
            else // успешный ввод
                return a;
        }
    }
    std::string getNum();

    class book
    {
    protected:// фамилия и инициалы автора, название издания; год и издательство; количество экземпляров;тип литературы
        std::string Name;
        std::string edition;
        std::string year_publisher;
        int copies;
        std::string type_literature;
        std::string cipher;
    public:
        book() {
            Name = "";  year_publisher = "";
            edition = "";   type_literature = "";
            copies = -1; cipher = "";
        }
        book(const std::string& vName, const std::string& vedition, const std::string& vyear_publisher, int vcopies, const std::string& vtype_literature) {
            Name = vName; edition = vedition; year_publisher = vyear_publisher; copies = vcopies; type_literature = vtype_literature;
            generationСipher();
        }
        book(const book& other) {
            Name = other.Name; edition = other.edition; year_publisher = other.year_publisher; copies = other.copies; type_literature = other.type_literature; generationСipher();
        }
        ~book() = default;//вирту
        std::string getName()const {
            return Name;
        }
        std::string getEdition()const {
            return edition;
        }
        std::string getYear_publisher()const {
            return year_publisher;
        }
        std::string getType_literature()const {
            return type_literature;
        }
        int getCopies()const {
            return copies;
        }
        void setCopies(int ot) {
            copies = ot;
        }
        std::string getCipher()const {
            return cipher;
        }
        void initialization();
        void setTypeLiterature();// не может менятся
        void generationСipher() {
            cipher = Name[0]; cipher += edition[0]; cipher += year_publisher[0]; cipher += type_literature[0];
        }
        void print() const;
        friend std::ostream& operator << (std::ostream& os, const book& obj);
        virtual void Display() {
            print();
        }
        virtual book* clone()const {
            return new book(*this);
        }
           
    };




}



#endif 