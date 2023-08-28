# converts an object point in a 3d scene into a virtual image point
# It assumes ideal projection perspective.
# The coordinate system is left-handed and centered on the point of projection
# p is an (x,y,z) tuple and f is the focal point
# All units are assumed to be identical, but as long as your coordinate point units
# are consistent, the returned tuple will be the same units as your focal length.
def obj2Virtual3D(p, f):
  x = f * p[0] / p[2]
  y = f * p[1] / p[2]
  return (x,y)

# For two coplanar lines (that are not parallel) expressed by the general formulae
# a_1*x + b_1*y + c_1 = 0 and a_2*x + b_2*y + c_2 = 0,
# this function determines their point of intersection (x,y).
# l1 and l2 are tuples specifying the values of the coefficients and constants a, b, c.
# The function returns an x,y tuple representing the intersection point.
def pointOfIntersection2D(l1, l2):
  a1, b1, c1 = l1
  a2, b2, c2 = l2
  numerator = (c1/b1)-(c2/b2)
  denominator = (a1/b1)-(a2/b2)
  x = numerator / denominator
  y = (a1/b1) * x - (c1/b1)
  return (x,y)
