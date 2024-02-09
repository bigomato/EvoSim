#include "world.h"

World::World()
{
    width = 1000;
    height = 1000;
    w_width = 1000;
    w_height = 1000;
    time = 0;
}

/**
 * @brief Starts the simulation.
 *
 * This function initializes the simulation, runs the main loop, and cleans up resources after the simulation ends.
 *
 * @return 0 if the simulation completes successfully, 1 otherwise.
 */
int World::startSimulation()
{
    if (!init())
    {
        system("pause");
        return 1;
    }

    loop();

    kill();
    return 0;
}

World::~World()
{
}

/**
 * @brief Executes the main simulation loop.
 *
 * This function is responsible for running the main simulation loop, which handles events,
 * updates the simulation state, and renders the simulation. It continues running until the
 * `running` flag is set to false.
 */
void World::loop()
{
    bool running = true;
    Uint32 totalFrameTicks = 0;
    Uint32 totalFrames = 0;
    Uint32 lastUpdate = 0;
    while (running)
    {
        // Start frame timing
        totalFrames++;
        Uint32 startTicks = SDL_GetTicks();
        Uint64 startPerf = SDL_GetPerformanceCounter();

        // Handle events
        SDL_Event e;
        handleEvents(e, running);

        // Update
        Uint32 time = SDL_GetTicks();
        double dT = (time - lastUpdate) / 1000.0f;
        update(dT);

        // Draw
        draw();
        SDL_RenderPresent(renderer);

        // End frame timing
        Uint32 endTicks = SDL_GetTicks();
        Uint64 endPerf = SDL_GetPerformanceCounter();
        Uint64 framePerf = endPerf - startPerf;
        totalFrameTicks += endTicks - startTicks;
    }
}

/**
 * Handles SDL events and updates the running flag accordingly.
 *
 * @param e The SDL event to handle.
 * @param running A boolean flag indicating whether the program is running.
 */
void World::handleEvents(SDL_Event &e, bool &running)
{
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            running = false;
        }
        if (e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_ESCAPE)
            {
                running = false;
            }
        }
    }
}

/**
 * @brief Initializes the World object.
 *
 * This function initializes the SDL library, creates a window, and creates a renderer.
 *
 * @return true if initialization is successful, false otherwise.
 */
int World::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("EvoSim", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w_width, w_height, SDL_WINDOW_SHOWN);

    if (!window)
    {
        printf("Error creating window: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        printf("Error creating renderer: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

/**
 * @brief Updates the world by advancing the time by a given delta time.
 *
 * @param dt The delta time to advance the world by.
 */
void World::update(double dt)
{
    time += dt;
}

void World::draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

/**
 * @brief Destroys the renderer and window objects, sets them to NULL, and quits SDL.
 */
void World::kill()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;

    SDL_Quit();
}