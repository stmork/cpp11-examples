/**
 * $Id$
 * $Revision$
 * $Date$
 * $Author$
 * @brief   Simple hash implementation.
 */

#include <stdio.h>
#include <stdlib.h>

#include <string>

int main()
{
   std::string text("Abbbcde");

   printf("%p\n", &text);
   printf("%s %p\n",  text.c_str(),  text.c_str());
   printf("%s %p\n",  text.data(),   text.data());
   printf("%s %p\n", &text.front(), &text.front());

   return EXIT_SUCCESS;
}