#include "vostok/application.hxx"

#include <iostream>
#include <stdexcept>

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>


namespace vostok {


application::application()
{
    init_sdl();
    init_vulkan();
}


application::~application()
{
    shutdown_sdl();
}


void application::run()
{
    for (;;) {
        bool finished = false;

	SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
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
}


void application::init_sdl()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("SDL_Init failed (%s)", SDL_GetError());
        throw std::runtime_error("SDL initialization failed");
    }

    if (SDL_CreateWindowAndRenderer(640, 480, 0, &_window, &_renderer) < 0) {
        SDL_Log("SDL_CreateWindowAndRenderer failed (%s)", SDL_GetError());
        SDL_Quit();
        throw std::runtime_error("SDL initialization failed");
    }
    SDL_SetWindowTitle(_window, "SDL issue");
}


void application::init_vulkan()
{

    std::uint32_t n_ext = 0;
    auto result = vkEnumerateInstanceExtensionProperties(nullptr, &n_ext, nullptr);
    if (result == VK_SUCCESS) {
        std::cout << "Found " << n_ext << " vulkan extensions" << std::endl;
    }
    else {
        std::cout << "Failed to enumerate vulkan extensions" << std::endl;
    }
}


void application::shutdown_sdl()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);

    SDL_Quit();  
}


} // namespace vostok

// EOF
