// Written solely by Christopher Jaston

// Tracker of in-shuffles of a 52 card deck to track the positions of top/bottom cards and position of card index #1

#include <iostream>
#include <vector>
#include <string>
//using namespace std; is bad practice

class inShuffle {
public:
	std::vector<int> shuffler(std::vector<int>& cards) {				//method shuffler with constructor cards: performs in-shuffle operation
		std::vector<int> shuffled(cards.size());				//return variable of type vector<int>

			for (int i = 0; i < cards.size() / 2; i++) {			//iterate 26 times, placing 2 cards in correct position each loop
				shuffled[2 * i] = cards[cards.size() / 2 + i];		//places top half beginning at index[0] and increments by 2
				shuffled[2 * i + 1] = cards[i];				//places bottom half beginning at index[1] and increments by 2
			}

		return shuffled;							//returns proper in-shuffle
	}
};

int main() {
	inShuffle m;									//class object instantiated
	int cardcount = 0;								//stores total amount of cards
	int shufflecount = 0;								//stores total amount of shuffles
														
	std::vector<int> cardStack;							//primary card configuration container
	std::vector<int> shuffletemp;							//temporary card configuration container
	std::vector<int> shufflereset;							//initial configuration container
	
	std::cout << "How many cards are in the deck? \n" << std::endl;			//get total amount of cards from user input
	std::cin >> cardcount;								//store total amount of cards
	std::cout << "\n\n";								//eye candy spacing

	for (int j = 1; j <= cardcount; j++) {						//cards will be pushed starting with 'card 1' at index[0]
			cardStack.push_back(j);
	}
	shufflereset = cardStack;							//saves initial configuration template
	int end = 1;									//initialize while loop breaker
	while (end == 1) {
		cardStack = shufflereset;						//resets initial configuration of cardStack each loop
		std::cout << "How many 'in shuffles' would you like? \n" << std::endl;	//get amount of in-shuffles from user input
		std::cin >> shufflecount;						//store amount of in-shuffles
		std::cout << "\n\n";							//eye candy spacing

		for (int a = 0; a < shufflecount; a++) {				//iterate amount of shuffles
			shuffletemp = m.shuffler(cardStack);				//call shuffler method to shuffle and store in shuffletemp
			cardStack = shuffletemp;					//overwrite cardStack to continue shuffling same loop
		}
		for (int k = 0; k < shuffletemp.size(); k++) {				//print shuffled vector
			std::cout << shuffletemp[k] << ' ';
		}

		std::cout << "\n\n";
		std::cout << "The bottom card is now " << shuffletemp[0] << "! \n\n";				//return bottom card value
		std::cout << "The top card is now " << shuffletemp[shuffletemp.size() - 1] << "! \n\n";		//return top card value

		for (int m = 0; m < shuffletemp.size(); m++) {							//iterate to locate first card after nth shuffle
			if (shuffletemp[m] == 1) {
				std::cout << "The position/index of the first card is now " << m << "! \n\n";;
			}
		}

		int bottomfinder = 0;										//initialize loop counter
		cardStack = shufflereset;									//reset to intial configuration
		const int top_card = cardStack[cardStack.size() - 1];						//constant top card, in this case value 52 at index[51]
		while (true) {
			shuffletemp = m.shuffler(cardStack);							//shuffle each loop
			cardStack = shuffletemp;
			bottomfinder++;										//increment each loop
			if (shuffletemp[0] == top_card) {							//return loop timer after finding top card in index[0]
				std::cout << "It took " << bottomfinder << " times to shuffle the top card to the bottom from the initial configuration!\n";
				break;
			}
		}

		int touching = 0;										//initialize loop counter
		cardStack = shufflereset;									//reset to intial configuration
		const int bottom_card = cardStack[0];								//constant bottom card, in this case value 1 at index[0]
		bool breaker = false;										//variable to break out of nested for loop inside while
		while (breaker == false) {	
			shuffletemp = m.shuffler(cardStack);							//begin shuffling
			cardStack = shuffletemp;
			touching++;										//increment loop counter each shuffle
			for (int d = 0; d < cardStack.size() - 1; d++) {					//only need to iterate up to n-1 terms
				if (cardStack[d] == bottom_card || cardStack[d] == top_card) {			//check if either card is found during increment
					if (cardStack[d + 1] == bottom_card || cardStack[d + 1] == top_card) {	//check if next card is either card we are looking for
						std::cout << "It took " << touching << " shuffles for bottom and top cards to touch from the initial configuration!\n";
						breaker = true;																	//return loop counter and break loop
					}
				}
			}
		}	
		std::cout << "[Press 1 to continue] \n[Press 0 to break] " << "\n";				//for ease of use in multiple case testing
		std::cin >> end;																				//breaks final while loop
	}
	return 0;
};

// Thanks so much for the opportunity! - Christopher Jaston
