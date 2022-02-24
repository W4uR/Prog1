#include "Simple_window.h"
#include "Graph.h"

/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/

int main()
{

	try
	{

	using namespace Graph_lib;
	
	Point tl{100,100};
	Simple_window win {tl,600,400,"My window"};
	
	Axis xa {Axis::x, Point{20,150},314,2,"x axis"};
	win.attach(xa);
	
	Axis ya {Axis::y, Point{20,300},300,3,"y axis"};
	ya.set_color(Color::red);
	win.attach(ya);	

	Function sine {sin,0,12.5,Point{20,150},150,25,50};
	win.attach(sine);


	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	
	
	Rectangle r{Point{200,200},100,50};
	r.set_fill_color(Color::yellow);
	
	win.attach(r);
	
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);
	
	Text t {Point{150,150}, "Hello, graphical world!"};
	win.attach(t);
	
	Image ii {Point{500,50},"mosoly.jpeg"};
	win.attach(ii);
	
	Circle c {Point{100,200},50};
	Ellipse e{Point{100,200},75,25};
	e.set_color(Color::dark_red);
	Mark m{Point{100,200},'x'};
	
	ostringstream oss;
	oss << "screen size: "<<x_max()<<"*"<<y_max()<<";window size: " << win.x_max() << "*" <<win.y_max();
	Text size {Point{100,20},oss.str()};
	
	Image cal{Point{225,225},"mosoly.jpeg"};
	cal.set_mask(Point{40,40},50,30);
	
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(size);
	win.attach(cal);
	
	win.wait_for_button();
	
	
	}
	catch(...){
		return 1;
	}
}
