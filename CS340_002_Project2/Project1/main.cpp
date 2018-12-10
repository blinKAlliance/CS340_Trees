#include "RedBlackTree.h"
#include "BinarySearchTree.h"
#include "sadInterface.h"
#include "BinarySearchTree.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main() {

	char repeat = 'y';

	while (repeat != 'n') {

		cout << "(1)  Unsorted 15k    (11) Sorted 15k\n(2)  Unsorted 30k    (12) Sorted 30k\n"
			"(3)  Unsorted 45k    (13) Sorted 45k\n(4)  Unsorted 60k    (14) Sorted 60k\n"
			"(5)  Unsorted 75k    (15) Sorted 75k" << endl;

		cout << "(6)  Unsorted 90k    (16) Sorted 90k\n(7)  Unsorted 105k   (17) Sorted 105k\n"
			"(8)  Unsorted 120k   (18) Sorted 120k\n(9)  Unsorted 135k   (19) Sorted 135k\n"
			"(10) Unsorted 150k   (20) Sorted 150k" << endl;

		cout << "Enter a number: " << endl;

		int fileNum = -1;
		string fileName = "";

		while (fileNum < 1 || fileNum > 20) { // User chooses a file
			cin >> fileNum;

			if (fileNum < 0 || fileNum > 20) {
				cout << "The number you entered was invalid.\nEnter a number: " << endl;
			}
		}

		int fileSize = 1;

		switch (fileNum) { // Assigns file size and name

		case 1:
			fileName = "perm15K.txt";
			fileSize = 15000;
			break;
		case 2:
			fileName = "Perm30K.txt";
			fileSize = 30000;
			break;
		case 3:
			fileName = "Perm45K.txt";
			fileSize = 45000;
			break;
		case 4:
			fileName = "Perm60K.txt";
			fileSize = 60000;
			break;
		case 5:
			fileName = "Perm75K.txt";
			fileSize = 75000;
			break;
		case 6:
			fileName = "Perm90K.txt";
			fileSize = 90000;
			break;
		case 7:
			fileName = "Perm105K.txt";
			fileSize = 105000;
			break;
		case 8:
			fileName = "Perm120K.txt";
			fileSize = 120000;
			break;
		case 9:
			fileName = "Perm135K.txt";
			fileSize = 135000;
			break;
		case 10:
			fileName = "Perm150K.txt";
			fileSize = 150000;
			break;
		case 11:
			fileName = "Sorted15K.txt";
			fileSize = 15000;
			break;
		case 12:
			fileName = "Sorted30K.txt";
			fileSize = 30000;
			break;
		case 13:
			fileName = "Sorted45K.txt";
			fileSize = 45000;
			break;
		case 14:
			fileName = "Sorted60K.txt";
			fileSize = 60000;
			break;
		case 15:
			fileName = "Sorted75K.txt";
			fileSize = 75000;
			break;
		case 16:
			fileName = "Sorted90K.txt";
			fileSize = 90000;
			break;
		case 17:
			fileName = "Sorted105K.txt";
			fileSize = 105000;
			break;
		case 18:
			fileName = "Sorted120K.txt";
			fileSize = 120000;
			break;
		case 19:
			fileName = "Sorted135K.txt";
			fileSize = 135000;
			break;
		case 20:
			fileName = "Sorted150K.txt";
			fileSize = 150000;
			break;
		}

		cout << "What type of tree would you like to use?" << endl;
		cout << "(1) Binary Search Tree   (2) Red-Black Tree" << endl;

		int treeNum = -1;

		while (treeNum < 1 || treeNum > 2) { // User chooses Tree
			cin >> treeNum;

			if (treeNum < 0 || treeNum > 2) {
				cout << "The number you entered was invalid.\nEnter a new number: " << endl;
			}
		}

		string userWord;

		ifstream ifs;

		ifs.open(fileName);
		if (!ifs.is_open()) {
			cout << "Error reading file: " << fileName << endl;
			return 1;
		}

		string code;
		Node * newNode = new Node(NULL, NULL, NULL, code);

		clock_t start;
		clock_t timeElapsed;

		if (treeNum == 1) {
			sadInterface * bst = new BinarySearchTree(); // Creates new Interface that uses BST

			start = clock();
			getline(ifs, code);
			bst->insert(newNode, code); // Interface interaction to insert

			while (!ifs.eof()) {
				getline(ifs, code);
				bst->insert(newNode, code); // Interface interaction to insert

			}
			timeElapsed = clock() - start;
			cout << "Time taken to construct the dictionary from the selected data structure: " << timeElapsed << " ms." << endl;

			ifs.close();

			cout << "What would you like to search for?" << endl;
			cin >> userWord;

			start = clock();
			if (bst->searchTree(newNode, userWord)) { // Interface interaction to search
				cout << "Word Found." << endl;
			}
			else {
				cout << "Word Not Found." << endl;
			}
			timeElapsed = (clock() - start);
			cout << "Time taken to search the dictionary from the selected data structure: " << timeElapsed << " ms." << endl;
		}
		else {
			sadInterface * rbt = new RedBlackTree(); // Creates new Interface that uses RBT

			start = clock();
			getline(ifs, code);
			rbt->insert(newNode, code); // Interface interaction to insert

			while (!ifs.eof()) {
				getline(ifs, code);
				rbt->insert(newNode, code); // Interface interaction to insert
			}
			timeElapsed = clock() - start;
			unsigned msElapsed = timeElapsed;
			cout << "Time taken to construct the dictionary from the selected data structure: " << timeElapsed << " ms." << endl;


			ifs.close();

			cout << "What would you like to search for?" << endl;
			cin >> userWord;

			start = clock();
			if (rbt->searchTree(newNode, userWord)) { // Interface interaction to search
				cout << "Word Found." << endl;
			}
			else {
				cout << "Word Not Found." << endl;
			}
			timeElapsed = (clock() - start);
			cout << "Time taken to search the dictionary from the selected data structure: " << timeElapsed << " ms." << endl;
		}

		cout << "Would you like to try another file? ( y / n )" << endl;
		cin >> repeat;
	}

	return 1;
}