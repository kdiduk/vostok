#ifndef VOSTOK_APPLICATION_HXX_221F5193_98E7_461F_8D86_90428FD21989
#define VOSTOK_APPLICATION_HXX_221F5193_98E7_461F_8D86_90428FD21989

#include <SDL2/SDL.h>


namespace vostok {

class application final {
public:
    application();
    ~application();
    void run();

private:
    void init_sdl();
    void init_vulkan();
    void shutdown_sdl();

    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;

};

} // namespace vostok

#endif // VOSTOK_APPLICATION_HXX_221F5193_98E7_461F_8D86_90428FD21989
