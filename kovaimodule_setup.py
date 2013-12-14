#!/usr/bin/env python
from distutils.core import setup, Extension

module1 = Extension('kovai', sources = ['kovaimodule.c'] )


setup ( name = 'Kovai',
        version  = '1.0',
        description = 'Kovai package',
        ext_modules = [module1]
     )

