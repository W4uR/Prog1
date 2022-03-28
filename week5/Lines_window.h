#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );

	Open_polyline lines;
	Menu color_menu;
	Button color_menu_button;
	Menu style_menu;
	Button style_menu_button;

    static void cb_color_menu(Address,Address);
	static void cb_style_menu(Address,Address);

	static void cb_red(Address,Address);
	static void cb_blue(Address,Address);
	static void cb_black(Address,Address);

	void red_pressed(){change_color(Color::red); redraw();}
	void blue_pressed(){change_color(Color::blue); redraw();}
	void black_pressed(){change_color(Color::black); redraw();}
	void change_color(Color c){lines.set_color(c);hide_color_menu();}

    void change_style(Line_style ls){lines.set_style(ls); hide_style_menu(); redraw();}

    void hide_color_menu(){color_menu.hide(); color_menu_button.show();}
	void hide_style_menu(){style_menu.hide(); style_menu_button.show();}

	void color_menu_pressed(){color_menu_button.hide();color_menu.show();}
	void style_menu_pressed(){style_menu_button.hide();style_menu.show();}

	bool wait_for_button();

private:
	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();

};


