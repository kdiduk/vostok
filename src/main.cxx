#include <SDL3/SDL.h>


int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("SDL_Init failed (%s)", SDL_GetError());
        return 1;
    }

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) < 0) {
        SDL_Log("SDL_CreateWindowAndRenderer failed (%s)", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_SetWindowTitle(window, "SDL issue");

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

        SDL_SetRenderDrawColor(renderer, 80, 80, 80, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    
    return 0;
}

// EOF
