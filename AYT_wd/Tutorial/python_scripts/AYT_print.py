"""this file contains print functionalities for zoo classes
"""
import Tutorial.AYT_tutorial as AYT

AYT.Zoo.__str__ = lambda x: 'Zoo: {}'.format(x.name)