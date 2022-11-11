#include <cs50.h>
#include <stdio.h>

void print_string(string s, int rep);
void print_layer(int s_gap, int m_gap, int n_brick);

int main(void)
{
    int height;

    // ask for user input
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    const int M_GAP = 2;
    int s_gap, n_brick;

    // print pyramids
    for (int i = 0; i < height; i++)
    {
        s_gap = height - i - 1;
        n_brick = i + 1;
        print_layer(s_gap, M_GAP, n_brick);
    }
}

void print_layer(int s_gap, int m_gap, int n_brick)
{
    print_string(" ", s_gap);   // print start gap
    print_string("#", n_brick); // print bricks (1st)
    print_string(" ", m_gap);   // print middle gap
    print_string("#", n_brick); // print bricks (2nd)
    printf("\n");
}

void print_string(string s, int rep)
{
    for (int i = 0; i < rep; i++)
    {
        printf("%s", s);
    }
}