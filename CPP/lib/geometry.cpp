int cross(int a, int b, int c, int d){
    return a * d - b * c;
}

//(x1, y1) -> (x2, y2) と(a1, b1) -> (a2, b2)の交差判定
int line_crossing(int x1, int y1, int x2, int y2, int a1, int b1, int a2, int b2){
    int vx = x2 - x1;
    int vy = y2 - y1;

    int s = cross(vx, vy, a1 - x1, b1 - y1);
    int t = cross(vx, vy, a2 - x1, b2 - y1);
    return s > 0 && t > 0 || s < 0 && t < 0;
}
