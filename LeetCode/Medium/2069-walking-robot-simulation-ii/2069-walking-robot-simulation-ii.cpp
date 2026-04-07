class Robot {
public:
    int x, y, dir;
    int width, height;
    int cycle;

    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        x = 0; y = 0;
        dir = 0; // East
        cycle = 2 * (width + height) - 4;
    }

    void step(int num) {
        num %= cycle;

        // Special case
        if (num == 0) {
            if (x == 0 && y == 0)
                dir = 3; // South
            return;
        }

        while (num > 0) {
            if (dir == 0) { // East
                int move = min(num, width - 1 - x);
                x += move;
                num -= move;
                if (num > 0) dir = 1;
            }
            else if (dir == 1) { // North
                int move = min(num, height - 1 - y);
                y += move;
                num -= move;
                if (num > 0) dir = 2;
            }
            else if (dir == 2) { // West
                int move = min(num, x);
                x -= move;
                num -= move;
                if (num > 0) dir = 3;
            }
            else { // South
                int move = min(num, y);
                y -= move;
                num -= move;
                if (num > 0) dir = 0;
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};