#include "vostok/application.hxx"

#include <iostream>
#include <stdexcept>

#include <boost/algorithm/string/join.hpp>
#include <boost/log/trivial.hpp>

#include <SDL2/SDL_vulkan.h>

#include <vulkan/vulkan_core.h>


namespace vostok {


application::application()
{
    init_sdl();
    init_vulkan();
}


application::~application()
{
    vkDestroyInstance(_vk_instance, nullptr);

    SDL_DestroyWindow(_window);
    SDL_Quit();
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
    }
}


void application::init_sdl()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("SDL_Init failed (%s)", SDL_GetError());
        throw std::runtime_error("SDL initialization failed");
    }

    _window = SDL_CreateWindow(
            "Vostok",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            960,
            540,
            SDL_WINDOW_VULKAN);
    if (!_window) {
        SDL_Log("SDL_CreateWindow failed (%s)", SDL_GetError());
        SDL_Quit();
        throw std::runtime_error("SDL initialization failed");
    }
}


void application::init_vulkan()
{
    _vk_instance = create_vulkan_instance();

}


VkInstance application::create_vulkan_instance() const
{
    auto&& extensions = get_required_vk_instance_extensions();
    
    VkInstanceCreateInfo create_info = {};
    create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create_info.enabledExtensionCount = static_cast<std::uint32_t>(extensions.size());
    create_info.ppEnabledExtensionNames = extensions.data();
    
    VkInstance instance = {};
    VkResult result = vkCreateInstance(&create_info, nullptr, &instance);
    if (result != VK_SUCCESS) {
        BOOST_LOG_TRIVIAL(error) << "Failed to create Vulkan instance";
        throw std::runtime_error("vkCreateInstance() call failed");
    }

    BOOST_LOG_TRIVIAL(trace) << "Vulkan instance has been successfully created";

    return instance;
}


std::vector<const char*> application::get_required_vk_instance_extensions() const
{
    unsigned int count = 0;
    if (!SDL_Vulkan_GetInstanceExtensions(_window, &count, nullptr)) {
        BOOST_LOG_TRIVIAL(error) << "Failed to get Vulkan instance extensions required for SDL";
        throw std::runtime_error("SDL_Vulkan_GetInstanceExtensions() call failed");
    }

    std::vector<const char*> extensions(count);
    if (!SDL_Vulkan_GetInstanceExtensions(_window, &count, extensions.data())) {
        BOOST_LOG_TRIVIAL(error) << "Failed to get Vulkan instance extension required for SDL";
        throw std::runtime_error("SDL_Vulkan_GetInstanceExtensions() call failed");
    }

    BOOST_LOG_TRIVIAL(debug)
            << "Vulkan extensions required by SDL: "
            << boost::algorithm::join(
                    std::vector<std::string>(extensions.begin(), extensions.end()),
                    ", ");
    
    return extensions;
}


} // namespace vostok

// EOF
