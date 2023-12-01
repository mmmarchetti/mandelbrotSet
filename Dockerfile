# Use an official Ubuntu runtime as a base image
FROM ubuntu:latest

# Set the working directory inside the container
WORKDIR /mandelbrot

# Update the package list and install necessary dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    libsdl2-dev

ENV XDG_RUNTIME_DIR=/tmp

# Copy the local code to the container
COPY . .

# Compile the C++ code
RUN g++ -std=c++23 -o mandelbrotSet mandelbrotSet.cpp -lSDL2

# Specify the command to run on container start
CMD ["./mandelbrotSet"]
