// HunterKiller.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//Random number seeding.
#include <ctime>
using std::cout;
using std::endl;


int main()
{
	//Enemy spawns on a 8x8 grid somewhere
	cout << "Enemy being spawned on 8x8 grid..." << endl;
	srand(time(0));
	//random number between 1-64
	int searchHighnumber = 64;
	int searchLownumber = 1;
	int enemyLocation = rand() % searchHighnumber + searchLownumber;
	cout << "Enemy is located at location #" << enemyLocation << "on 8x8 grid" << endl;

	cout << "USS Gettysburg initiating patrols in 8x8 grid" << endl;
	//number of target location predictions it took to find enemy
	int targetlocationpredictioncounter = 0;
	//is target found / destroyed
	bool targetFound = false;

	while (targetFound == false)
	{
		//perdicting where to begin search
		int targelocationprediction = ((searchHighnumber - searchLownumber) / 2) + searchLownumber;
		targetlocationpredictioncounter++;
		//radar sweeps for enemyy
		cout << "=====================================================================================" << endl;
		cout << "USS Gettysburg radar is sending out a sweep for enemys #" << targetlocationpredictioncounter << endl;
		//ping tells us if the target location is higher or lower or right on the enemy
		if (targelocationprediction > enemyLocation)
		{
			searchHighnumber = targelocationprediction - 1;
			cout << " The target location predition of " << targelocationprediction << "was higher then the actual";
			cout << " The new search pattern is #" << searchHighnumber << endl;

		}
		else if (targelocationprediction < enemyLocation)
		{
			searchLownumber = targelocationprediction + 1;
			cout << "The target location prediction of " << targelocationprediction << " was lower then the actual";
			cout << "The new search pattern is # " << searchLownumber << endl;
		}
		else if (targelocationprediction == enemyLocation)
		{
			//Simulate won!
			cout << "Enemy has been detected at location #" << enemyLocation << endl;
			cout << "Target was found at location #" << targelocationprediction << endl;
			cout << "USS Gettysburg software took " << targetlocationpredictioncounter << " predictions to find the enemy" << endl;
			targetFound = true;
		}
		else
		{
			//something has gone wrong this keeps the simulation from running forever
			cout << "Battleship malfunction!!!!!!!" << endl;
			cout << "Battleship software needs diagnostics!!!!!" << endl;
			targetFound = true;
		}
	}

	//pause then exit simulation...
	system("pause");
    return 0;
}

