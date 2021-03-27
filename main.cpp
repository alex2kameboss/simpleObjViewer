#include <BasicWindow.h>

int main() {
    BasicWindow window("Simple OBJ Viewer");

    if(window.init()){
        window.run();
    }

    return 0;
}
