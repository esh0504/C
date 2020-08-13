#include<iostream>

using namespace std;

int main() {
	int w, h, f, c, x1, y1, x2, y2,arror;
	cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;
	int width = w * h;
	int height_num = c+1;
	int color = (y2 - y1) * (x2 - x1);
	if (w - f > f) {
		if (x2 <= f)cout << width - ((color * 2) * height_num) << endl;
		else if (x1 < f && f < x2) cout << width - (height_num * (color + ((f - x1) * (y2 - y1)))) << endl;
		else cout << width - (height_num * (color)) << endl;
	}
	else if(w-f==f){
		cout << width - (color * 2*height_num) << endl;
	}
	else {
		if (x2 <= w - f)cout << width - ((color * 2) * height_num) << endl;
		else if (x1 < w - f && w - f < x2)cout<<width-(height_num*(color+(((w-f)-x1)*(y2-y1)))) <<endl;
		else cout << width - (height_num * (color)) << endl;
		}
	return 0;
}