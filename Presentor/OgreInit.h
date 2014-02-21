#pragma once
#include "OGRE\OgreRoot.h"

class OgreInit
{
private:
	// These functions are private (exterior classes cannot use it), and are not coded (linker error
	// if someone tries to call it).
	// This might happen when people make simple mistakes (eg. putting it directly in a std::vector ...).
	OgreInit(const OgreInit& s);
	OgreInit& operator=(const OgreInit& s);

public:
	///\brief  This function will create 1 ogre root and 1 window and store them in its members mRoot and mWindow.
	///\return false if an error occurs, true otherwise.
	bool initOgre();
	OgreInit();
	~OgreInit();

	// I put the member in public because there is no need to put them private in these tutorials.
	// It will allow very simple access to these useful members.
	///\brief the root of ogre will be contained in this member.
	/// it will be initialised in initOgre().
	std::auto_ptr<Ogre::Root> mRoot;
	///\brief the window created in the initOgre(). NULL otherwise.
	/// This is just a handle, not a real aggregation. 
	/// The destruction of the Root will imply its destruction.
	Ogre::RenderWindow* mWindow;
};

