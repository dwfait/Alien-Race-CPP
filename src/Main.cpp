#include "Grid.h"
#include "ImageManager.h"
#include "HumanPlayer.h"
#include "Exception.h"

#include "Game.h"


#include "App.h"
#include <iostream>
#include <fstream>


int main (int argc, char* argv[]) 
{
	try
	{
		App* app = new App();
		app->run();
		delete app;

	}
	catch(Exception& e)
	{
		//std::cout << "Unrecoverable error: "<< e.getMessage() << std::endl;
		std::ofstream myfile;
		myfile.open ("error.txt");
		myfile << e.getMessage() << std::endl;
		myfile.close();
	}



    return 0;
}