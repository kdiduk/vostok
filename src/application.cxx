#include "vostok/application.hxx"

namespace vostok {


application::application()
{
}


application::~application()
{
}


void application::run()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("SDL_Init failed (%s)", SDL_GetError());
        return;
    }

    if (SDL_CreateWindowAndRenderer(640, 480, 0, &_window, &_renderer) < 0) {
        SDL_Log("SDL_CreateWindowAndRenderer failed (%s)", SDL_GetError());
        SDL_Quit();
        return;
    }
    SDL_SetWindowTitle(_window, "SDL issue");

    while (1) {
        bool finished = false;

	SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                finished = true;
                break;
            }
        }
	
        if (finished) {
            break;
        }

        SDL_SetRenderDrawColor(_renderer, 80, 80, 80, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(_renderer);
        SDL_RenderPresent(_renderer);
    }

    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);

    SDL_Quit();  
}

} // namespace vostok

// EOF
