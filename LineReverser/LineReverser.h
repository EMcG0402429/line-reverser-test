// Class definition. Should probably have some include guards and such. Although apparently pragma once makes it unnecessary?
class lineReverser
{
public:
	int reverseLines();
	lineReverser(std::string);
private:
	int countLines();
	std::string filename;
};