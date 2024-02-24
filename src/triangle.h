class Triangle
{
private:
    const int size;
    int width = 400, height = 400;
public:
    void transform3D();
    void transform2D();

    void multiply();
    void multiplyF();

    void projection();
    void system3D();

    void build();
    void rebuild();

    void rotateX();
    static void rotateY();
    void rotateZ();
    void transpose();
    void scale();

    void symmetryXY();
    void symmetryXZ();
    void symmetryYZ();
};