// Copyright (C) 2016 Fioratto Raffaele

// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.

// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
// more details.

// You should have received a copy of the GNU General Public License along
// with this program.  If not, see <http://www.gnu.org/licenses/>.


#ifndef __GAS_ASSEMBLY_H__
#define __GAS_ASSEMBLY_H__

#define DEFINE_FUNCTION(name) \
    .global name; \
    .type name,@function; \
    name:
#define END_FUNCTION(name) \
    .size name, . - name;

#define GLUE2(a, b) a##b
#define GLUE(a, b) GLUE2(a, b)

#endif /* __GAS_ASSEMBLY_H__ */
