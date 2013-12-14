#!/usr/bin/env python
from distutils.core import setup, Extension

module1 = Extension('hello', sources = ['hellomodule.c'] )


setup ( name = 'PackageName',
        version  = '1.0',
        description = 'this is a demo package',
        ext_modules = [module1]
     )

