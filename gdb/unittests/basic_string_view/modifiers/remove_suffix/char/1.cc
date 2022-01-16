// { dg-options "-std=gnu++17" }

// Copyright (C) 2013-2022 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

namespace modifiers_remove_suffix {

static void
test01 ()
{
  using gdb::string_view;

  string_view str0{"olympus mons"};
  string_view::pointer p = str0.data();
  str0.remove_suffix(2);
  VERIFY( str0.data() == p);
  VERIFY( str0.length() == 10 );
  VERIFY( str0 == string_view{"olympus mo"} );
}

#ifndef GDB_STRING_VIEW
constexpr bool
test02()
{
  using std::string_view;

  string_view str0{"olympus mons"};
  string_view::pointer p = str0.data();
  str0.remove_suffix(2);
  if ( str0.data() != p)
    return false;
  if ( str0.length() != 10 )
    return false;
  if ( str0 != string_view{"olympus mo"} )
    return false;

  return true;
}
#endif

static int
main ()
{ 
  test01();
#ifndef GDB_STRING_VIEW
  static_assert( test02() );
#endif

  return 0;
}

} // namespace modifiers_remove_suffix
