##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile de Hoppy Tower Defense
##

SRC	=	src/main.c	\
		src/bgm/play.c	\
		src/enemy/create.c	\
		src/enemy/destroy.c	\
		src/enemy/position_to_2f.c	\
		src/enemy/refresh.c	\
		src/enemy/to_scene_object.c	\
		src/file/read.c	\
		src/file/exists.c	\
		src/file/to_level.c	\
		src/file/to_level_analyze.c	\
		src/hoppy/attack.c	\
		src/hoppy/create.c	\
		src/hoppy/cursor.c	\
		src/hoppy/destroy.c	\
		src/hoppy/generate.c	\
		src/hoppy/refresh.c	\
		src/hoppy/to_scene_object.c	\
		src/hoppy/upgrade.c	\
		src/input/create.c	\
		src/input/manage_controller.c	\
		src/input/manage_keyboard.c	\
		src/input/manage_mouse.c	\
		src/input/manage_numpad.c	\
		src/input/manage.c	\
		src/my_putstr.c	\
		src/object/circle/create.c	\
		src/object/text/create.c	\
		src/object/add_position.c	\
		src/object/child_malloc.c	\
		src/object/create.c	\
		src/object/destroy.c	\
		src/object/draw_outline.c	\
		src/object/draw.c	\
		src/object/is_hovering.c	\
		src/object/set_anchor.c	\
		src/object/set_size.c	\
		src/option_h.c	\
		src/scene/game/hud/coins.c	\
		src/scene/game/hud/health.c	\
		src/scene/game/hud/hoppy_update.c	\
		src/scene/game/hud/hoppy.c	\
		src/scene/game/hud/score.c	\
		src/scene/game/hud/wave.c	\
		src/scene/game/h_hud_update.c	\
		src/scene/game/h_hud.c	\
		src/scene/game/hud.c	\
		src/scene/game/main.c	\
		src/scene/game/path.c	\
		src/scene/game/valid_placement.c	\
		src/scene/title/button.c	\
		src/scene/title/display.c	\
		src/scene/title/screen.c	\
		src/scene/create.c	\
		src/scene/options_bgm.c	\
		src/scene/options_buttons.c	\
		src/scene/options_fps.c	\
		src/scene/options_sfx.c	\
		src/scene/options.c	\
		src/scene/replace.c	\
		src/scene/title.c	\
		src/sfx/destroy.c	\
		src/sfx/generate.c	\
		src/sfx/play.c	\
		src/wave/generator.c	\
		src/wave/new.c	\
		src/window/close.c	\
		src/window/create.c	\
		src/window/is_open.c	\
		src/color_player.c	\
		src/grid.c	\
		src/md_prog.c	\
		src/my_int_to_str.c	\
		src/my_str_to_array.c	\
		src/my_strfcts.c	\
		src/path.c	\
		src/start.c	\
		src/tick.c	\
		src/writerror.c	\

OBJ	=	$(SRC:.c=.o)

CLEAN	=	*~

NAME	=	my_defender

LCSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

IDIR	=	include

CFLAGS	=	-I$(IDIR) -I./include

RM	=	rm

all:	$(NAME)

$(NAME):	$(OBJ)
	unzip graphics.zip
	unzip sfx.zip
	rm graphics.zip
	rm sfx.zip
	gcc -o $(NAME) $(OBJ) $(LCSFML) $(CFLAGS) -lm

clean:
	$(RM) -f $(OBJ)
	$(RM) -f $(CLEAN)

fclean: clean
	$(RM) -f $(NAME)
	$(RM) -f a.out
	zip -r graphics.zip graphics
	zip -r sfx.zip sfx
	rm -r graphics
	rm -r sfx

play:	fclean all
	./my_defender

re:	fclean all

.PHONY: all fclean clean play re
