#include <RenderWindow.h>
#include <ObjModel.h>

int main() {
    //ObjModel obj("../objModels/cube_triangulated.obj"); // triangulated cube, small object
    //ObjModel obj("../objModels/cube_untriangulated.obj"); // untriangulated cube, small object
    ObjModel obj("../objModels/largeObject.obj"); // large object
    if (!obj.load())
        return -1;

    RenderWindow window;

    if(window.init()){
        window.run(obj);
    }

    return 0;
}
