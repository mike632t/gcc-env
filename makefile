#
#	gcc-cat.make
#
#	Copyright (C) 2012  MEJT
#	
#  This  program is free software: you can redistribute it and/or modify  it
#  under  the  terms of the GNU General Public License as published  by  the
#  Free  Software  Foundation, either version 3 of the License, or (at  your
#  option) any later version.
#
#  This  program  is  distributed in the hope that it will  be  useful,  but
#  WITHOUT   ANY   WARRANTY;   without  even   the   implied   warranty   of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
#  Public License for more details.
#
#  You  should have received a copy of the GNU General Public License  along
#  with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#	Note - Shell commands must start with a tab character at the beginning
#  of each line NOT spaces..!
#	
#  09 Apr 12   0.1   - Initial version derived from gtk-sample-menu - MEJT
#  17 Aug 13   0.2   - Added make clean to delete any object files - MEJT
#
PROGRAM = gcc-env
SOURCE = $(PROGRAM).c
OBJECT = $(SOURCE:.c=.o)
FLAGS	= 
LIBS	= 
CC	= gcc
#
all: $(PROGRAM)
#
$(PROGRAM): $(OBJECT)
	@$(CC) $(OBJECT) -o $(PROGRAM) $(LIBS)
#
#	Doesn't attempt to be selective - just recompiles everything!
$(OBJECT): $(SOURCE)
	@$(CC) $(FLAGS) -c $(SOURCE)
#
# Clean up any object files.
.PHONY: clean
clean:
	@rm -f $(OBJECT)
#


