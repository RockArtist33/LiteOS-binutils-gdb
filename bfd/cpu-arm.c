/* BFD support for the ARM processor
   Copyright 1994 Free Software Foundation, Inc.
   Contributed by Richard Earnshaw (rwe@pegasus.esprit.ec.org)

This file is part of BFD, the Binary File Descriptor library.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

#include "bfd.h"
#include "sysdep.h"
#include "libbfd.h"

/* This routine is provided two arch_infos and works out which ARM
   machine which would be compatible with both and returns a pointer
   to its info structure */

static const bfd_arch_info_type *
compatible (a,b)
     const bfd_arch_info_type * a;
     const bfd_arch_info_type * b;
{
  /* For now keep things real simple - insist on matching architecture types */
  
  return (a->arch != b->arch || a->mach != b->mach ) ? NULL : a ;
}

static struct
{
  enum bfd_architecture arch;
  char *                name;
}
processors[] =
{
  { bfd_mach_arm_2,  "arm2"     },
  { bfd_mach_arm_2a, "arm250"   },
  { bfd_mach_arm_2a, "arm3"     },
  { bfd_mach_arm_3,  "arm6"     },
  { bfd_mach_arm_3,  "arm60"    },
  { bfd_mach_arm_3,  "arm600"   },
  { bfd_mach_arm_3,  "arm610"   },
  { bfd_mach_arm_3,  "arm7"     },
  { bfd_mach_arm_3,  "arm710"   },
  { bfd_mach_arm_3,  "arm7500"  },
  { bfd_mach_arm_3,  "arm7d"    },
  { bfd_mach_arm_3,  "arm7di"   },
  { bfd_mach_arm_3M, "arm7dm"   },
  { bfd_mach_arm_3M, "arm7dmi"  },
  { bfd_mach_arm_4,  "arm8"     },
  { bfd_mach_arm_4,  "arm810"   },
  { bfd_mach_arm_4,  "sa1"      },
  { bfd_mach_arm_4T, "arm7tdmi" }
};

static boolean 
scan (info, string)
     const struct bfd_arch_info * info;
     const char * string;
{
  int  i;

  /* First test for an exact match */
  if (strcasecmp (string, info->printable_name) == 0)
    return true;

  /* Next check for a processor name instead of an Architecture name */
  for (i = sizeof (processors) / sizeof (processors[0]); i--;)
    {
      if (strcasecmp (string, processors[ i ].name) == 0)
	break;
    }

  if (i != -1 && info->arch == processors[ i ].arch)
    return true;

  /* Finally check for the default architecture */
  if (strcasecmp (string, "arm") == 0)
    return info->the_default;
  
  return false;
}


#define N(number, print, default, next)  \
{  32, 32, 8, bfd_arch_arm, number, "arm", print, 4, default, compatible, scan, next }

static const bfd_arch_info_type arch_info_struct[] =
{ 
  N( bfd_mach_arm_2,  "ARMv2",  false, & arch_info_struct[1] ),
  N( bfd_mach_arm_2a, "ARMv2a", false, & arch_info_struct[2] ),
  N( bfd_mach_arm_3,  "ARMv3",  false, & arch_info_struct[3] ),
  N( bfd_mach_arm_4,  "ARMv4",  false, & arch_info_struct[4] ),
  N( bfd_mach_arm_4T, "ARMv4T", false, NULL )
};

const bfd_arch_info_type bfd_arm_arch =
  N( bfd_mach_arm_3M, "ARMv3M", true, & arch_info_struct[0] );
