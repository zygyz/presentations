#include <Python.h>
#include "sim/init.hh"
int main(int argc, char **argv) {
    int ret;
    initSignals();
    Py_SetProgramName(argv[0]);
    // initialize embedded Python interpreter
    Py_Initialize();
    // Initialize the embedded m5 python library
    ret = initM5Python();
    if (ret == 0) {// start m5
        ret = m5Main(argc, argv);
    }
    Py_Finalize();
    return ret;
}
