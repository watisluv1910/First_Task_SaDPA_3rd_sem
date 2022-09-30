#include <iostream>
#include <bitset>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::string;

int doFirstOperation(size_t number);
int doSecondOperation(size_t number);
int doThirdOperation(size_t number);
int doFourthOperation(size_t number);
int doFifthOperation(size_t number, size_t n);
inline void outputMenu(const size_t& curr_num);
void inputHex(size_t& curr_num);
string getBinFromHex(const size_t& curr_num);

int main()
{
	size_t curr_num = 0;

	outputMenu(curr_num);

	cout << "\nYour choise is:\n";

	unsigned path = 0; // Menu navigation variable
	cin >> path;

	// cin.clear and cin.ignore are used to prevent fake input:
	cin.clear();
	cin.ignore(std::numeric_limits<int>::max(), '\n');

	while (path)
	{
		switch (path)
		{
		case 1:
			cout << "\nThe mask is:\n"
				"10000110\n";
			cout << "\nThe result is:\n"
				<< getBinFromHex(doFirstOperation(curr_num)) << std::endl;
			break;
		case 2:
			cout << "\nThe mask is:\n"
				"1110000000\n";
			cout << "\nThe result is:\n"
				<< getBinFromHex(doSecondOperation(curr_num)) << std::endl;
			break;
		case 3:
			cout << "\nThe result is:\n"
				<< getBinFromHex(doThirdOperation(curr_num)) << std::endl;
			break;
		case 4:
			cout << "\nThe result is:\n"
				<< getBinFromHex(doFourthOperation(curr_num)) << std::endl;
			break;
		case 5: {
			size_t reset_bit_num = 0;
			cout << "\nEnter the number of bit you want to reset:\n";
			cin >> reset_bit_num;
			cout << "\nThe result is:\n"
				<< getBinFromHex(doFifthOperation(curr_num, reset_bit_num)) << std::endl;
			break;
		}
		case 6:
			inputHex(curr_num);
			break;
		default:
			std::cerr << "\nError (0): Wrong path entered.\n"; // Error 0
			break;
		}

		system("pause");
		system("cls"); // clear screen

		outputMenu(curr_num);

		// Next menu navigation step:
		cout << "\nYour choise is:\n";
		cin >> path;

		// cin.clear and cin.ignore are used to prevent fake input
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
	}

    return 0;
}

int doFirstOperation(size_t number) 
{
    size_t mask = 0b10000110;
    return number | mask;
}

int doSecondOperation(size_t number)
{
    size_t mask = 0b1110000000;
    return number & ~mask;
}

int doThirdOperation(size_t number)
{
    return number << 3;
}

int doFourthOperation(size_t number)
{
    return number >> 3;
}

int doFifthOperation(size_t number, size_t n)
{
    size_t mask = 0b1;
	cout << "\nThe mask is:\n"
		<< "1" << string(n, '0') << "\n";
    return number & ~(mask << n);
}

inline void outputMenu(const size_t& curr_num)
{
	cout << "Practical task num.1\nIKBO-24-21 Nasevich V.V.\n"
		"Variant num. 16.\n\nMenu:\n"
		"1)Enter <1> to set 1, 2, 7 digits to 1.\n"
		"2)Enter <2> to reset 7-9 digits.\n"
		"3)Enter <3> to multiply number by 8 in decimal cc.\n"
		"4)Enter <4> to divide number by 8 in decimal cc.\n"
		"5)Enter <5> to reset bit with chosen number.\n"
		"6)Enter <6> to enter the new number in hex format.\n"
		"7)Enter <0> to end the programm.\n";

	cout << "\nCurrent number in hex format is "
		<< std::hex << std::uppercase << curr_num << ".\n";

	cout << "Current number in bin format is "
		<< getBinFromHex(curr_num) << ".\n";
}

void inputHex(size_t& curr_num)
{
	cout << "\nEnter the number in hex format:\n";
	cin.unsetf(std::ios::dec);
	cin.setf(std::ios::hex);
	cin >> curr_num;
	cin.unsetf(std::ios::hex);
	cin.setf(std::ios::dec);
}

string getBinFromHex(const size_t& curr_num)
{
	std::bitset<32> b(curr_num);

	if (b.to_string().find('1') != string::npos)
	{
		return b.to_string().erase(0, b.to_string().find_first_of('1'));
	}

	return "0";
}