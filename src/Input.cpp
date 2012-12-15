#include "Input.h"

Input::Input(boost::shared_ptr<View> view)
{
	this->view = view;
	state.exit = false;
}

Input::~Input(void)
{
}



void Input::update()
{
	pollInput();

	view->updateInput(state);
}

bool Input::getExit()
{
	return state.exit;
}


void Input::pollInput()
{
	state.leftMouseHit = false;
	state.leftMouseUp = false;
	state.anyKey = false;
	state.anyMouseButton = false;
	SDL_Event event;
	SDL_GetMouseState(&state.mouseCoord.x,&state.mouseCoord.y );
    while (SDL_PollEvent(&event))
    {
        // check for messages
        switch (event.type)
        {
            // exit if the window is closed
        case SDL_QUIT:
		{
			state.exit = true;
            break;
		}
            // check for keypresses
        case SDL_KEYDOWN:
        {

            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                {
					state.exit = true;
                    break;
                }
				case SDLK_F9:
					{
						SettingsManager::get()->delayTime = 20;
						break;
					}
				case SDLK_F10:
					{
						SettingsManager::get()->delayTime = 80;
						break;
					}
					case SDLK_F11:
					{
						SettingsManager::get()->delayTime = 150;
						break;
					}
				
            }
			state.anyKey = true;
            break;
        }
		
		case SDL_MOUSEBUTTONDOWN:
		{
			state.anyMouseButton = true;
			if ( event.button.button == SDL_BUTTON_LEFT )
			{
				state.leftMouseHit = true;
				//state.mouseCoord.x = event.button.x;
				//state.mouseCoord.y = event.button.y;
				
				//Kernel::getInstance().kill();
			} else if (event.button.button == SDL_BUTTON_RIGHT )
			{
				
				//state.rightMouseDown = true;
			}

			break;
		}
		case SDL_MOUSEBUTTONUP:
		{
			if (event.button.button == SDL_BUTTON_RIGHT )
			{
				
				//state.rightMouseDown = false;
			} else if (event.button.button == SDL_BUTTON_LEFT)
			{
				state.leftMouseUp = true;
			}
			break;
		}
        } // end switch
    } // e

}