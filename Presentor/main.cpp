#include <Windows.h>
// Here is exactly the same as the previous tutorial, but I have reorganized it a bit.
// Things are separated between a class that does the initialisation,
// and a main() that makes the application run.
// If you don't understand what a class is, or what #ifndef means, you should learn C++ first :-).

// I will use std::auto_ptr so I need to include 'memory'. 
// If you don't know std::auto_ptr, you should check some C++ tutorials/lesson on this matter.
#include <memory>
// I will check for std::exception. If you don't know what exception/try/catch means, you should learn C++ first.
#include <exception>

// These are some files that we need to include to use Ogre3D. Note that you can at the beginnings use directly "Ogre.h", to include lots of commonly used classes.
#include "OGRE/OgreRoot.h"
#include "OGRE/OgreRenderWindow.h"
#include "OGRE/OgreWindowEventUtilities.h"

//Here I include my other files, like the one for SimpleOgreInit...
#include "OgreInit.h"


// I declare a function in which I will make my whole application.
// This is easy then to add more things later in that function.
// The main will call this function and take care of the global try/catch.
void AnOgreApplication()
{
	// I construct my object that will allow me to initialise Ogre easily.
	OgreInit lOgreInit;

	if(!lOgreInit.initOgre())
	{
		return;
	}

	// I wait until the window is closed.
	// The "message pump" thing is something you will see in most GUI application.
	// It allow the binding of messages between the application and the OS.
	// These messages are most of the time : keystroke, mouse moved, ... or window closed.
	// If I don't do this, the message are never caught, and the window won't close.
	while(!lOgreInit.mWindow->isClosed())
	{
		Ogre::WindowEventUtilities::messagePump();
	}
	return;
}


int WINAPI WinMain(HINSTANCE inst,  HINSTANCE preInst, LPSTR args, int flag)
{
	try
	{
		AnOgreApplication();
		std::cout<<"end of the program"<<std::endl;
	}catch(Ogre::Exception &e)
	{
	}catch(std::exception &e)
	{
	}
	return 0;
}

