#include <python2.6/Python.h>
//---- ref: http://en.wikibooks.org/wiki/Python_Programming/Extending_with_C
static PyObject* say_hello(PyObject* self, PyObject* args) {
   const char* name;
  if ( !PyArg_ParseTuple(args, "s", &name) ) {
  	return NULL;
  }  
  printf("Hello %s\n", name);
  Py_RETURN_NONE;
}

//---- method list
static PyMethodDef HelloMethods[]  = {
  { "say_hello", say_hello, METH_VARARGS, "Greet somebody." }
 ,{ NULL, NULL, 0, NULL }

};

//---- initing

PyMODINIT_FUNC

inithello(void) {
   (void) Py_InitModule("hello", HelloMethods);
}

