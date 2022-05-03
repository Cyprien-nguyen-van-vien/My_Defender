/*
** EPITECH PROJECT, 2021
** htd.h
** File description:
** Hoppy notre bonheur
*/

#pragma once
    #define EXIT 0
    #define ERROR 84
    #define DEFAULT_SCR_X (int)1920
    #define DEFAULT_SCR_Y (int)1080
    #define SCR_X (int)1920
    #define SCR_X_HALF (int)960
    #define SCR_Y (int)1080
    #define SCR_Y_HALF (int)540
    #define HUD_X (int)300
    #define HUD_Y (int)1080
    #define LEVEL_X (int)(1920 - 300)
    #define LEVEL_Y (int)1080
    #define TILE 40
    #define PLAYERS_MAX (int)8
    #define ENEMIES_MAX (int)400
    #define ENEMIES_BORDER (int)2
    #define ENEMY_LIST_MAX (int)500
    #define HOPPIES_MAX (int)((LEVEL_X / TILE) * (LEVEL_Y / TILE) * 2 * 2)
    #define LINEBREAK (char)'\n'
    #define WIN_PARAMS sfClose | sfResize
    #define SEC_TO_DELTA(X) (X * 1000000)
    #define IS_DIGIT(X) ('0' <= X && X <= '9')
    #define ABS(X) ((X < 0) ? (0 - (X)) : (X))
    #define MIN(X, M) (((X) < M) ? (M) : (X))
    #define MAX(X, M) (((X) > M) ? (M) : (X))
    #define CAT(X, Y) (my_strcat(X, Y))
    #define LEN(X) (my_strlen(X))
    #define SFX_CHANNELS (int)10
    #define HOPPY_COUNT (int)8

    #include "htd_config.h"
    #include "htd_ermsg.h"
    #include "htd_filepaths.h"
    #include "htd_objects.h"
    #include <fcntl.h>
    #include <math.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/System/Time.h>
    #include <SFML/Window/Mouse.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <time.h>
    #include <unistd.h>

static const sfColor COLOR_GRAY_50 = {127, 127, 127, 255};

enum INPUTS {
    INPUTS_MOUSE = 1,
    INPUTS_KEYBOARD,
    INPUTS_NUMPAD,
    INPUTS_CONTROLLER0,
    INPUTS_CONTROLLER1,
    INPUTS_CONTROLLER2,
    INPUTS_CONTROLLER3,
    INPUTS_CONTROLLER4,
    INPUTS_SIZE = 8,
};

enum FONT {
    GOODDOG_PLAIN_TTF,
    FONT_SIZE,
};

enum SCN {
    SCN_BG,
    SCN_PATH,
    SCN_BG1,
    SCN_ENNEMIES,
    SCN_HOPPIES,
    SCN_HOPPY_HUD,
    SCN_HUD,
    SCN_SIZE,
};

enum JOYSTICK_BUTTONS {
    JB_B,
    JB_A,
    JB_Y,
    JB_X,
    JB_L,
    JB_R,
    JB_ZL,
    JB_ZR,
    JB_SELECT,
    JB_START,
    JB_LCLICK,
    JB_RCLICK,
    JB_HOME,
    JB_SCREENSHOT,
};

//Segment of the path of the level
//theta corresponds to the angle, using arctan(-b/a)
typedef struct md_path_t {
    sfVector2f point;
    float theta;
    float distance;
    int size;
} md_path_t;

//Contains datas about an hoppy
typedef struct md_hoppy_t {
    int cooldown;
    int damage;
    int delta_stored;
    float range;
    float speed;
    int owner;
    int texture;
    int cost;
    int level;
    int special;
    sfVector2i size;
    sfVector2i position;
} md_hoppy_t;

//Spare the sympathy, everybody wants to be my enemy
typedef struct md_enemy_t {
    float position;
    float speed;
    int delta_stored;
    int delta_slow;
    int camo;
    int health;
    int lead;
    int regrow;
    int coin;
} md_enemy_t;

//Never gonna struct you up
typedef struct md_bgm_t {
    sfMusic *music;
} md_bgm_t;

//Never gonna struct you down
typedef struct md_sfx_t {
    sfSound *sound;
    sfSoundBuffer *buffer;
    sfClock *clock;
} md_sfx_t;

//Informations about the mouse
typedef struct md_mouse_t {
    sfVector2i position;
} md_mouse_t;

//Contains different possible inputs
typedef struct md_inputs_t {
    int control_type;
    int select;
    int back;
    int exit;
    int up;
    int left;
    int down;
    int right;
} md_inputs_t;

//Contains what can be found in the option menu
typedef struct md_options_t {
    float bgm;
    int fps;
    float sfx;
} md_options_t;

typedef struct md_prog2i_t {
    int value;
    int min;
    int max;
} md_prog2i_t;

typedef struct md_wave_t {
    int wave;
    int enemy_delta;
    int enemy_list[ENEMY_LIST_MAX];
} md_wave_t;

