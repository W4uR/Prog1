/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/

/*
    Graph.cpp and Windows.cpp are needed
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2;}
double square(double x) { return x*x; }
double sloping_cos(double x) {return cos(x) + slope(x);};

int main()
{
    using namespace Graph_lib;

    int width = 600;
    int height = 600;

    int x_orig = width/2;
    int y_orig = height/2;

    double r_min = -10;
    double r_max = 11;

    int scale = 20;
    int axis_length = 400;
    int axis_offset = (width - axis_length) / 2;
    int n_point = 400;

    Simple_window win {Point{100,100}, width, height, "Function graphs."};

	Point origo {x_orig, y_orig};

    Axis x {Axis::x, Point{axis_offset, y_orig}, axis_length, axis_length/scale, "1==20 pixels"};
    Axis y {Axis::y, Point{x_orig, height - axis_offset}, axis_length, axis_length/scale, "1==20 pixels"};
	
    x.set_color(Color::red);
    y.set_color(Color::red);

    Function f_one{one,r_min,r_max,origo,n_point,scale,scale};
    Function f_slope{slope,r_min,r_max,origo,n_point,scale,scale};
    Text t_slope{Point{x_orig + r_min * scale, y_orig - (slope(r_min) * scale + 10)},"x/2"};
    t_slope.set_color(Color::black);

    Function f_square(square,r_min,r_max,origo,n_point,scale,scale);

    Function f_cosine{cos,r_min,r_max,origo,n_point,scale,scale};    

    f_cosine.set_color(Color::blue);

    Function f_sloping_cosine{sloping_cos,r_min,r_max,origo,n_point,scale,scale};


    win.attach(x);
    win.attach(y);
    win.attach(f_one);
    win.attach(f_slope);
    win.attach(t_slope);
    win.attach(f_square);
    win.attach(f_cosine);
    win.attach(f_sloping_cosine);


    win.wait_for_button();

}
