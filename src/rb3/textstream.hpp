#ifndef RB3_TEXTSTREAM_HPP
#define RB3_TEXTSTREAM_HPP
#include "symbol.hpp"

class TextStream {
public:
	TextStream();
	virtual ~TextStream(); // fn_8000DD10 - generic dtor fn
	virtual void Print(const char *) = 0;

	TextStream& operator<<(char); // fn_8037A68C
	TextStream& operator<<(short); // unused
	TextStream& operator<<(int); // fn_8037A6EC
	TextStream& operator<<(long); // fn_8037A750
	TextStream& operator<<(unsigned int); // fn_8037A7B4
	TextStream& operator<<(unsigned short); // fn_8037A818
	TextStream& operator<<(unsigned long); // fn_8037A87C
	TextStream& operator<<(float); // fn_8037A8E0
	TextStream& operator<<(double); // unused
	TextStream& operator<<(const char *); // fn_8037A940
	TextStream& operator<<(Symbol); // fn_8037A97C
	TextStream& operator<<(bool); // fn_8037A9BC
	void Space(int); // fn_8037AA10
};

#endif
