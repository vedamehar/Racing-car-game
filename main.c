#include "raylib.h"
#include <stdlib.h>
#include <time.h>

// Screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Car properties
#define CAR_WIDTH 50
#define CAR_HEIGHT 100
#define CAR_SPEED 5

// Obstacle properties
#define OBSTACLE_WIDTH 50
#define OBSTACLE_HEIGHT 100
#define NUM_OBSTACLES 5
#define OBSTACLE_SPEED 3



// Road and pavement properties
#define ROAD_WIDTH 550
#define PAVEMENT_WIDTH ((SCREEN_WIDTH - ROAD_WIDTH) / 2)
#define STRIPE_WIDTH 15

typedef struct {
    Rectangle rect;
    bool active;
} Obstacle;

typedef struct {
    Vector2 position;
} Tree;

#define NUM_TREES 10
Tree trees[NUM_TREES];

void GenerateTrees() {
    for (int i = 0; i < NUM_TREES; i++) {
        trees[i].position.x = (rand() % 2 == 0) ? (PAVEMENT_WIDTH / 2) : (SCREEN_WIDTH - PAVEMENT_WIDTH / 2);
        trees[i].position.y = rand() % SCREEN_HEIGHT;
    }
}

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Racing Car Game");
    SetTargetFPS(100);
    srand(time(NULL));

    // Initialize car
    Rectangle car = {SCREEN_WIDTH / 2 - CAR_WIDTH / 2, SCREEN_HEIGHT - CAR_HEIGHT - 20, CAR_WIDTH, CAR_HEIGHT};
    int score = 0;
    bool gameOver = false;

    // Initialize obstacles
    Obstacle obstacles[NUM_OBSTACLES];
    for (int i = 0; i < NUM_OBSTACLES; i++) {
        obstacles[i].rect.x = PAVEMENT_WIDTH + rand() % (ROAD_WIDTH - OBSTACLE_WIDTH);
        obstacles[i].rect.y = rand() % (SCREEN_HEIGHT / 2) - SCREEN_HEIGHT;
        obstacles[i].rect.width = OBSTACLE_WIDTH;
        obstacles[i].rect.height = OBSTACLE_HEIGHT;
        obstacles[i].active = true;
    }

    GenerateTrees(); // Generate trees on pavement

    int countdown = 3;
    bool countdownActive = true;
    double countdownTimer = 0;

    while (!WindowShouldClose())
    {
        if (!gameOver) {
            if (countdownActive) {
                countdownTimer += GetFrameTime();
                if (countdownTimer >= 1) {
                    countdown--;
                    countdownTimer = 0;
                    if (countdown == 0) {
                        countdownActive = false;
                    }
                }
            } else {
                // Move car
                if (IsKeyDown(KEY_RIGHT) && car.x + CAR_WIDTH < SCREEN_WIDTH - PAVEMENT_WIDTH)
                    car.x += CAR_SPEED;
                if (IsKeyDown(KEY_LEFT) && car.x > PAVEMENT_WIDTH)
                    car.x -= CAR_SPEED;

                // Move obstacles
                for (int i = 0; i < NUM_OBSTACLES; i++) {
                    if (obstacles[i].active) {
                        obstacles[i].rect.y += OBSTACLE_SPEED;
                        if (obstacles[i].rect.y > SCREEN_HEIGHT) {
                            obstacles[i].rect.y = rand() % (SCREEN_HEIGHT / 2) - SCREEN_HEIGHT;
                            obstacles[i].rect.x = PAVEMENT_WIDTH + rand() % (ROAD_WIDTH - OBSTACLE_WIDTH);
                            score++;
                        }
                        if (CheckCollisionRecs(car, obstacles[i].rect))
                            gameOver = true;
                    }
                }

                // Move trees down (simulating movement)
                for (int i = 0; i < NUM_TREES; i++) {
                    trees[i].position.y += OBSTACLE_SPEED;
                    if (trees[i].position.y > SCREEN_HEIGHT) {
                        trees[i].position.y = -rand() % SCREEN_HEIGHT;
                    }
                }
            }
        }

        // Drawing
        BeginDrawing();
        ClearBackground(DARKGRAY);

        // Draw pavements with yellow-black stripes
        for (int i = 0; i < SCREEN_HEIGHT / 40; i++) {
            Color stripeColor = (i % 2 == 0) ? YELLOW : BLACK;
            DrawRectangle(0, i * 40, STRIPE_WIDTH, 40, stripeColor);
            DrawRectangle(SCREEN_WIDTH - STRIPE_WIDTH, i * 40, STRIPE_WIDTH, 40, stripeColor);
        }

        // Draw trees
        for (int i = 0; i < NUM_TREES; i++) {
            DrawCircleV(trees[i].position, 10, GREEN);
            DrawRectangleV((Vector2){trees[i].position.x - 2, trees[i].position.y + 10}, (Vector2){4, 10}, BROWN);
        }

        // Draw road lines
        for (int i = 0; i < SCREEN_HEIGHT / 20; i++) {
            DrawRectangle(SCREEN_WIDTH / 2 - 5, (i * 40 + (int)(GetTime() * 200) % 40) % SCREEN_HEIGHT, 10, 20, WHITE);
        }

        DrawRectangleRec(car, RED); // Draw car
        for (int i = 0; i < NUM_OBSTACLES; i++) {
            if (obstacles[i].active) {
                DrawRectangleRec(obstacles[i].rect, BLUE); // Draw obstacles
            }
        }

        DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);
        if (countdownActive) {
            DrawText(TextFormat("%d", countdown), SCREEN_WIDTH / 2 - 20, SCREEN_HEIGHT / 2 - 40, 80, RED);
        }
        if (gameOver) {
            DrawText("GAME OVER", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 20, 40, RED);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}