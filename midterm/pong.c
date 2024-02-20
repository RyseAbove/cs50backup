// Header files
#define _DEFAULT_SOURCE
#include <cs50.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

// Constants
#define BOARD_HEIGHT 25
#define BOARD_WIDTH 90
#define PADDLE_SIZE 7

// Board
int board[BOARD_HEIGHT][BOARD_WIDTH];

// Inputs
char INPUTS[4];

// Gamestate
string gamestate = "game_start";

// Score
int player_1_score = 0;
int player_2_score = 0;

// Paddle coordinates
int paddle_left_y;
int paddle_right_y;

// The ball logic
int ball_speed = 2;
int ball_countdown = 0;
int ball_x_velocity;
int ball_y_velocity;
int ball_x;
int ball_y;

// The winner
string winner;

// Functions
void greet(void);
void initialize(void);
void gameManager(string state);
void renderBoard(void);
void updatePaddle(char key);
void updateBall(void);
int kbhit(void);

int main(void)
{
    // Clear system on start
    system("clear");

    // Start the board
    initialize();

    // Greet the player
    greet();

    // Run the main game
    while (true)
    {
        gameManager(gamestate);
        usleep(100000);
        if (strcmp(gamestate, "end") == 0)
        {
            return 0;
        }
    }
}

// Greets the player and shows them the controls
void greet()
{
    system("clear");
    printf("WELCOME TO THE GAME OF PONG\n");
    usleep(3000000);
    system("clear");
    printf("Controls:\n   Player 1:\n      up - %c\n      down - %c\n   Player 2:\n      up - %c\n      down - %c\nPRESS ANY KEY "
           "TO BEGIN",
           INPUTS[0], INPUTS[1], INPUTS[2], INPUTS[3]);
    while (true)
    {
        if (kbhit())
        {
            break;
        }
    }
}

// Initialize the board
void initialize(void)
{
    // Populate some variables
    INPUTS[0] = 'w';
    INPUTS[1] = 's';
    INPUTS[2] = 'i';
    INPUTS[3] = 'k';
    paddle_left_y = floor(BOARD_HEIGHT / 2) - floor(PADDLE_SIZE / 2);
    paddle_right_y = floor(BOARD_HEIGHT / 2) - floor(PADDLE_SIZE / 2);
    ball_x_velocity = 0;
    ball_y_velocity = 0;

    // Find the middles
    int middle_height = floor(BOARD_HEIGHT / 2);
    int middle_width = floor(BOARD_WIDTH / 2);
    int half_paddle = floor(PADDLE_SIZE / 2);

    // Place the ball
    board[middle_height][middle_width] = 2;
    ball_x = middle_width;
    ball_y = middle_height;

    // Place the paddles
    for (int i = middle_height - half_paddle; i < (middle_height - half_paddle) + PADDLE_SIZE; i++)
    {
        board[i][0] = 1;
        board[i][BOARD_WIDTH - 1] = 1;
    }

    // Place the floor and ceiling
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        board[0][i] = 3;
        board[BOARD_HEIGHT - 1][i] = 3;
    }

    board[0][middle_width - 2] = 4;
    board[0][middle_width - 1] = 0;
    board[0][middle_width] = 5;
    board[0][middle_width + 1] = 0;
    board[0][middle_width + 2] = 6;
}

void gameManager(string state)
{
    renderBoard();
    // The game_start gamestate
    if (strcmp(state, "game_start") == 0)
    {
        ball_x = floor(BOARD_WIDTH / 2);
        ball_y = floor(BOARD_HEIGHT / 2);
        // The initial pause
        for (int i = 0; i < 50; i++)
        {
            renderBoard();
            if (kbhit())
            {
                char key = getchar();
                updatePaddle(key);
            }
            usleep(100000);
        }
        gamestate = "active";
        // The velocity is "randomized" here
        if (player_1_score % 2 == 0)
        {
            ball_x_velocity = 1;
        }
        else
        {
            ball_x_velocity = -1;
        }
        if (player_2_score % 2 == 0)
        {
            ball_y_velocity = 1;
        }
        else
        {
            ball_y_velocity = -1;
        }
    }
    // The active game_state
    if (strcmp(state, "active") == 0)
    {
        updateBall();
    }
    // The game ends
    if (strcmp(state, "end") == 0)
    {
        system("clear");
        printf("%s wins!\nFinal Score: %i - %i\n", winner, player_1_score, player_2_score);
    }
    // Update paddles
    if (kbhit())
    {
        char key = getchar();
        updatePaddle(key);
    }
}

