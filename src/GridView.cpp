#include "GridView.h"

GridView::GridView(boost::shared_ptr<Grid> grid)
{
	this->grid = grid;

	Settings* settings = SettingsManager::get();
	squareSize.x = settings->squareWidth;
	squareSize.y = settings->squareHeight;
	this->showSquares = false;
	offset.x = 15 + ((459 - (squareSize.x * settings->columns))/2);
	offset.y = 76 + ((459 - (squareSize.y * settings->rows))/2);
	this->image = ImageManager::get()->getImage("Images/gamescreen.bmp");
	this->updatePosition(Point2D(0,0));
}

GridView::~GridView(void)
{
}

void GridView::draw(SDL_Surface* screen)
{
	std::vector< boost::shared_ptr<SquareView> > ::iterator it = squares.begin();
	for (;it != squares.end();++it)
	{
		(*it)->setShowDebug(showSquares);
		(*it)->updateAndDraw(screen);
		
	}
}
void GridView::update()
{

}

void GridView::createView()
{
	std::vector< std::vector< boost::shared_ptr<Square> > > modelGrid = grid->getGrid();

	
	std::vector< std::vector< boost::shared_ptr<Square> > >::iterator itm = modelGrid.begin();
	squares.clear();
	for (int x = 0;itm != modelGrid.end();++itm,++x)
	{
		for (unsigned int i = 0; i < (*itm).size(); ++i)
		{
			SquareView* tmp = new SquareView((*itm).at(i));
			tmp->updatePosition(Point2D( (x * squareSize.x)+offset.x, (i * squareSize.y)+offset.y) );



			squares.push_back(boost::shared_ptr<SquareView>(tmp));
			
		}
	}

}

Point2D GridView::squareCoordFromMouse(Point2D mouseCoord)
{
	Point2D tmp;
	tmp.x = (mouseCoord.x -offset.x)/ squareSize.x ;
	tmp.y = (mouseCoord.y -offset.y)/ squareSize.y ;
	return tmp;
}

void GridView::setShowSquares(bool show)
{
	this->showSquares = show;
}