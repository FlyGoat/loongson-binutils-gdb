/* Simulator Floating-point support.
   Copyright (C) 1997 Free Software Foundation, Inc.
   Contributed by Cygnus Support.

This file is part of GDB, the GNU debugger.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */



#ifndef _SIM_FPU_C_
#define _SIM_FPU_C_

#include "sim-main.h"
#include "sim-fpu.h"

#include <math.h>


/* register <-> sim_fpu */

INLINE_SIM_FPU (sim_fpu)
sim_fpu_32to (unsigned32 s)
{
  sim_fpu ans;
  ans.val = *(float*) &s;
  return ans;
}


INLINE_SIM_FPU (sim_fpu)
sim_fpu_64to (unsigned64 s)
{
  sim_fpu ans;
  ans.val = *(double*) &s;
  return ans;
}


INLINE_SIM_FPU (unsigned32)
sim_fpu_to32 (sim_fpu l)
{
  float s = l.val;
  return *(unsigned32*) &s;
}


INLINE_SIM_FPU (unsigned64)
sim_fpu_to64 (sim_fpu s)
{
  return *(unsigned64*) &s.val;
}


/* Arithmetic ops */

INLINE_SIM_FPU (sim_fpu)
sim_fpu_add (sim_fpu l,
	     sim_fpu r)
{
  sim_fpu ans;
  ans.val = l.val + r.val;
  return ans;
}


INLINE_SIM_FPU (sim_fpu)
sim_fpu_sub (sim_fpu l,
	     sim_fpu r)
{
  sim_fpu ans;
  ans.val = l.val - r.val;
  return ans;
}


INLINE_SIM_FPU (sim_fpu)
sim_fpu_mul (sim_fpu l,
	     sim_fpu r)
{
  sim_fpu ans;
  ans.val = l.val * r.val;
  return ans;
}


INLINE_SIM_FPU (sim_fpu)
sim_fpu_div (sim_fpu l,
	     sim_fpu r)
{
  sim_fpu ans;
  ans.val = l.val / r.val;
  return ans;
}


INLINE_SIM_FPU (sim_fpu)
sim_fpu_inv (sim_fpu r)
{
  sim_fpu ans;
  ans.val = 1 / r.val;
  return ans;
}


INLINE_SIM_FPU (sim_fpu)
sim_fpu_sqrt (sim_fpu r)
{
  sim_fpu ans;
  ans.val = sqrt (r.val);
  return ans;
}


/* int/long -> sim_fpu */

INLINE_SIM_FPU (sim_fpu)
sim_fpu_i32to (signed32 s)
{
  sim_fpu ans;
  ans.val = s;
  return ans;
}


INLINE_SIM_FPU (sim_fpu)
sim_fpu_u32to (unsigned32 s)
{
  sim_fpu ans;
  ans.val = s;
  return ans;
}


INLINE_SIM_FPU (sim_fpu)
sim_fpu_i64to (signed64 s)
{
  sim_fpu ans;
  ans.val = s;
  return ans;
}


INLINE_SIM_FPU (sim_fpu)
sim_fpu_u64to (unsigned64 s)
{
  sim_fpu ans;
  ans.val = s;
  return ans;
}


/* sim_fpu -> host format */

INLINE_SIM_FPU (float)
sim_fpu_2f (sim_fpu f)
{
  return f.val;
}


INLINE_SIM_FPU (double)
sim_fpu_2d (sim_fpu s)
{
  return s.val;
}


#if 0
INLINE_SIM_FPU (sim_fpu)
sim_fpu_f2 (float f)
{
  sim_fpu ans;
  ans.val = f;
  return ans;
}
#endif


#if 0
INLINE_SIM_FPU (sim_fpu)
sim_fpu_d2 (double d)
{
  sim_fpu ans;
  ans.val = d;
  return ans;
}
#endif



/* General */

INLINE_SIM_FPU (int)
sim_fpu_is_nan (sim_fpu d)
{
  return 0; /* FIXME - detect NaN */
}


/* Compare operators */

INLINE_SIM_FPU (int)
sim_fpu_is_lt (sim_fpu l,
	       sim_fpu r)
{
  return (l.val < r.val);
}

INLINE_SIM_FPU (int)
sim_fpu_is_le (sim_fpu l,
	       sim_fpu r)
{
  return (l.val <= r.val);
}

INLINE_SIM_FPU (int)
sim_fpu_is_eq (sim_fpu l,
	       sim_fpu r)
{
  return (l.val == r.val);
}

INLINE_SIM_FPU (int)
sim_fpu_is_ne (sim_fpu l,
	       sim_fpu r)
{
  return (l.val != r.val);
}

INLINE_SIM_FPU (int)
sim_fpu_is_ge (sim_fpu l,
	       sim_fpu r)
{
  return (l.val >= r.val);
}

INLINE_SIM_FPU (int)
sim_fpu_is_gt (sim_fpu l,
	       sim_fpu r)
{
  return (l.val > r.val);
}

#endif
