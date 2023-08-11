#include <iostream>
#include <vector>
using namespace std;
#include <utility>

// Lab - Line Drawing Algorithm
// En este codigo se implementa el algoritmo de Bresenham's 
// Gerardo Ulises Sanchez Felix - A01641788 
// Fuente: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm

pair<int, int> coordenadas;
vector <pair<int, int>> puntos;
// All cases implementation
void plotLineLow(int x0, int y0, int x1, int y1){
    int dx, dy, yi, D, y;
    dx = x1 - x0;
    dy = y1 - y0;
    yi = 1;

    if(dy < 0){
        yi = -1;
        dy = -dy;
    }
    D = (2 * dy) - dx;
    y = y0;
    
    for(int x = x0; x<=x1; x++){
        // cout <<"("<<x<<" "<<y<<")";
        coordenadas.first = x;
        coordenadas.second = y;
        puntos.push_back(coordenadas);
        if(D > 0){
            y = y + yi;
            D = D + (2 * (dy - dx));
        }else {
            D = D + 2*dy;
        }
    }
}

void plotLineHigh(int x0, int y0, int x1, int y1){
    int dx, dy, xi, D, x;
    dx = x1 - x0;
    dy = y1 - y0;
    xi = 1;
    if(dx < 0){
        xi = -1;
        dx = -dx;
    }
    D = (2 * dx) - dy;
    x = x0;

    for(int y = y0; y<=y1; y++){
        // cout <<"("<<x<<" "<<y<<")";
        coordenadas.first = x;
        coordenadas.second = y;
        puntos.push_back(coordenadas);
        if(D > 0){
            x = x + xi;
            D = D + (2 * (dx - dy));
        }else{
            D = D +2*dx;
        }
    }
}

void plotLine(int x0, int y0, int x1, int y1){
    if(abs(y1 - y0) < abs(x1 - x0)){
        if(x0 > x1){
            plotLineLow(x1, y1, x0, y0);
        }else{
            plotLineLow(x0, y0, x1, y1);
        }
    }else{
        if(y0>y1){
            plotLineHigh(x1, y1, x0, y0);
        }else{
            plotLineHigh(x0, y0, x1, y1);
        }
    }
}

int main (){
    int x1, x2, y1,y2;

    cout << "Ingrese el valor de las coordenadas del primer punto en el siguiente formato 'x y' :" << endl;
    cin >> x1 >> y1;
    cout << "Ingrese el valor de las coordenadas del segundo punto en el siguiente formato 'x y' :" << endl;
    cin >> x2 >> y2;    
    
    plotLine(x1,y1,x2,y2);
    for (size_t i = 0; i < puntos.size(); ++i) {
        cout << "(" << puntos[i].first << "," << puntos[i].second << ")\n";
    }

    return 0;
}