#include <iostream>
#include <stdexcept>

#include "vostok/application.hxx"


int main()
{
    try {
        vostok::application app;

        app.run();
    }
    catch (std::runtime_error& ex) {
        std::cerr << "Failed to run the program: " << ex.what() << std::endl;
    }

    return 0;
}

// EOF
