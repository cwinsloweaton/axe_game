#include "raylib.h"

int main()
{
    int window_width{800};
    int window_height{450};
    InitWindow(window_width, window_height, "My Window");

    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    // Circle bounding box edges.
    int circle_left{circle_x - circle_radius};
    int circle_right{circle_x + circle_radius};
    int circle_top{circle_y - circle_radius};
    int circle_bottom{circle_y + circle_radius};

    int axe_x{400};
    int axe_y{0};
    int axe_length{50};
    // Axe bounding box edges.
    int axe_left{axe_x};
    int axe_right{axe_x + axe_length};
    int axe_top{axe_y};
    int axe_bottom{axe_y + axe_length};

    int direction{10};

    bool collision_with_axe{false};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);
            axe_y += direction;

            if (axe_y > window_height || axe_y < 0)
            {
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && circle_x < window_width)
            {
                circle_x += 10;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }


            axe_left = axe_x;
            axe_right = axe_x + axe_length;
            axe_top = axe_y;
            axe_bottom = axe_y + axe_length;

            circle_left = circle_x - circle_radius;
            circle_right = circle_x + circle_radius;
            circle_top = circle_y - circle_radius;
            circle_bottom = circle_y + circle_radius;

            if (axe_bottom >= circle_top &&
                axe_top <= circle_bottom &&
                axe_left <= circle_right &&
                axe_right >= circle_left)
            {
                collision_with_axe = true;
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}