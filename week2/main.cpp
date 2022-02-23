/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    int cell_size = 100;
    int rows = 8;
    int cols = 8;

    Simple_window win {Point{100,100}, 800, 1000, "Canvas"};   

    Lines grid;
    Vector_ref<Rectangle> rects;

    // Sorok
    for(int row = 1; row <= rows; row++){
        grid.add(Point{0,cell_size*row}, Point{800,cell_size*row});
    }
    // Oszolopok
    for(int col = 1; col <= cols; col++){
        grid.add(Point{cell_size*col,0}, Point{cell_size*col,800});
    }
    
    // Négyzetek
    for(int i = 0; i < 8;i++){
        rects.push_back(new Rectangle{Point{cell_size*i,cell_size*i},cell_size,cell_size});
        rects[rects.size()-1].set_fill_color(Color::red);
        win.attach(rects[rects.size()-1]);
    }


    Image img1 {Point{cell_size * 2,cell_size * 4},"kave.jpg"};
    Image img2 {Point{cell_size * 2,cell_size * 6},"kave.jpg"};
    Image img3 {Point{cell_size * 6,cell_size * 2},"kave.jpg"};

    Image moving = {Point{cell_size,cell_size},"mosoly.jpeg"};

    win.attach(grid);
    win.attach(img1);
    win.attach(img2);
    win.attach(img3);

    win.attach(moving);

    int i = 0;
    while(i<5){
        win.wait_for_button();
        moving.move(cell_size,0);
        i++;
    }

}