#pragma once
#include "player.h"
#include "InputState.h"
class HumanPlayer :
	public Player
{
protected:
	bool getSquare();
public:
	HumanPlayer(boost::shared_ptr<Grid> grid) ;
	void updateState(InputState& state,Point2D& square);

	virtual ~HumanPlayer(void);
};


