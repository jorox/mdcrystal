#include "aatom.h"

AbstractAtom::AbstractAtom(int id, int typ,
                           double x, double y, double z)
  : _coords(x,y,z)
{
  _type = typ;
  _id = id;
}

AbstractAtom::AbstractAtom(int id, int typ, Vect3& x)
  : _coords(x)
{
  _type = typ;
  _id = id;
}
