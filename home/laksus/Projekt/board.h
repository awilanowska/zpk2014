class Board{
    ALLEGRO_DISPLAY *board = NULL;
    ALLEGRO_BITMAP *hero, *background, *obstacle_up, *obstacle_down, *endgame;
    ALLEGRO_FONT *font24;
    const int w = 800;
    const int h = 600;

public:
    void init(int bird_type);
    void close();
    void refresh_hero(double b_x, double b_y);
    void refresh_pipe(double p_x, double p_y);
    void refresh_background();
    void show();
    void end_game();

};