// Render the current board
void renderBoard(void)
{
    system("clear");
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            // 0 indicates blank space
            if (board[i][j] == 0)
            {
                printf(" ");
            }
            // 1 indicates a paddle
            else if (board[i][j] == 1)
            {
                printf("\033[30;47m ");
                printf("\033[0m");
            }
            // 2 indicates the ball
            else if (board[i][j] == 2)
            {
                printf("o");
            }
            // 3 indicates a floor or ceiling tile
            else if (board[i][j] == 3)
            {
                printf("_");
            }
            // 4 indicates the player 1 score
            else if (board[i][j] == 4)
            {
                printf("%i", player_1_score);
            }
            // 5 indicates the little dash between scores
            else if (board[i][j] == 5)
            {
                printf("-");
            }
            // 6 indicates the player 2 score
            else if (board[i][j] == 6)
            {
                printf("%i", player_2_score);
            }
        }
        printf("\n");
    }
}

// Updates the paddles position based on input
void updatePaddle(char key)
{
    // Move the left paddle up
    if (key == INPUTS[0])
    {
        if (paddle_left_y != 1)
        {
            board[paddle_left_y - 1][0] = 1;
            if (paddle_left_y != BOARD_HEIGHT - PADDLE_SIZE)
            {
                board[paddle_left_y + PADDLE_SIZE - 1][0] = 0;
            }
            paddle_left_y--;
        }
    }
    // Move the left paddle down
    else if (key == INPUTS[1])
    {
        if (paddle_left_y != BOARD_HEIGHT - PADDLE_SIZE)
        {
            board[paddle_left_y + PADDLE_SIZE - 1][0] = 1;
            if (paddle_left_y != 1)
            {
                board[paddle_left_y - 1][0] = 0;
            }
            paddle_left_y++;
        }
    }
    // Move the right paddle up
    else if (key == INPUTS[2])
    {
        if (paddle_right_y != 1)
        {
            board[paddle_right_y - 1][BOARD_WIDTH - 1] = 1;
            if (paddle_right_y != BOARD_HEIGHT - PADDLE_SIZE)
            {
                board[paddle_right_y + PADDLE_SIZE - 1][BOARD_WIDTH - 1] = 0;
            }
            paddle_right_y--;
        }
    }
    // Move the right paddle down
    else if (key == INPUTS[3])
    {
        if (paddle_right_y != BOARD_HEIGHT - PADDLE_SIZE)
        {
            board[paddle_right_y + PADDLE_SIZE - 1][BOARD_WIDTH - 1] = 1;
            if (paddle_right_y != 1)
            {
                board[paddle_right_y - 1][BOARD_WIDTH - 1] = 0;
            }
            paddle_right_y++;
        }
    }
}

