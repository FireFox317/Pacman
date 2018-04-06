/// \file
/// main.cpp

/*
 *  Created on: Jan 29, 2015
 *      Author: frits
 *       Group: TA's
 */

#include "GameObjectStruct.h"
#include "UI.h"
#include <Game.h>
#include <SDL2/SDL.h>
#include <vector>


Uint32 updateTimer(Uint32 interval, void* param) {
	static_cast<Game*>(param)->move();
	return interval;
}

/// Program entry point.
int main(int /*argc*/, char ** /*argv*/)
{
	std::vector<std::vector<int>> map = { {
			#include "board.def"
		} };

	UI ui(map);
	Game game(map);

    // Start timer for game update, call this function every 100 ms.
    SDL_TimerID timer_id =
        SDL_AddTimer(50, updateTimer, static_cast<void *>(&game));

    // Example object, this can be removed later
	
	game.init();

	ui.setLives(game.getLives());
	ui.setScore(game.getScore());

    // Call game init code here


    bool quit = false;
    while (!quit) {
        // set timeout to limit frame rate
        Uint32 timeout = SDL_GetTicks() + 20;

        // Handle the input
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            // Quit button.
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            // All keydown events
            if (e.type == SDL_KEYDOWN) {
				
				game.input(e.key.keysym.sym);
				if (e.key.keysym.sym == SDLK_ESCAPE) {
					quit = true;
				}
            }
        }

        // Set the score
		game.update();

        // Render the scene
		game.render();

		ui.update(game.getStructs());
		ui.setLives(game.getLives());
		ui.setScore(game.getScore());

        while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
            // ... do work until timeout has elapsed
        }
    }

    SDL_RemoveTimer(timer_id);

    return 0;
}