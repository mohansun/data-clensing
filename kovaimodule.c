#include <python2.6/Python.h>

//Kovai module
//--- ref: http://en.wikibooks.org/wiki/Python_Programming/Extending_with_C
static PyObject* editdistance(PyObject* self, PyObject* args) {
   const char* s1;
   const char* s2;
  if ( !PyArg_ParseTuple(args, "ss", &s1,&s2) ) {
	return NULL;
  }
  return Py_BuildValue("i", levenshtein(s1,s2) );
}

static PyObject* fuzzyscore(PyObject* self, PyObject* args) {
   const char* s1;
   const char* s2;
  if ( !PyArg_ParseTuple(args, "ss", &s1,&s2) ) {
	return NULL;
  }
  return Py_BuildValue("i", matchscore(s1,s2) );
}



//------ method list
static PyMethodDef kovaiMethods[]  = {
  { "editdistance", editdistance, METH_VARARGS, "editdistance" }
 ,{ "fuzzyscore",   fuzzyscore,   METH_VARARGS, "fuzzyscore" }
 ,{ NULL, NULL, 0, NULL }

};

//---- initing

PyMODINIT_FUNC

initkovai(void) {
   (void) Py_InitModule("kovai", kovaiMethods);
}

//--- http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int matchscore(char *s1, char *s2) {
  return 1 ;
}
 
int levenshtein(char *s1, char *s2) {
    //printf ("s1 %s s2 %s", s1, s2);
    unsigned int x, y, s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int matrix[s2len+1][s1len+1];
    matrix[0][0] = 0;
    for (x = 1; x <= s2len; x++)
        matrix[x][0] = matrix[x-1][0] + 1;
    for (y = 1; y <= s1len; y++)
        matrix[0][y] = matrix[0][y-1] + 1;
    for (x = 1; x <= s2len; x++)
        for (y = 1; y <= s1len; y++)
            matrix[x][y] = MIN3(matrix[x-1][y] + 1, matrix[x][y-1] + 1, matrix[x-1][y-1] + (s1[y-1] == s2[x-1] ? 0 : 1));
 
    return(matrix[s2len][s1len]);
}
