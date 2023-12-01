#include <iostream>
#include <SDL2/SDL.h>
#include <complex>

const int WIDTH = 800;
const int HEIGHT = 800;

int isMandelbrot(double x, double y) {
    std::complex<double> c(x, y);
    std::complex<double> z(0, 0);

    for (int i = 0; i < 100; i++) {
        z = std::pow(z, 2) + c;

        if (std::norm(z) > 10) {
            return i;
        }
    }

    return 0;
}

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    // Set the window size
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    SDL_RenderSetLogicalSize(renderer, WIDTH, HEIGHT);

    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

    Uint32* pixels;
    int pitch;

    SDL_LockTexture(texture, nullptr, reinterpret_cast<void**>(&pixels), &pitch);

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double point_x = std::lerp(-2.0, 2.0, static_cast<double>(x) / WIDTH);
            double point_y = std::lerp(-2.0, 2.0, static_cast<double>(y) / HEIGHT);

            int iterations = isMandelbrot(point_x, point_y);

            int colorValue = (iterations > 0) ? 255 - iterations * 10: 0; // Adjust color based on iterations

            // Assuming 32-bit RGBA format
            Uint32 color = SDL_MapRGBA(SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888), colorValue, colorValue, colorValue, 255);

            pixels[y * WIDTH + x] = color;
        }
    }

    SDL_UnlockTexture(texture);

    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);

    SDL_Delay(10000);

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
