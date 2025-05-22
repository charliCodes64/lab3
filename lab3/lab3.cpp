

#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_native_dialog.h>


int main()
{
	al_init();

	//specs and set up for display
	const int width = 800;
	const int height = 700;
	ALLEGRO_DISPLAY* display = al_create_display(width, height);
	al_init_primitives_addon();

	//checks if allegro can be initiated
	if (!al_init()) {
		al_show_native_message_box(NULL, NULL, NULL, "Cannot initalize Allegro 5!", NULL, NULL);
	}

	//checks if display works
	if (!display) {
		al_show_native_message_box(NULL, NULL, NULL, "Cannot initalize Display!", NULL, NULL);
	}

	bool draw = false, done = false;

	//centers
	int posx = width / 2;
	int posy = height / 2;

	//creates a queue for actions executing them in order
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;

	//initializes 
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	//fonts used 
	ALLEGRO_FONT* font24 = al_load_font("Starbim.ttf",22,0);
	ALLEGRO_FONT* font25 = al_load_font("Chonky Bunny.ttf", 28, 0);
	ALLEGRO_FONT* font26 = al_load_font("911porschav3bold.ttf", 24, 0);
	ALLEGRO_FONT* font27 = al_load_font("Future Glitch.ttf", 24, 0);

	//creates queue of events
	event_queue = al_create_event_queue();

	//added these due to a issue with getting fonts to work and this helpped a lot (lets me know which font want work)
	if (!font24) {
		al_show_native_message_box(NULL, NULL, "errorf", "Cannot initalize Font 24!", NULL, NULL);
	}
	if (!font25) {
		al_show_native_message_box(NULL, NULL, "errorf", "Cannot initalize Font 25!", NULL, NULL);
	}
	if (!font26) {
		al_show_native_message_box(NULL, NULL, "errorf", "Cannot initalize Font 26!", NULL, NULL);
	}
	if (!font27) {
		al_show_native_message_box(NULL, NULL, "errorf", "Cannot initalize Font 27!", NULL, NULL);
	}

	//listens to events that happen in display 
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_clear_to_color(al_map_rgb(0, 0, 0));

	//checks if mouse is found
	if (!al_install_mouse()) {
		al_show_native_message_box(NULL, NULL, NULL, "Cannot initalize Mouse!", NULL, NULL);
	}
	//listens to events performed by the mouse
	al_register_event_source(event_queue, al_get_mouse_event_source());
	
	//countinues until done = true;
	while (!done) {

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		//stops when display is closed
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}
		//checking if mouse button is being clicked
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			//getting mouse coordinates by where user clicks
			if (ev.mouse.button & 1) {
				draw = true;
				posx = ev.mouse.x;
				posy = ev.mouse.y;
			}
		}
		if (draw) {
			//setting rectangle location, font location, cords, and color when user clicks on the display at a certain point
			if (posx <= 400 && posx >= 0 && posy >= 0 && posy <= 350) {
				al_draw_filled_rectangle(0, 0, 400, 350, al_map_rgb(255, 255, 255));
				al_draw_textf(font24, al_map_rgb(0, 0, 0), posx, posy, ALLEGRO_ALIGN_LEFT, "Mouse located at %d / %d", posx, posy);
				al_flip_display();
			}
			else if (posx >= 401 && posx <= 800 && posy >= 0 && posy <= 350) {
				al_draw_filled_rectangle(400, 0, 800, 350, al_map_rgb(0, 0, 0));
				al_draw_textf(font25, al_map_rgb(255, 255, 255), posx, posy, ALLEGRO_ALIGN_LEFT, "Mouse located at = %i / %i", posx, posy);
				al_flip_display();
			}
			else if (posx >= 0 && posx <= 400 && posy >= 351 && posy <= 700) {
				al_draw_filled_rectangle(0, 351, 400, 700, al_map_rgb(0, 0, 255));
				al_draw_textf(font26, al_map_rgb(255, 255, 0), posx, posy, ALLEGRO_ALIGN_LEFT, "Mouse located at = %i / %i", posx, posy);
				al_flip_display();
			}
			else if (posx >= 400 && posx <= 800 && posy >= 350 && posy <= 700) {
				al_draw_filled_rectangle(400, 350, 800, 700, al_map_rgb(255, 255, 0));
				al_draw_textf(font27, al_map_rgb(0, 0, 255), posx, posy, ALLEGRO_ALIGN_LEFT, "Mouse located at = %i / %i", posx, posy);
				al_flip_display();
			}
			draw = false;
		}
		//clears color from display
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);//destroy our display object
	system("pause");
}

