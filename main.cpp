#include <RenderWindow.h>
#include <ObjModel.h>

int main() {
    ObjModel obj("../objModels/cube_triangulated.obj");
    if (!obj.load())
        return -1;

    RenderWindow window;

    if(window.init()){
        window.run(obj);
    }

    return 0;
}
