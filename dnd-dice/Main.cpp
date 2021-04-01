#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
#include <cstdlib>


class DiceCluster
{
public:
	int m_num_of_dice;
	int m_num_of_sides;

	DiceCluster( int num_of_dice, int num_of_sides)
		: m_num_of_dice(num_of_dice), m_num_of_sides(num_of_sides)
	{
	}
	~DiceCluster()
	{
		std::cout << "deleted dice cluster" << std::endl;
	}

	int getNumOfDice()
	{
		return m_num_of_dice;
	};

	int getNumOfSides()
	{
		return m_num_of_sides;
	};
};

// ex of str: 3d12
int * getDiceAndSidesHandler(std::string& str_ref)
{
	std::string amt_of_dice;
	std::string num_of_sides;
	int dice_and_sides[2] = {};
	unsigned int size = str_ref.size() - 1;

	bool is_past_d = false;

	for (unsigned int i = 0; i <= size; i++)
	{
		if (str_ref[i] == 'd')
		{
			is_past_d = true;
			continue;
		};
		if (!is_past_d)
		{
			amt_of_dice += str_ref[i];
		};
		if (is_past_d)
		{
			num_of_sides += str_ref[i];
		};
	};
	dice_and_sides[0] = std::stoi(amt_of_dice);
	dice_and_sides[1] = std::stoi(num_of_sides);

	return dice_and_sides;
}

int rollDice(DiceCluster* dc)
{
	int sum_sides_of_dice = dc->getNumOfDice() * dc->getNumOfSides();

	int result_diceroll = rand() % sum_sides_of_dice + 1;

	return result_diceroll;
}

int main()
{
	std::cout << "Hello input the dice (i.e. 3d12) \n";

	std::string dice_and_sides_input = "3d12";
	
	//std::cin >> dice_and_sides_input;

	int* dice_and_sides = getDiceAndSidesHandler(dice_and_sides_input);
	
	const int dice = dice_and_sides[0];
	const int sides = dice_and_sides[1];

	DiceCluster* dc = new DiceCluster(dice, sides);

	std::cout << "num of dice: " << dc->getNumOfDice();

	std::cout << "\nnum of sies: " << dc->getNumOfSides();

	for (int i = 0; i < 10; i++)
	{
		std::cout << "\nresult of dice roll: " << rollDice(dc);
	}
	

}
