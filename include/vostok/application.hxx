#ifndef VOSTOK_APPLICATION_HXX_221F5193_98E7_461F_8D86_90428FD21989
#define VOSTOK_APPLICATION_HXX_221F5193_98E7_461F_8D86_90428FD21989

#include <vector>

#include <SDL2/SDL.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>


namespace vostok {

class application final {
public:
    application();
    ~application();
    void run();

private:
    void init_sdl();
    void init_vulkan();

    VkInstance create_vulkan_instance() const;
    std::vector<const char*> get_vulkan_instance_extensions() const;
    
    SDL_Window* _window {nullptr};
    VkInstance _vk_instance;
};

} // namespace vostok

#endif // VOSTOK_APPLICATION_HXX_221F5193_98E7_461F_8D86_90428FD21989
