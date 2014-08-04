// Test HTML escaping.
// @since Sun Aug  3 20:16:34 EDT 2014
// @author Mark Bucciarelli <mkbucc@gmail.com>


#include "tap.h"

#include "../htmlescape.h"

void
simple()
{
	char		*result = 0;
		
	htmlescape("&", &result);

	is(result, "&amp;");

	free(result);
	
}


int
main (int argc, char *argv[])
{

	plan(1);

	simple();

	done_testing();
}
