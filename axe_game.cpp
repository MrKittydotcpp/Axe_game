#include "raylib.h"
int main()
{
    // window dimensions
    int width = 1240;
    int height = 860;
    InitWindow(width,height,"Stephen's Window");

    // circle coordinates
    int circle_x = 620;
    int circle_y = 430;
    int circle_radius{25};
    // circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    //axe coordinates
    int axe_x{420};
    int axe_y{0};
    int axe_length{50};
    // axe coordinates
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    int direction{4};

    bool collision_with_axe= 
                            (b_axe_y >= u_circle_y) &&
                            (u_axe_y <= b_circle_y) && 
                            (r_axe_x >= l_circle_x) &&
                            (l_axe_x <= l_circle_x);


    SetTargetFPS(120);
    while(WindowShouldClose() == false)
    {  
     BeginDrawing();
     ClearBackground(BLUE);

    if (collision_with_axe)
    {
       DrawText("Game Over!", 420,400,80,RED);
    }
    else
    {
         // Game logic begins

        // Update the edges
    l_circle_x = circle_x - circle_radius;
    r_circle_x = circle_x + circle_radius;
    u_circle_y = circle_y - circle_radius;
    b_circle_y = circle_y + circle_radius;  

    l_axe_x = axe_x;
    r_axe_x = axe_x + axe_length;
    u_axe_y = axe_y;
    b_axe_y = axe_y + axe_length;
    // update collision_with_axe
    collision_with_axe= 
                            (b_axe_y >= u_circle_y) &&
                            (u_axe_y <= b_circle_y) && 
                            (r_axe_x >= l_circle_x) &&
                            (l_axe_x <= l_circle_x);


     DrawCircle(circle_x,circle_y,circle_radius, WHITE);  
     DrawRectangle(axe_x,axe_y,axe_length,axe_length,BLACK);   

         // move the axe

        axe_y += direction;
        if (axe_y > height || axe_y < 0)
        {
            direction = -direction;
        }
        
        if (IsKeyDown(KEY_D) && circle_x < width)
        {
            circle_x +=5;
        }
        
        if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x -=5;
        }

        if (IsKeyDown(KEY_W) && circle_y > 0)
        {
            circle_y -=5;
        }

        if (IsKeyDown(KEY_S) && circle_y < height)
        {
            circle_y +=5;
        }
    
    }
    
    // Game logic ends
     EndDrawing();
   }
   
}