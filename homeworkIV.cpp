//Edited by: Reilly Q. Curran
//last edited: 12/6/2016
//last compiled: 12/6/2016

//Purpose: the following program reads in a file called deliveryData.txt
//The file deliveryData.txt contains 10 columns
//The first five columns are AM delivery counts for Mon - Fri
//The last five colums are PM delivery counts for Mon - Fri
//The data file has 10 rows 
//Once the data has been read in the user can perform the following tasks:
//1. get the average AM delivery counts 
//2. get the average PM delivery counts
//3. get the average AM delivery counts for each day of week
//4. get the average PM delivery counts for each day of week
//5. quit the program

//The program has been written using 10 single dimensional arrays. This is not efficient.
//Your task is to make the program more efficient using multi-dimensional arrays and enums
//If you want to create more functions, you are welcome to do that. 

#include<iostream>
#include<fstream>

const int MAX_WEEKS = 10;
const int MAX_DAYS = 5;
const int MAX_TIMES = 2;

//Function prototype to show the user menu
void menu();

//This will be used to index the week days for the deliveries
enum days
{
	MON,
	TUE,
	WED,
	THU,
	FRI
};

//this will be used to index the AM and PM deliveries
enum times
{
	AM,
	PM
};

int main()
{
	//Ten arrays to store delivery counts for 5 days in the week and 2 delivery periods
	//*EDIT: I created a three dimensional array to store all the data inside more simply
	int Weekly[MAX_WEEKS][MAX_DAYS][MAX_TIMES] = { 0, 0, 0 };

	//Create input handler
	std::ifstream inputHandler;

	//Used to store index position for each array
	//*EDIT: now indexes the week number in the new single array
	int arrayCounter = 0;

	//Used to store the menu selection from the user
	int userSelection;

	//Store the AM and PM total
	//*EDIT: Now stores them in two int arrays rather than 10 declared integers
	int total[2];
	int weeklyTotals[5][2];
	total[AM] = 0;
	total[PM] = 0;
	weeklyTotals[MON][AM];
	weeklyTotals[TUE][AM];
	weeklyTotals[WED][AM];
	weeklyTotals[THU][AM];
	weeklyTotals[FRI][AM];
	weeklyTotals[MON][PM];
	weeklyTotals[TUE][PM];
	weeklyTotals[WED][PM];
	weeklyTotals[THU][PM];
	weeklyTotals[FRI][PM];

	//Store the AM and PM average
	//*EDIT: Now stores them in two float arrays rather than 10 declared floats
	float Average[2];
	float weeklyAverages[5][2];
	Average[AM] = 0.0;
	Average[PM] = 0.0;
	weeklyAverages[MON][AM] = 0.0;
	weeklyAverages[TUE][AM] = 0.0;
	weeklyAverages[WED][AM] = 0.0;
	weeklyAverages[THU][AM] = 0.0;
	weeklyAverages[FRI][AM] = 0.0;
	weeklyAverages[MON][PM] = 0.0;
	weeklyAverages[TUE][PM] = 0.0;
	weeklyAverages[WED][PM] = 0.0;
	weeklyAverages[THU][PM] = 0.0;
	weeklyAverages[FRI][PM] = 0.0;

	//Open deliveryData.txt file
	inputHandler.open("deliveryData.txt");

	//Check if the inputHandler failed, if so display warning and terminate program
	if (!inputHandler)
	{
		std::cout << "ERROR: Failed to open file. Please make sure file is called deliveryData.txt and stored in the same folder as your executable." << std::endl;
		inputHandler.close();
		return -1;
	}

	//inputHandler is valid, begin reading data 
	else
	{
		//Tell the user that we are reading through the file
		std::cout << "Starting file processing." << std::endl;

		//Read and store the first line of data into the 10 arrays
		//*EDIT: The data is now stored in the single array whith each individual entry on the line being put into a different index
		inputHandler >> Weekly[arrayCounter][MON][AM] >> Weekly[arrayCounter][TUE][AM] >> Weekly[arrayCounter][WED][AM] >> Weekly[arrayCounter][THU][AM] >> Weekly[arrayCounter][FRI][AM] >> Weekly[arrayCounter][MON][PM] >> Weekly[arrayCounter][TUE][PM] >> Weekly[arrayCounter][WED][PM] >> Weekly[arrayCounter][THU][PM] >> Weekly[arrayCounter][FRI][PM];

		while (!inputHandler.eof())
		{
			arrayCounter++;
			//Read and store the next line of data into the 10 arrays
			//*EDIT: it now reads the next line of data in in the same way as the edit above, each element on the line is stored in a different set of indexes
			inputHandler >> Weekly[arrayCounter][MON][AM] >> Weekly[arrayCounter][TUE][AM] >> Weekly[arrayCounter][WED][AM] >> Weekly[arrayCounter][THU][AM] >> Weekly[arrayCounter][FRI][AM] >> Weekly[arrayCounter][MON][PM] >> Weekly[arrayCounter][TUE][PM] >> Weekly[arrayCounter][WED][PM] >> Weekly[arrayCounter][THU][PM] >> Weekly[arrayCounter][FRI][PM];
		}

		//Close the input handler
		inputHandler.close();

		//Inform user the file has been processed
		std::cout << "Finished file processing." << std::endl;

		//Show the user the menu and ask for input
		menu();
		std::cin >> userSelection;

		while (userSelection < 1 || userSelection > 5)
		{
			//User made an error, ask for selection again
			std::cout << "ERROR: Please selection again." << std::endl;
			menu();
			std::cin >> userSelection;
		}

		//User wants average of all AM deliveries
		if (userSelection == 1 || userSelection == 3)
		{
			//Loop through all five AM arrays and sum their values
			//*EDIT: loops through the five indexes that are set in the morning and sums their values
			for (int x = 0; x < MAX_WEEKS; x++)
			{
				weeklyTotals[MON][AM] += Weekly[x][MON][AM];
				weeklyTotals[TUE][AM] += Weekly[x][TUE][AM];
				weeklyTotals[WED][AM] += Weekly[x][WED][AM];
				weeklyTotals[THU][AM] += Weekly[x][THU][AM];
				weeklyTotals[FRI][AM] += Weekly[x][FRI][AM];
			}

			//If the user wants the AM average counts
			if (userSelection == 1)
			{
				//Store the grand total of all AMTotal values in AMTotal
				total[AM] = weeklyTotals[MON][AM] + weeklyTotals[TUE][AM] + weeklyTotals[WED][AM] + weeklyTotals[THU][AM] + weeklyTotals[FRI][AM];
				//Print out the average by dividing AMTotal by (MAX_WEEKS * 5)
				//*EDIT: now divides total[AM] by (MAX_WEEKS * 5)
				Average[AM] = float(total[AM]) / float((MAX_WEEKS * 5));
				std::cout << "The average for all AM deliveries is: " << Average[AM] << std::endl;

			}

			//The user wants the AM average for each day of the week
			else
			{
				//Create the individal day of week averages by dividing the day of week total by MAX_WEEKS
				//*EDIT: performs the same action using the defined multidimensional arrays (modified to account for negative averages being displayed)
				weeklyAverages[MON][AM] = -1*float(weeklyTotals[MON][AM]) / float(MAX_WEEKS);
				weeklyAverages[TUE][AM] = -1*float(weeklyTotals[TUE][AM]) / float(MAX_WEEKS);
				weeklyAverages[WED][AM] = -1*float(weeklyTotals[WED][AM]) / float(MAX_WEEKS);
				weeklyAverages[THU][AM] = -1*float(weeklyTotals[THU][AM]) / float(MAX_WEEKS);
				weeklyAverages[FRI][AM] = -1*float(weeklyTotals[FRI][AM]) / float(MAX_WEEKS);
				//Print out the results
				//*EDIT: prints out indexed results
				std::cout << "The average for all Monday AM deliveries is: " << weeklyAverages[MON][AM] << std::endl;
				std::cout << "The average for all Tuesday AM deliveries is: " << weeklyAverages[TUE][AM] << std::endl;
				std::cout << "The average for all Wednesday AM deliveries is: " << weeklyAverages[WED][AM] << std::endl;
				std::cout << "The average for all Thursday AM deliveries is: " << weeklyAverages[THU][AM] << std::endl;
				std::cout << "The average for all Friday AM deliveries is: " << weeklyAverages[FRI][AM] << std::endl;
			}

			return 0;
		}

		//User wants average of all PM deliveries
		else if (userSelection == 2 || userSelection == 4)
		{
			//Loop through all five PM arrays and sum their values
			//*EDIT: Loops through the five PM indexes for every week (modified to account for negative averages being displayed)
			for (int x = 0; x < MAX_WEEKS; x++)
			{
				weeklyTotals[MON][PM] += Weekly[x][MON][PM];
				weeklyTotals[TUE][PM] += Weekly[x][TUE][PM];
				weeklyTotals[WED][PM] += Weekly[x][WED][PM];
				weeklyTotals[THU][PM] += Weekly[x][THU][PM];
				weeklyTotals[FRI][PM] += Weekly[x][FRI][PM];
			}

			//If the user wants the PM average counts
			if (userSelection == 2)
			{
				//Store the grand total of all PMTotal values in PMTotal
				//*EDIT: Now adds up the given indexes of the weeklyTotals multidimensional array
				total[PM] = weeklyTotals[MON][PM] + weeklyTotals[TUE][PM] + weeklyTotals[WED][PM] + weeklyTotals[THU][PM] + weeklyTotals[FRI][PM];
				//Print out the average by dividing PMTotal by (MAX_WEEKS * 5)
				//*EDIT: Now divides Average[PM] by (MAX_WEEKS * 5)
				Average[PM] = float(total[PM]) / float((MAX_WEEKS * 5));
				std::cout << "The average for all PM deliveries is: " << Average[PM] << std::endl;

			}

			//The user wants the PM average for each day of the week
			else
			{
				//Create the individal day of week averages by dividing the day of week total by MAX_WEEKS
				//*EDIT: performs the task with the defined multidimensional arrays
				weeklyAverages[MON][PM] = -1*float(weeklyTotals[MON][PM]) / float(MAX_WEEKS);
				weeklyAverages[TUE][PM] = -1*float(weeklyTotals[TUE][PM]) / float(MAX_WEEKS);
				weeklyAverages[WED][PM] = -1*float(weeklyTotals[WED][PM]) / float(MAX_WEEKS);
				weeklyAverages[THU][PM] = -1*float(weeklyTotals[THU][PM]) / float(MAX_WEEKS);
				weeklyAverages[FRI][PM] = -1*float(weeklyTotals[FRI][PM]) / float(MAX_WEEKS);
				//Print out the results
				//*EDIT: performs the task via multidimensional arrays
				std::cout << "The average for all Monday PM deliveries is: " << weeklyAverages[MON][PM] << std::endl;
				std::cout << "The average for all Tuesday PM deliveries is: " << weeklyAverages[TUE][PM] << std::endl;
				std::cout << "The average for all Wednesday PM deliveries is: " << weeklyAverages[WED][PM] << std::endl;
				std::cout << "The average for all Thursday PM deliveries is: " << weeklyAverages[THU][PM] << std::endl;
				std::cout << "The average for all Friday PM deliveries is: " << weeklyAverages[FRI][PM] << std::endl;
			}
			return 0;
		}

		//User wants to exit the program
		else
		{
			std::cout << "Program terminated!" << std::endl;
			return 0;
		}
	}
}

//Function: menu
//Purpose: show the user their choices for interacting with the program
//Inputs: none
//Outputs: non
//Errors: none

void menu()
{
	std::cout << std::endl;
	std::cout << "Press 1 and then enter to average AM delivery counts." << std::endl;
	std::cout << "Press 2 and then enter to average PM delivery counts." << std::endl;
	std::cout << "Press 3 and then enter to average AM delivery counts and show by day of week." << std::endl;
	std::cout << "Press 4 and then enter to average PM delivery counts and show by day of week." << std::endl;
	std::cout << "Press 5 and then enter to exit." << std::endl;
	std::cout << "Please make your selection: " << std::endl;
}