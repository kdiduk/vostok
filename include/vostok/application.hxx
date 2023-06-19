#ifndef VOSTOK_APPLICATION_HXX_221F5193_98E7_461F_8D86_90428FD21989
#define VOSTOK_APPLICATION_HXX_221F5193_98E7_461F_8D86_90428FD21989

#include <SDL3/SDL.h>


namespace vostok {

class application final {
public:
    application();
    ~application();
    void run();

private:
    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;

};

} // namespace vostok

#endif // VOSTOK_APPLICATION_HXX_221F5193_98E7_461F_8D86_90428FD21989
