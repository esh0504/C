#include<iostream>

using namespace std;

int main() {
	int w, h, f, c, x1, y1, x2, y2,arror;
	cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;
	int width = w * h;
	int height_num = c+1;
	if (w - f >= f) {
		arror = (x2 - x1) * (y2 - y1);
		if (f >= x1 && f <= x2) {
			cout <<width-(((f - x1) * (y2 - y1) + arror) * height_num)  << endl;
		}
		else if(f<=x1) {
			cout <<width-( arror *height_num) << endl;
		}
		else if(x2<=f){
			cout <<width-( arror*2*height_num)<< endl;
		}
	}
	else {
		arror = (x2 - x1) * (y2 - y1);
		if (x1<=w - f && x2>=w - f) {
			cout<<width-((((w-f)-x1)*(y2-y1)+arror)*height_num) <<endl;
		}
		else if (x1 >= w - f) {
			cout <<width- (arror * height_num) << endl;
		}
		else if(x2<=w-f){
			cout << width - (2 * (arror * height_num)) << endl;
		}
	}
	return 0;
}