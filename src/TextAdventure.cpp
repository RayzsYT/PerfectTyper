#include "entity/Entity.h"
#include "world/Location.h"

#include <conio.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

#define NUMINAX
#define WIN32_LEAN_AND_MEAN

using namespace std;


const vector<string>& sentences =
{
    "Did you know that you can keep an avocado from browning by storing it with a slice of onion?",
    "Chewing gum while peeling onions can help reduce the chance of tears, though you'll look a bit strange doing it.",
    "Pineapples take about two years to grow, so next time you enjoy a slice, think about the patience involved.",
    "A group of flamingos is called a 'flamboyance,' which makes them sound even more fabulous than they already are.",
    "If you rub the inside of a banana peel on a scratched CD, it might play better, or at least smell fruity.",
    "Spiders are technically not insects; they're arachnids, but that won't make you like them any more, will it?",
    "Using a damp sponge in the microwave for two minutes can disinfect it, but watch out for the steam.",
    "The dot over the letter 'i' is called a 'tittle,' which is probably the least exciting thing you'll learn today.",
    "Putting your phone in airplane mode while charging can speed up the process slightly, not enough to change your life, though.",
    "A cow gives nearly 200,000 glasses of milk in a lifetime, which is impressive, but she probably doesn't think about it much.",
    "A group of porcupines is called a 'prickle,' which sounds cute until you remember what those quills can do.",
    "You can use toothpaste to clean foggy headlights, but it is best not to ask how anyone discovered this trick.",
    "Bubble wrap was originally intended to be wallpaper, which would have made moving furniture much more entertaining.",
    "If you lick your wrist and sniff it, you'll get a preview of your breath's smell, though there are better ways to check.",
    "A shrimp's heart is located in its head, which might explain why they're such clever little creatures.",
    "The average person walks the equivalent of three times around the world in a lifetime, though not all at once, of course.",
    "Cucumbers are technically berries, so your salad might be fruitier than you think.",
    "You can tell the temperature by counting a cricket's chirps, though it's easier to just check your phone.",
    "Honey never spoils, which is great if you're planning to keep it for centuries, just in case.",
    "A group of crows is called a 'murder,' but they rarely get up to anything that sinister.",
    "Pencils can write in zero gravity, but NASA still spent millions developing a pen for space.",
    "Peanuts aren't actually nuts; they're legumes, but nobody's changing the name any time soon.",
    "You can use a bread clip to fix a broken flip-flop temporarily, though you might not want to wear it for long.",
    "Elephants can't jump, but they don't seem to mind being left out of that activity.",
    "A group of owls is called a 'parliament,' which sounds very wise, just like the birds themselves.",
    "The inventor of the frisbee was turned into a frisbee after he died, which is an interesting way to leave a legacy.",
    "If you put a wooden spoon over a pot of boiling water, it might prevent it from boiling over, but don't forget to lower the heat.",
    "Most people can't lick their elbow, though that doesn't stop them from trying when they hear this fact.",
    "Bananas are berries, but strawberries aren't, making fruit classification more confusing than it needs to be.",
    "You can make ice cubes clear by boiling the water first, which looks cool but doesn't change the taste."
};


void clear() {
	system("cls");
}

string getRandomSentence() {
	srand(static_cast<unsigned int>(time(nullptr)));
	int randomIndex = rand() % sentences.size();
	return sentences[randomIndex];
}

int main() {
	system("title PerfectTyper");

	bool running = true,
		 pressed = false,
		 started = false;

	string sentence = getRandomSentence();
	int currentCharLvl = 0, errors = 0;
	char nextChar = sentence[currentCharLvl], pressedChar;

	cout << sentence << endl;

	while(running) {

		if(nextChar == 0) {
			if(!started) continue;
			started = false;

			const int& letters = sentence.length(), accuracy = (static_cast<double>(letters - errors) / letters) * 100;

			cout << endl << endl << "Accuracy: " << accuracy << "%" << endl
					<< "Letters: " << letters << endl
					<< "Misspells: " << errors << endl << endl
					<< "Next sentence appears in 5 seconds." << endl;


			Sleep(5000);
			currentCharLvl = 0;
			errors = 0;
			clear();

			sentence = getRandomSentence();
			nextChar = sentence[currentCharLvl];

			cout << sentence << endl;
			continue;
		}

		while (!pressed && _kbhit()) {
			if(!started) started = true;
			pressedChar = _getch();

			if(pressedChar == nextChar) {

				currentCharLvl += 1;
				nextChar = sentence[currentCharLvl];
				cout << pressedChar;

			} else errors += 1;

			pressed = true;
		}

		pressed = false;

	}

	return 0;
}
