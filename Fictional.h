#pragma once
#ifndef CLASS_Fictional
#define CLASS_Fictional
#include "classBook.h"


namespace Prog3 {
	class Fictional :public book
	{
	private:
		std::string genre;
	public:
		Fictional() = default;
		Fictional(const book& other, const std::string& value);
		Fictional(const book& other);
		~Fictional() = default;
		const std::string GetGener()const;
		void SetGener(const std::string other);
		void Display() override;// const
		Fictional* clone()const override {
			return new Fictional(*this);
		}
	};


}


#endif