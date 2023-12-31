# Mandelbrot Set Renderer

This project is a simple Mandelbrot Set renderer using C++ and SDL.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Docker Support](#docker-support)
- [License](#license)

## Introduction

This project generates a Mandelbrot Set image and renders it using SDL. It demonstrates basic usage of C++ and SDL for graphics programming.

## Features

- Generate Mandelbrot Set images.
- Render the images using SDL.
- Adjustable parameters such as window size and iteration count.

## Requirements

- C++ compiler
- SDL2 library
- (Optional) Docker for containerized execution

## Getting Started

1. Clone the repository:

   ```bash
   git clone https://github.com/mmmarchetti/mandelbrotSet.git
   cd mandelbrotSet
   ```

2. Install SDL2 (if not already installed):

   ```bash
   sudo apt-get install libsdl2-dev
   ```

3. Build the project:

   ```bash
   g++ -o mandelbrot mandelbrot.cpp -lSDL2
   ```

## Usage

Run the compiled executable:

```bash
./mandelbrot
```

Adjust parameters in the code (e.g., window size, iteration count) for customization.

## Docker Support

If you encounter issues with running the project in your environment, Docker support is available. Follow the instructions in the Docker section of this README.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```