void updateBall()
{
    bool ball_gone = false;
    // Update the ball position
    if (ball_countdown == 0)
    {
        // Check for collision with the roof or floor
        if (ball_y - ball_y_velocity <= 0 || ball_y - ball_y_velocity >= BOARD_HEIGHT - 1)
        {
            ball_y_velocity *= -1;
        }
        // Check for left paddle collision
        if ((ball_x + ball_x_velocity <= 0 && board[ball_y - ball_y_velocity][0]) || board[ball_y][ball_x - 1] == 1)
        {
            ball_x_velocity *= -1;
            // If the ball lands directly in the middle of the paddle
            if (ball_y - ball_y_velocity == paddle_left_y + floor(PADDLE_SIZE / 2))
            {
                // Nudge the ball closer to 0 y velocity
                if (ball_y_velocity < 0)
                {
                    ball_y_velocity += 1;
                }
                else if (ball_y_velocity > 0)
                {
                    ball_y_velocity -= 1;
                }
                // Rocket the ball forward
                ball_x_velocity += 2;
            }
            // If the ball hits higher than the middle
            else if (ball_y - ball_y_velocity < paddle_left_y + floor(PADDLE_SIZE / 2))
            {
                // If the ball hits the tip
                if (ball_y - ball_y_velocity == paddle_left_y)
                {
                    if (ball_y - ball_y_velocity < 0)
                    {
                        ball_y_velocity *= -1;
                    }
                    // Reduce velocity
                    if (ball_x_velocity != 1)
                    {
                        ball_x_velocity -= 1;
                    }
                }
                // If the ball doesn't hit the tip
                else if (ball_y - ball_y_velocity != paddle_left_y)
                {
                    ball_x_velocity += 1;
                }
                ball_y_velocity += 1;
            }
            // If the ball hits lower than the middle
            else if (ball_y - ball_y_velocity > paddle_left_y + floor(PADDLE_SIZE / 2))
            {
                // If the ball hits the tip
                if (ball_y - ball_y_velocity == paddle_left_y + PADDLE_SIZE - 1)
                {
                    if (ball_y_velocity > 0)
                    {
                        ball_y_velocity *= -1;
                    }
                    // Reduce velocity
                    if (ball_x_velocity != 1)
                    {
                        ball_x_velocity -= 1;
                    }
                }
                // If the ball doesn't hit the tip
                else if (ball_y - ball_y_velocity != paddle_left_y + PADDLE_SIZE - 1)
                {
                    ball_x_velocity += 1;
                }
                ball_y_velocity -= 1;
            }
        }
        // Check for right paddle collision
        else if ((ball_x + ball_x_velocity >= BOARD_WIDTH - 1 && board[ball_y - ball_y_velocity][BOARD_WIDTH - 1]) ||
                 board[ball_y][ball_x + 1] == 1)
        {
            ball_x_velocity *= -1;
            // If the ball lands directly in the middle of the paddle
            if (ball_y - ball_y_velocity == paddle_right_y + floor(PADDLE_SIZE / 2))
            {
                // Nudge the ball closer to 0 y velocity
                if (ball_y_velocity < 0)
                {
                    ball_y_velocity += 1;
                }
                else if (ball_y_velocity > 0)
                {
                    ball_y_velocity -= 1;
                }
                // Rocket the ball forward
                ball_x_velocity += -2;
            }
            // If the ball hits higher than the middle
            else if (ball_y - ball_y_velocity < paddle_left_y + floor(PADDLE_SIZE / 2))
            {
                // If the ball hits the tip
                if (ball_y - ball_y_velocity == paddle_right_y)
                {
                    if (ball_y - ball_y_velocity < 0)
                    {
                        ball_y_velocity *= -1;
                    }
                    // Reduce velocity
                    if (ball_x_velocity != 1)
                    {
                        ball_x_velocity -= 1;
                    }
                }
                // If the ball doesn't hit the tip
                else if (ball_y - ball_y_velocity != paddle_right_y)
                {
                    ball_x_velocity += 1;
                }
                ball_y_velocity += 1;
            }
            // If the ball hits lower than the middle
            else if (ball_y - ball_y_velocity > paddle_right_y + floor(PADDLE_SIZE / 2))
            {
                // If the ball hits the tip
                if (ball_y - ball_y_velocity == paddle_right_y + PADDLE_SIZE - 1)
                {
                    if (ball_y_velocity > 0)
                    {
                        ball_y_velocity *= -1;
                    }
                    // Reduce velocity
                    if (ball_x_velocity != 1)
                    {
                        ball_x_velocity -= 1;
                    }
                }
                // If the ball doesn't hit the tip
                else if (ball_y - ball_y_velocity != paddle_right_y + PADDLE_SIZE - 1)
                {
                    ball_x_velocity += 1;
                }
                ball_y_velocity -= 1;
            }
        }
        // Check for collision with wall
        else if (ball_x + ball_x_velocity >= BOARD_WIDTH - 1 || ball_x + ball_x_velocity <= 0)
        {
            if (ball_x + ball_x_velocity >= BOARD_WIDTH - 1)
            {
                player_1_score++;
            }
            else if (ball_x + ball_x_velocity <= 0)
            {
                player_2_score++;
            }
            ball_x_velocity = 0;
            ball_y_velocity = 0;
            ball_gone = true;
            gamestate = "game_start";
        }
        // Update the position
        ball_countdown = ball_speed;
        board[ball_y][ball_x] = 0;
        if (ball_gone)
        {
            board[ball_y - ball_y_velocity][ball_x + ball_x_velocity] = 0;
            int middle_height = floor(BOARD_HEIGHT / 2);
            int middle_width = floor(BOARD_WIDTH / 2);
            board[middle_height][middle_width] = 2;
        }
        else
        {
            board[ball_y - ball_y_velocity][ball_x + ball_x_velocity] = 2;
        }
        // Update the velocity
        ball_y -= ball_y_velocity;
        ball_x += ball_x_velocity;
        // Check the scores
        if (player_1_score == 5)
        {
            winner = "Player 1";
            gamestate = "end";
        }
        else if (player_2_score == 5)
        {
            winner = "Player 2";
            gamestate = "end";
        }
    }
    // Update the countdown
    else
    {
        ball_countdown--;
    }
}

// If a key has been pressed recently, return true (don't ask me how it works I don't know either)
int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