//Contains what needs to be accessible at (almost) ANY time
typedef struct md_game_t {
    md_bgm_t bgm;
    int coins;
    int delta;
    sfClock *deltaclock;
    sfClock *permaclock;
    md_enemy_t enemy[ENEMIES_MAX];
    object_t *enemy_object[ENEMIES_MAX];
    md_hoppy_t hoppy[HOPPIES_MAX];
    object_t *hoppy_object[HOPPIES_MAX];
    md_hoppy_t hoppy_data[HOPPY_COUNT];
    int hoppy_data_count;
    int hoppy_selected[PLAYERS_MAX];
    sfFont *font[10];
    md_prog2i_t hearts;
    md_inputs_t input[PLAYERS_MAX];
    md_mouse_t mouse;
    object_t *mouse_object;
    md_options_t option;
    md_path_t *path;
    object_t *path_object;
    int score;
    int scene_closing;
    md_sfx_t sfx[SFX_CHANNELS];
    int wave;
    sfRenderWindow *window;
    sfVector2u window_size;
} md_game_t;

extern md_game_t GAME;

//Plays music, give as a filepath
void bgm_play(char const *path);
//Sets the volume of the bgm
void bgm_volume(float volume);
//Checks if a character is present inside a string 'sep'
int char_in_str(char const character, char const *sep);
//Returns a sfColor corresponding to a player
sfColor color_player_get(int id);
int file_exists(char const *path);
char *file_read(char const *path);
int file_to_level(char const *path);
void ftl_analyze(char const *str);
int enemy_create(int id);
void enemy_destroy(int const id);
void enemy_destroy_all(void);
sfVector2f enemy_position_to_2f(int const id);
void enemy_refresh(int const id);
void enemy_refresh_all(void);
void enemy_to_scene_object(object_t *scene_layer);
object_t *grid(void);
int hoppy_attack(int const id);
int hoppy_create(int const plyr);
sfVector2i hoppy_cursor(int plyr);
void hoppy_destroy(int const id);
void hoppy_destroy_all(void);
void hoppy_generate(void);
void hoppy_refresh(int const id);
void hoppy_refresh_all(void);
void hoppy_to_scene_object(object_t *scene_layer);
int upgrade_hoppy(int const id);
md_inputs_t *input_create(md_inputs_t *input);
void input_create_all(md_inputs_t *inputs);
void input_manage(int id);
void input_manage_controller(int id, int cid);
void input_manage_keyboard(int id);
void input_manage_mouse(int id);
void input_manage_numpad(int id);
int md_prog2i_set(md_prog2i_t *prog2i, int value, int min, int max);
object_t *mouse_object_get(int id);
int my_putstr(char const *str);
char *my_int_to_str(int);
//Concatenate two strings, returning a new string
//It only malloc, it DOESN'T free arguments
char *my_strcat(char const *str1, char const *str2);
//Returns the length of a string
int my_strlen(char const *string);
//Converts a string into an array of strings
//'sep' is a string containing all separators
char **my_str_to_array(char const *str, char const *sep);
void path_add(float x, float y);
void path_add_str(char const *arg);
void path_destroy_all(void);
void path_malloc(int size);
float path_pythagore(sfVector2f start, sfVector2f end);
float path_theta(sfVector2f start, sfVector2f end);
int print_h(void);
sfVector2f *ept2f_seg(sfVector2f *coor, float pos, int path_idx);
int regen(void);
object_t *scene_title_buttons(void);
object_t *scene_create(void);
void scene_game_hud_coins_update(object_t *object);
object_t *scene_game_hud_coins_create(void);
void scene_game_h_hud_update(object_t *object);
object_t *scene_game_h_hud_create(void);
object_t *scene_game_hud_health_create(void);
void scene_game_hud_health_update(object_t *object);
object_t *scene_game_hud_hoppy_create(void);
void scene_game_hud_hoppy_update(object_t *object);
object_t *scene_game_hud_create(void);
void scene_game_hud_score_update(object_t *object);
object_t *scene_game_hud_score_create(void);
void scene_game_hud_wave_update(object_t *object);
object_t *scene_game_hud_wave_create(void);
void scene_game_hud_update(object_t *object);
object_t *scene_game_path_create(void);
int scene_game_valid_placement(sfVector2f pos, sfVector2u size);
int scene_game_main(void);
int scene_options(object_t *title);
object_t *scene_options_buttons(void);
void scene_options_buttons_evt(object_t *buttons, int id);
void scene_options_fps(object_t *button);
void scene_options_fps_display(object_t *button, int fps);
void scene_options_bgm(object_t *button);
void scene_options_bgm_display(object_t *button, float bgm);
void scene_options_sfx(object_t *button);
void scene_options_sfx_display(object_t *button, float sfx);
object_t *scene_replace(object_t *, int index, object_t *object);
int scene_title(void);
int scene_title_screen(object_t *title);
void scene_title_screen_display(object_t *scene);
void sfx_destroy_channel(int id);
void sfx_destroy(void);
void sfx_generate(void);
void sfx_play(char const *path);
int start(int ac, char **av);
void tick(void);
int wave_generator(md_wave_t *wave);
int wave_new(md_wave_t *wave);
int window_close(void);
//Closes the window, write an error message then returns (int)ERROR
int window_crash(char const *message);
//Closes the window, write an error message then returns (char *)NULL
char *window_crash_null(char const *message);
void window_create(void);
sfBool window_is_open(void);
//Writes a string with (fd = 2) and returns ERROR
int writerror(char const *string);
